/**
 * Copyright (c) 2018-2020 LG Electronics, Inc.
 *
 * This software contains code licensed as described in LICENSE.
 *
 */

using Simulator.Bridge;
using Simulator.Bridge.Data;
using Simulator.Map;
using Simulator.Utilities;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;
using Simulator.Sensors.UI;

namespace Simulator.Sensors
{
    [SensorType("GPS Device", new[] { typeof(GpsData) })]
    public class GpsSensor : SensorBase
    {
        [SensorParameter]
        [Range(1f, 100f)]
        public float Frequency = 12.5f;

        [SensorParameter]
        public bool IgnoreMapOrigin = false;

        Queue<Tuple<double, Action>> MessageQueue =
            new Queue<Tuple<double, Action>>();

        bool Destroyed = false;
        bool IsFirstFixedUpdate = true;
        double LastTimestamp;

        float NextSend;
        uint SendSequence;
        float gpsval;
        public static bool flag_gps_api = true;
        public int gps_perc;
        public double gps_lat;
        public double gps_initial_lat;
        public double gps_lon;
        public double gps_alt;
        public double gps_initial_lon;
        public double gps_est;
        public double gps_nrth;
        BridgeInstance Bridge;
        Publisher<GpsData> Publish;

        MapOrigin MapOrigin;

        public override SensorDistributionType DistributionType => SensorDistributionType.LowLoad;

        private void Awake()
        {
            MapOrigin = MapOrigin.Find();
        }

        public void Start()
        {
            print("in start");
            flag_gps_api = true;
            Task.Run(Publisher);
        }

        void OnDestroy()
        {
            Destroyed = true;
        }

        public override void OnBridgeSetup(BridgeInstance bridge)
        {
            Bridge = bridge;
            Publish = Bridge.AddPublisher<GpsData>(Topic);
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

                Tuple<double, Action> msg = null;
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
                        msg.Item2();
                    }
                    catch (Exception ex)
                    {
                        UnityEngine.Debug.LogException(ex, this);
                    }
                    nextPublish = now + (long)(Stopwatch.Frequency / Frequency);
                    LastTimestamp = msg.Item1;
                }
            }
        }

        void FixedUpdate()
        {
            //print("Before connecting bridge");
            if (MapOrigin == null || Bridge == null || Bridge.Status != Status.Connected)
            {
                return;
            }
            //print("After connecting bridge");
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
            var location = MapOrigin.GetGpsLocation(transform.position, IgnoreMapOrigin);

            if(flag_gps_api == false){
                //print($"## initial lat = {location.Latitude}");
                location.Latitude = location.Latitude +  gps_lat;
                location.Longitude = location.Longitude + gps_lon;
                location.Altitude = location.Altitude + gps_alt;
                location.Northing = location.Northing + gps_est;
                location.Easting = location.Easting + gps_nrth;
            }
            
            var orientation = transform.rotation;
            orientation.Set(-orientation.z, orientation.x, -orientation.y, orientation.w); // converting to right handed xyz

            var data = new GpsData()
            {
                Name = Name,
                Frame = Frame,
                Time = SimulatorManager.Instance.CurrentTime,
                Sequence = SendSequence++,

                IgnoreMapOrigin = IgnoreMapOrigin,
                Latitude = location.Latitude,
                Longitude = location.Longitude,
                Altitude = location.Altitude,
                Northing = location.Northing,
                Easting = location.Easting,
                Orientation = orientation,
            };

            lock (MessageQueue)
            {
                MessageQueue.Enqueue(Tuple.Create(time, (Action)(() =>
                {
                    if (Bridge != null && Bridge.Status == Status.Connected)
                    {
                        //print($"## publish lat = {location.Latitude}");
                        Publish(data);
                    }
                })));
            }
        }

        void Update()
        {
            IsFirstFixedUpdate = true;
        }
//sneha

        public Api.Commands.GpsData GetData()
        {
            var location = MapOrigin.GetGpsLocation(transform.position);

            var data = new Api.Commands.GpsData
            {
                Latitude = location.Latitude,
                Longitude = location.Longitude,
                Easting = location.Easting,
                Northing = location.Northing,
                Altitude = location.Altitude,
                Orientation = -transform.rotation.eulerAngles.y
            };
            return data;
        }
        public void ApplyContext(double lat, double lon, double alt, double est, double nrth)
        {
            flag_gps_api = false;
            gps_lat = lat;
            gps_lon = lon;
            gps_alt = alt;
            gps_est = est;
            gps_nrth = nrth;
            print($"Apply_context : {gps_lat}");
        }

        public override void OnVisualize(Visualizer visualizer)
        {
            UnityEngine.Debug.Assert(visualizer != null);

            var location = MapOrigin.GetGpsLocation(transform.position, IgnoreMapOrigin);
            //print($"visual : {location.Latitude} ---- {gps_lat}");
            if(flag_gps_api == false){
                gps_initial_lat = location.Latitude;
                gps_initial_lon = location.Longitude;
                location.Latitude = location.Latitude + gps_lat ;
                location.Longitude = location.Longitude + gps_lon;
                location.Altitude = location.Altitude + gps_alt;
                location.Northing = location.Northing + gps_nrth;
                location.Easting = location.Easting + gps_est;
                //print($"lat visual : {location.Latitude}  initial : {tmp}");  
            }
            var orientation = transform.rotation;
            orientation.Set(-orientation.z, orientation.x, -orientation.y, orientation.w); // converting to right handed xyz

            var graphData = new Dictionary<string, object>()
            {
                {"Ignore MapOrigin", IgnoreMapOrigin},
                {"Initial Latitude", gps_initial_lat},
                {"Latitude", location.Latitude},
                {"Initial Longitude", location.Longitude},
                {"Longitude", location.Longitude},
                {"Altitude", location.Altitude},
                {"Northing", location.Northing},
                {"Easting", location.Easting},
                {"Orientation", orientation},
            };
            visualizer.UpdateGraphValues(graphData);
        }
        public override void OnVisualizeToggle(bool state)
        {
            //
        }
    }
}