#!/usr/bin/env python3
#
# Copyright (c) 2019-2021 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

# See VF_C_25_Slow for a commented script

import time
import logging
from environs import Env
import lgsvl
import random

env = Env()
# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene = "JTA_R1"

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
print("Test")

spawns = sim.get_spawn()
for spawn in sim.get_spawn():
    print(spawn)
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

sim.set_time_of_day(18.00, False)
print(sim.time_of_day)

state = lgsvl.AgentState()
state.transform = spawns[0]
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
state.transform.position = spawns[0].position + 55 * forward - 1.5 *right
state.transform.rotation = spawns[0].rotation
state.velocity = 12 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
#random npc's
sim.add_random_agents(lgsvl.AgentType.NPC) 

#input("Press Enter to set normal time to 10:30")
# Normal time moves forward (at an accelerated rate). Pass False to set_time_of_day for this to happen
# spawn PED
pedState = lgsvl.AgentState()
pedState.transform.position = spawns[0].position + 30 * forward + 4 * right
ped = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, pedState)
ped.walk_randomly(True)

sim.add_random_agents(lgsvl.AgentType.NPC)

sim.run(13)
