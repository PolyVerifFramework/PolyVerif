#!/usr/bin/env python3
# Copyright (c) 2019-2020 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

from environs import Env
import lgsvl
import time
import random
import sys
import os
import math


env = Env()

# Taking arguments for weather parameters and scene
rain = 50
fog = 0
wetness = 0
cloudiness = 50
damage = 0
scene = scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map

file = open('pid','w+');
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

#if sys.argv[1]: 
   #rain = float(sys.argv[1])
   #fog = float(sys.argv[2])
   #wetness = float(sys.argv[1])
   #cloudiness = float(sys.argv[4])
   #damage = float(sys.argv[5])
   #scene = sys.argv[6]

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)
print("Test")
sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)
'''sim.set_time_of_day(17.00, False)
print(sim.time_of_day)'''

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
state1 = lgsvl.AgentState()
state1.transform.position = spawns[0].position + 40 * forward - 4.78 * right 
state1.transform.rotation = spawns[0].rotation
npc1 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, state1)

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 25 * forward #+ 3.5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 20  * forward - 1.9 *right

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
#sim.run(2)

pedState = lgsvl.AgentState()
pedState.transform.position = spawns[0].position + 160 * forward #+ 5.78 * right 
#pedState.transform.position = lgsvl.Vector(125.49626182889025, 7.5, 15.708560251031198)
ped = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, pedState)
'''print(spawns[0].position + 160 * forward + 8.78 * right)
print(spawns[0].position + 160 * forward -1.78 * right)
'''

stateobj = lgsvl.ObjectState()
stateobj.transform.position = lgsvl.Vector(85.38435275890069,6.5, 47.3093947490924)
print("obj ",spawns[0].position + 155 * forward) #+ 8.78 * right)
stateobj.transform.rotation = spawns[0].rotation
o = sim.controllable_add("ChargingStation", stateobj)

# Create the list of waypoints for the pedestrian to follow
waypoints = []
# Fist waypoint is the same position that the PED is spawned. The PED will wait here until the EGO is within 50m
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(83.24222597640421, 7, 47.274945202712505),speed = 35, idle=0, trigger_distance=55))
# Second waypoint is across the crosswalk
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(84.98068161741013, 7, 35.959955279678066), idle=0))
#waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(157.64, 9.0,0.21775358693382874), idle=0))

# List of waypoints is given to the pedestrian
ped.follow(waypoints)
#ped.walk_randomly(True)
sim.run(6.8)
c = lgsvl.VehicleControl()
c.throttle = -0.7
c.steering = -0.007
ego.apply_control(c, True)
sim.run(3.4)
c = lgsvl.VehicleControl()
c.breaking=1
ego.apply_control(c, True)
sim.run(3)
c = lgsvl.VehicleControl()
c.throttle = 0.2
#c.steering = -0.007
ego.apply_control(c, True)
sim.run(10)
'''
c2 = lgsvl.VehicleControl()
c2.steering = -0.01
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c2, True)'''
