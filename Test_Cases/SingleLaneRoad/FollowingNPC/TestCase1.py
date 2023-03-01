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
env = Env()
scene = "a6e2d149-6a18-4b83-9029-4411d7b2e69a"

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()

# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

# NPC
state = lgsvl.AgentState()
state.transform.position = spawns[0].position + 20 * forward - 1 * right 
state.transform.rotation = spawns[0].rotation
npc = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state)
npc.velocity = 15 * forward
npc.follow_closest_lane(True,25)

state.transform = spawns[0]
state.transform.position = spawns[0].position + 30 * forward - 2 * right
state.velocity = 10 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)

# NPC
state = lgsvl.AgentState()
state.transform.position = spawns[0].position - 5 * forward - 3 * right 
state.transform.rotation = spawns[0].rotation
npc = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state)
npc.follow_closest_lane(True,20)
'''sim.run(4)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.18
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)'''
sim.run(15)