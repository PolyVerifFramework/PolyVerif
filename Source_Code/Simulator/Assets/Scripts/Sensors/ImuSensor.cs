/**
 * Copyright (c) 2019-2020 LG Electronics, Inc.
 *
 * This software contains code licensed as described in LICENSE.
 *
 */

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;
using SimpleJSON;
using Simulator.Bridge;
using Simulator.Bridge.Data;
using Simulator.Utilities;
using Simulator.Sensors.UI;

#pragma warning disable CS0649

namespace Simulator.Sensors
{
    [SensorType("IMU", new[] { typeof(ImuData) })]
    class ImuSensor : SensorBase
    {
        [SensorParameter]
        public string CorrectedTopic;

        [SensorParameter]
        public string CorrectedFrame;

        uint Sequence;
        Vector3 imu_ang_velocity;
        float imu_percentage_linear_vel;
        float imu_percentage_ang_vel;
        float imu_percentage_accel;
        public static bool imu_api_flag = false;

        BridgeInstance Bridge;
        Publisher<ImuData> Publish;
        Publisher<CorrectedImuData> CorrectedWriter;

        Queue<Tuple<double, float, Action>> MessageQueue =
            new Queue<Tuple<double, float, Action>>();
        bool Destroyed = false;
        bool IsFirstFixedUpdate = true;
        double LastTimestamp;

        Rigidbody RigidBody;
        Vector3 LastVelocity;

        ImuData data;
        
        public override SensorDistributionType DistributionType => SensorDistributionType.HighLoad;

        public override void OnBridgeSetup(BridgeInstance bridge)
        {
            Bridge = bridge;
            Publish = Bridge.AddPublisher<ImuData>(Topic);
            if (!string.IsNullOrEmpty(CorrectedTopic))
            {
                CorrectedWriter = Bridge.AddPublisher<CorrectedImuData>(CorrectedTopic);
            }
        }

        void Start()
        {
            imu_api_flag = false;
            RigidBody = GetComponentInParent<Rigidbody>();
            Task.Run(Publisher);
        }

        void OnDestroy()
        {
            Destroyed = true;
        }
        public void ApplyContext(float ang_vel,float linear_vel,float accel)
        {
            imu_api_flag = true;          
            imu_percentage_ang_vel = ang_vel;
            imu_percentage_linear_vel = linear_vel;
            imu_percentage_accel = accel;
            print($"Apply context : {imu_percentage_ang_vel}");
        }

        void Publisher()
        {
            var nextPublish = Stopwatch.GetTimestamp();

            while (!Destroyed)
            {
                long now = Stopwatch.GetTimestamp();
                if (now < nextPublish)
                {
                    Thread.Sleep(0);
                    continue;
                }

                Tuple<double, float, Action> msg = null;
                lock (MessageQueue)
                {
                    if (MessageQueue.Count > 0)
                    {
                        msg = MessageQueue.Dequeue();
                    }
                }

                if (msg != null)
                {
                    try
                    {
                        msg.Item3();
                    }
                    catch (Exception ex)
                    {
                        UnityEngine.Debug.LogException(ex, this);
                    }
                    nextPublish = now + (long)(Stopwatch.Frequency * msg.Item2);
                    LastTimestamp = msg.Item1;
                }
            }
        }

