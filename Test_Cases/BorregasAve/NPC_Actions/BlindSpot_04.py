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
scene = "aae03d2a-b7ca-4a88-9e41-9035287a12cc"

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()

# EGO
egoState = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

'''# NPC
state = lgsvl.AgentState()
state.transform.position = spawns[0].position + 20 * forward - 1 * right 
state.transform.rotation = spawns[0].rotation
npc = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state)
npc.velocity = 15 * forward
npc.follow_closest_lane(True,25)'''

# spawn EGO
egoState = lgsvl.AgentState()
egoState.transform = sim.get_spawn()[0]

forward = lgsvl.utils.transform_to_forward(egoState.transform) # Unit vector in the forward direction of the EGO
right = lgsvl.utils.transform_to_right(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 40 * forward - 3 * right
egoState.velocity = 6 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842977"), lgsvl.AgentType.EGO, state)
'''
# NPC
npcstate = lgsvl.AgentState()
npcstate.transform.position = egoState.transform.position + 46.0 * forward -  19* right
npcstate.transform.rotation.y = spawns[0].rotation.y + 90
npc = sim.add_agent("BoxTruck", lgsvl.AgentType.NPC, npcstate)
npc.follow_closest_lane(True,3)
'''
# NPC
state = lgsvl.AgentState()
state.transform.position = egoState.transform.position - 20 * forward #+ 10 *right
state.transform.rotation.y = spawns[0].rotation.y + 270
npc1 = sim.add_agent("SchoolBus", lgsvl.AgentType.NPC, state)
npc1.follow_closest_lane(True,11)

sim.run(15)