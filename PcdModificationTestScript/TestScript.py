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

forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])


# Lidar sensor callback for user control to modify Lidar data  
def UpdateLidarData(agent, kind, context):
    if kind == "mylidar":
       
       ##### Get the Lidar point cloud data in y["array"] 
       test = context["Points"]
       y = json.loads(test)
       print("json data: ", y["array"])

       ##### Now y["array"] has all the Lidar Point cloud data. 
       ##### print(y["array"])
       ##### Research user can use this point cloud data for adding his model etc. and update y["array"]
       ##### The Point cloud data in y["array"] will be updated below in the context in the Simulator.
       #####let me show you without modified so below is the code where teh point cloud daat is not modified


       #### Now I am trying to modified the lidar points with some random values 
       #y["array"] = [50] # this will set every value of the y to 50 its just random value
      ##### Update the Lidar point cloud data from y["array"] to Simulator context
       s = lgsvl.LidarContext()
       s.Points = y["array"] # updated value gain transferd to the lg simulator for publishing on ROS bridge
       a.apply_lidar_context(s)
    else:
       pass

#Register user callback with the simulator
a.on_custom(UpdateLidarData)

input("Press Enter to run : ")

sim.run()

