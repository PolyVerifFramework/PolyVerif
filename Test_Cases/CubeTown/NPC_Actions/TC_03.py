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
import math
env = Env()

scene = "06773677-1ce3-492f-9fe2-b3147e126e27"

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
for s in spawns:
    print(s)
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])


state = lgsvl.AgentState()
state.transform = spawns[0]

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position +   10 * forward - 6 *right
state.transform.rotation = spawns[0].rotation
state.velocity = 19 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842977"), lgsvl.AgentType.EGO, state)

for i, name in enumerate(["SUV", "Jeep", "Hatchback"],1):
    state = lgsvl.AgentState()

    # Spawn NPC vehicles 10 meters ahead of the EGO
    state.transform.position = spawns[0].position + (10 * forward) + (3.0 * i * right)
    state.transform.rotation = spawns[0].rotation
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, state)
    npc.follow_closest_lane(True, 50)
sim.run(4)
#turn right
# VehicleControl objects can only be applied to EGO vehicles
# You can set the steering (-1 ... 1), throttle and braking (0 ... 1), handbrake and reverse (bool)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.3
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
'''#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)'''