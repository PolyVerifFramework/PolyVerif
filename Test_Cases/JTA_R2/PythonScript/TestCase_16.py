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
scene =scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map

file = open('pid','w+')
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
'''sim.set_time_of_day(2.00, False)
print(sim.time_of_day)'''

# EGO
egoState = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])
# NPC
state3 = lgsvl.AgentState()
state3.transform.position = spawns[0].position + 400 * forward -21 * right 
state3.transform.rotation.y = spawns[0].rotation.y + 180
npc3 = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state3)
npc3.velocity = 19 * forward
npc3.follow_closest_lane(True,25)
# spawn EGO
egoState = lgsvl.AgentState()
egoState.transform = sim.get_spawn()[0]
forward = lgsvl.utils.transform_to_forward(egoState.transform) # Unit vector in the forward direction of the EGO
right = lgsvl.utils.transform_to_right(egoState.transform) 
up =lgsvl.utils.transform_to_up(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 340 * forward -28 * right
egoState.transform.rotation.y = spawns[0].rotation.y + 310
egoState.velocity = 12 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,egoState)

c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(5)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.11
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(4)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.2
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

sim.run(15)