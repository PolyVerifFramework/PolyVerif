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

scene = "06773677-1ce3-492f-9fe2-b3147e126e27"

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])


state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position - 1 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 9 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842977"), lgsvl.AgentType.EGO, state)



sim.add_random_agents(lgsvl.AgentType.PEDESTRIAN)


state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

# 10 meters ahead, on left lane
state.transform.position = spawns[0].position + 20.0 * forward - 5.0 *right 
state.transform.rotation = spawns[0].rotation
print("npcvector",spawns[0].position + 21.0 * forward - 6.0 *right )
npc1 = sim.add_agent("BoxTruck", lgsvl.AgentType.NPC, state)

state = lgsvl.AgentState()

# 10 meters ahead, on right lane
state.transform.position = spawns[0].position + 4.0 * right + 20.0 * forward
state.transform.rotation = spawns[0].rotation

npc2 = sim.add_agent("SUV", lgsvl.AgentType.NPC, state, lgsvl.Vector(1, 1, 0))

# If the passed bool is False, then the NPC will not moved
# The float passed is the maximum speed the NPC will drive
# 11.1 m/s is ~40 km/h
#npc1.follow_closest_lane(True, 11.1)
# 5.6 m/s is ~20 km/h
npc2.follow_closest_lane(True, 5.6)


#print("Python API Quickstart #28: How to Add/Control Traffic Cone")



state = lgsvl.ObjectState()
state.transform.position = spawns[0].position + 24 * forward + 8 * right 
state.transform.rotation = spawns[0].rotation
# Set velocity and angular_velocity
#state.velocity = 50 * up 
#state.angular_velocity = 6.5 * right 

# add controllable
o = sim.controllable_add("ChargingStation", state)

t0 = time.time()
sim.run(time_limit=10, time_scale=1)
