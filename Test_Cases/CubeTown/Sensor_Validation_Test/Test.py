# -*- coding: utf-8 -*-
'''
Created on Tue Jun  1 18:43:47 2021

@author: Admin
'''
from math import cos, asin, sqrt, pi
from environs import Env
import lgsvl
import json

env = Env()
sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == "BorregasAve":
    sim.reset()
else:
    sim.load("BorregasAve")

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform.position = spawns[0].position - 5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 20 * forward

a=sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)
a.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
#sensor disable
# sensors = a.get_sensors()

# for d in sensors:
# 	print("sensor : ",d)
#     if isinstance(d, lgsvl.sensor.GpsSensor):
#         d.enabled = False

s=lgsvl.GPSContext()
displacement = 10 # in meters  
disp_mtr2mm = displacement * 1000 #  1meter = 1000mm

# #possibility-1
lat_disp  = disp_mtr2mm * (0.00000001/1.1132) #  0.00000001  = 1.1132mm
long_disp = 0.0

# # new_Lat  = Lat + lat_disp
# # new_Long = Long + long_disp
# #print("  ",new_Long,new_Lat)

s.Latitude = lat_disp
s.Longitude = long_disp
a.apply_gps_context(s)
print("  ",lat_disp)
input("enter to start : ")
sim.run()
# dist = distance(Lat, Long, new_Lat, new_Long)
# print(dist*1000)
