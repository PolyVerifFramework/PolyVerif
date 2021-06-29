/**
 * Copyright (c) 2019 LG Electronics, Inc.
 *
 * This software contains code licensed as described in LICENSE.
 *
 */

using SimpleJSON;
using UnityEngine;
using Simulator.Sensors;
using System.Collections.Generic;
using System.Linq;

//Rahul
namespace Simulator.Api.Commands
{
    class IMUContext : ICommand
    {
        public string Name => "sensor/apply_imu_context";
        public void Execute(JSONNode args)
        {
            var uid = args["uid"].Value;
            var api = ApiManager.Instance;
            if (api.Agents.TryGetValue(uid, out GameObject obj))
            {
                 
                var sensors = obj.GetComponentsInChildren<SensorBase>(true).ToList();
            
                   for (int i = 0; i < sensors.Count; i++)
                   {
                     var sensor = sensors[i];
                      if (sensor is ImuSensor imu){
                        var imuval = args["ImuData"];
                        double span = imuval["MeasurementSpan"];
                        // Vector3 pos = imuval["Position"];
                        // Quaternion orient = imuval["Orientation"];
                        // Vector3 accel = imuval["Acceleration"];
                        // Vector3 linearvel = imuval["LinearVelocity"];
                        // JSONArray angvel = imuval["AngularVelocity"].AsArray;
                        float percentage_accel = imuval["Percentage_acccel"];
                        float percentage_angl = imuval["Percentage_angular_vel"];
                        float percentage_linear = imuval["Percentage_linear_vel"];                        
                        imu.ApplyContext(percentage_angl,percentage_linear,percentage_accel );
                      }
                }           
            }
            else
            {
                api.SendError(this, $"Agent '{uid}' not found");
            }
        }
    }
}