        void FixedUpdate()
        {
            if (IsFirstFixedUpdate)
            {
                lock (MessageQueue)
                {
                    MessageQueue.Clear();
                }
                IsFirstFixedUpdate = false;
            }

            var time = SimulatorManager.Instance.CurrentTime;
            if (time < LastTimestamp)
            {
                return;
            }

            var position = transform.position;
            position.Set(position.z, -position.x, position.y);
            var velocity = transform.InverseTransformDirection(RigidBody.velocity);
            velocity.Set(velocity.z, -velocity.x, velocity.y);
            var acceleration = (velocity - LastVelocity) / Time.fixedDeltaTime;
            LastVelocity = velocity;

            var localGravity = transform.InverseTransformDirection(Physics.gravity);
            acceleration -= new Vector3(localGravity.z, -localGravity.x, localGravity.y);

            var angularVelocity = RigidBody.angularVelocity;
            angularVelocity.Set(-angularVelocity.z, angularVelocity.x, -angularVelocity.y); // converting to right handed xyz
           //sneha
            if(imu_api_flag == true){
                //print($"##Initial imu angular vel : {angularVelocity.x}");
                imu_ang_velocity.x = angularVelocity.x;
                imu_ang_velocity.y = angularVelocity.y;
                imu_ang_velocity.z = angularVelocity.z;
                velocity.x = velocity.x + velocity.x * (imu_percentage_linear_vel/100);
                velocity.y = velocity.y + velocity.y * (imu_percentage_linear_vel/100);
                velocity.z = velocity.z + velocity.z * (imu_percentage_linear_vel/100);
                angularVelocity.x = angularVelocity.x + angularVelocity.x * (imu_percentage_ang_vel/100);
                angularVelocity.y = angularVelocity.y + angularVelocity.y * (imu_percentage_ang_vel/100);
                angularVelocity.z = angularVelocity.z + angularVelocity.z * (imu_percentage_ang_vel/100);
                acceleration.x = acceleration.x + acceleration.x * (imu_percentage_accel/100);
                acceleration.y = acceleration.y + acceleration.y * (imu_percentage_accel/100);
                acceleration.z = acceleration.z + acceleration.z * (imu_percentage_accel/100);
                //print($"## imu angular vel : {angularVelocity.x}");
            }
            var orientation = transform.rotation;
            orientation.Set(-orientation.z, orientation.x, -orientation.y, orientation.w); // converting to right handed xyz

            data = new ImuData()
            {
                Name = Name,
                Frame = Frame,
                Time = time,
                Sequence = Sequence,

                MeasurementSpan = Time.fixedDeltaTime,

                Position = position,
                Orientation = orientation,

                Acceleration = acceleration,
                LinearVelocity = velocity,
                AngularVelocity = angularVelocity,
            };

            var correctedData = new CorrectedImuData()
            {
                Name = Name,
                Frame = CorrectedFrame,
                Time = time,
                Sequence = Sequence,

                MeasurementSpan = Time.fixedDeltaTime,

                Position = position,
                Orientation = orientation,

                Acceleration = acceleration,
                LinearVelocity = velocity,
                AngularVelocity = angularVelocity,
            };

            if (Bridge == null || Bridge.Status != Status.Connected)
            {
                return;
            }

            lock (MessageQueue)
            {
                MessageQueue.Enqueue(Tuple.Create(time, Time.fixedDeltaTime, (Action)(() =>
                {
                    if (Bridge != null && Bridge.Status == Status.Connected)
                    {   
                        Publish(data);
                        CorrectedWriter?.Invoke(correctedData);
                    }
                })));
            }

            Sequence++;
        }


        void Update()
        {
            IsFirstFixedUpdate = true;
        }

        public override void OnVisualize(Visualizer visualizer)
        {
            UnityEngine.Debug.Assert(visualizer != null);

            if (data == null)
            {
                return;
            }
            print($"visual Avelocity = {data.AngularVelocity.x}");                        
            var graphData = new Dictionary<string, object>()
            {
                {"Measurement Span", data.MeasurementSpan},
                {"Position", data.Position},
                {"Orientation", data.Orientation},
                {"Acceleration", data.Acceleration},
                {"Linear Velocity", data.LinearVelocity},
                {"initial Angular Velocity.x", imu_ang_velocity.x},
                {"Angular Velocity.x", data.AngularVelocity.x},
                {"Angular Velocity", data.AngularVelocity}
            };
            visualizer.UpdateGraphValues(graphData);
        }

        public override void OnVisualizeToggle(bool state)
        {
            //
        }
    }
}
