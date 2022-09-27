#!/usr/bin/env python3
#
# Copyright (c) 2019-2020 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

from environs import Env
import lgsvl
import json

env = Env()
sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == "CubeTown":
    sim.reset()
else:
    sim.load("CubeTown")

spawns = sim.get_spawn()

state = lgsvl.AgentState()
state.transform = spawns[0]
a=sim.add_agent(env.str("LGSVL__VEHICLE_0", "TestROS2Vehicle"), lgsvl.AgentType.EGO, state)
a.connect_bridge(env.str("BRIDGE_HOST", "127.0.0.1"), 9090)

#JaguarRos2
#JaguarRosCustomSensor
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])


# Lidar sensor callback for user control to modify Lidar data  
def UpdateLidarData(agent, kind, context):
    if kind == "mylidar":
       test = context["Points"]
       y = json.loads(test)
       #print("json data: ", y["array"])

       #modify y["array"] have all the lidar point cloud data
       s = lgsvl.LidarContext()
       s.Points = y["array"]
       a.apply_lidar_context(s)
    else:
       pass


a.on_custom(UpdateLidarData)

input("Press Enter to run : ")

sim.run()

