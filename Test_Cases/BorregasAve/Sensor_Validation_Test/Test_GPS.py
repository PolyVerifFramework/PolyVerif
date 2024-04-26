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

print("This test case will allow user to modify and add noise/error to the generated GPS Data")
sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)


spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform.position = spawns[0].position + 1 * right
state.transform.rotation = spawns[0].rotation - 10
# state.transform.position = spawns[0].position - 5 * right
# state.transform.rotation = spawns[0].rotation
# state.velocity = 20 * forward

a=sim.add_agent(env.str("LGSVL__VEHICLE_0", "AVPCar"), lgsvl.AgentType.EGO, state)
a.connect_bridge(env.str("BRIDGE_HOST", "127.0.0.1"), 9090)

# def distance(lat1, lon1, lat2, lon2):
#     p = pi/180
#     a = 0.5 - cos((lat2-lat1)*p)/2 + cos(lat1*p) * cos(lat2*p) * (1-cos((lon2-lon1)*p))/2
#     return 12742 * asin(sqrt(a)) #2*R*asin...

Lat  =  28.5234571 
Long =  80.6830941
s=lgsvl.GPSContext()
# s.Latitude = Lat
# s.Longitude = Long
#a.apply_gps_context(s)
displacement = .50 # in meters  
disp_mtr2mm = displacement * 1000 #  1meter = 1000mm

# #possibility-1
lat_disp  = disp_mtr2mm + (0.00000001/1.1132) #  0.00000001  = 1.1132mm
long_disp = 0.0

#possibility-2
# lat_disp  = 0.0
# long_disp = disp_mtr2mm * (0.00000001/1.1132) #  0.00000001  = 1.1132mm

# #possibility-3
# lat_disp  = disp_mtr2mm * (0.00000001/1.1132) #  0.00000001  = 1.1132mm
# long_disp = disp_mtr2mm * (0.00000001/1.1132) #  0.00000001  = 1.1132mm

# new_Lat  = Lat + lat_disp
# new_Long = Long + long_disp
print("lat_disp :  ",lat_disp)

s.Latitude = lat_disp
s.Longitude = long_disp
a.apply_gps_context(s)

print("  ",lat_disp)
sim.run()
# dist = distance(Lat, Long, new_Lat, new_Long)
# print(dist*1000)