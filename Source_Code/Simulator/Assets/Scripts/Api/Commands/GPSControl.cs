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
    class GPSContext : ICommand
    {
        public string Name => "sensor/apply_gps_context";
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
                      if (sensor is GpsSensor gps){
                        var gpsval = args["gpsData"];
                        double lat = gpsval["Latitude"];
                        double lon = gpsval["Longitude"];
                        double alt = gpsval["Altitude"];
                        double est = gpsval["Easting"];
                        double nrth = gpsval["Northing"];
                        gps.ApplyContext(lat,lon,alt,est,nrth);
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