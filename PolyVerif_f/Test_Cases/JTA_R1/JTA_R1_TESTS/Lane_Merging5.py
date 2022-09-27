#!/usr/bin/env python3
#
# Copyright (c) 2019-2020 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

from distutils.spawn import spawn
from environs import Env
import lgsvl
import time
import random
import sys
import os

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
env = Env()
scene = "JTA_R1"
file = open('pid','w+')
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

#if sys.argv[1]: 
   #rain = float(sys.argv[1])
   #fog = float(sys.argv[2])
   #wetness = float(sys.argv[3])
   #cloudiness = float(sys.argv[4])
   #damage = float(sys.argv[5])
   #scene = sys.argv[6]

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)


sim.set_time_of_day(18.00, False)
print(sim.time_of_day)

spawns = sim.get_spawn()
#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)
# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

# NPC
state = lgsvl.AgentState()
state.transform.position = spawns[0].position + 20 * forward + 1.8 * right 
state.transform.rotation = spawns[0].rotation
npc = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state)
npc.velocity = 15 * forward
npc.follow_closest_lane(True,25)
#EGO
state.transform = spawns[0]
state.transform.position = spawns[0].position + 30 * forward# - 2 * right
state.velocity = 11 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

npc.follow_closest_lane(True,20)
sim.run(3)

c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(1)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(1)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
#sim.run(15)