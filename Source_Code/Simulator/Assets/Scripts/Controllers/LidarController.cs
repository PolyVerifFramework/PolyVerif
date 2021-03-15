/**
 * Copyright (c) 2019-2020 LG Electronics, Inc.
 *
 * This software contains code licensed as described in LICENSE.
 *
 */

using UnityEngine;
using System.Collections.Generic;
using Simulator;
using Simulator.Api;
using System.Linq;
using Simulator.Sensors;

public class LidarController : LidarSensor
{
    // api
    public void ApplyControl(float acceleration)
    {
        Debug.Log($"Inside Lidar  Controller : {acceleration}");
        test_variable = acceleration;
    }

}
