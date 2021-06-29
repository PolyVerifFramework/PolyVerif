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
    class LidarContext : ICommand
    {
        public string Name => "sensor/apply_lidar_context";
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

                    if (sensor is LidarSensor lidar){
                        var lidarData = args["lidarData"];
                        // JSONArray Points = lidarData["Points"].AsArray;
                        // lidar.ApplyContext(Points);

                        int ErrorNoise = lidarData["ErrorNoise"];
                        lidar.ApplyNoiseError(ErrorNoise);
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