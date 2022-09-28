# -*- coding: utf-8 -*-
'''
Created on Tue Jun  1 18:43:47 2021

@author: Admin
'''
from math import cos, asin, sqrt, pi
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

print("This test case will allow user to modify and add noise/error to the generated IMU Data")
sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform.position = spawns[0].position - 5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 20 * forward

a=sim.add_agent(env.str("LGSVL__VEHICLE_0", "AVPCar"), lgsvl.AgentType.EGO, state)
a.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

# def distance(lat1, lon1, lat2, lon2):
#     p = pi/180
#     a = 0.5 - cos((lat2-lat1)*p)/2 + cos(lat1*p) * cos(lat2*p) * (1-cos((lon2-lon1)*p))/2
#     return 12742 * asin(sqrt(a)) #2*R*asin...
s=lgsvl.IMUContext()
s.Percentage = 5
a.apply_imu_context(s)
print(s.Percentage)
sim.run()
# sim.run(time_limit=30)

# dist = distance(Lat, Long, new_Lat, new_Long)
# print(dist*1000)