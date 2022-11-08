#!/usr/bin/env python3

from environs import Env
import lgsvl
import json

import random
import time
import sys
import os
from pathlib import Path
env = Env()
# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene = "BorregasAve"
home = str(Path.home())
file = open(home+'/pid','w');
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()
print("pid : ",pid)
if sys.argv[1]: 
   rain = float(sys.argv[1])
   fog = float(sys.argv[2])
   wetness = float(sys.argv[3])
   cloudiness = float(sys.argv[4])
   damage = float(sys.argv[5])
   scene = sys.argv[6]

env = Env()
print("This test case will allow user to modify and add noise/error to the generated lidar points")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()

state = lgsvl.AgentState()
state.transform = spawns[0]
a=sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)
a.connect_bridge(env.str("BRIDGE_HOST", "127.0.0.1"), 9090)

forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

#### Now trying to modified the lidar points with some random error % 
##### Update the Lidar point cloud data for x, y axis of the point cloud
s = lgsvl.LidarContext()
s.NoisePercentage = 50             # added the error percentage to the lidar points
#s.LidarDistance = 20                # Change the Lidar Max, Min Distance for the lidar points
a.apply_lidar_context(s)

sim.run()