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
scene = "781b04c8-43b4-431e-af55-1ae2b2efc877"
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
'''sim.set_time_of_day(18.00, False)
print(sim.time_of_day)'''

# EGO
egoState = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

# spawn EGO
egoState = lgsvl.AgentState()
egoState.transform = sim.get_spawn()[0]
forward = lgsvl.utils.transform_to_forward(egoState.transform) # Unit vector in the forward direction of the EGO
right = lgsvl.utils.transform_to_right(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 25 * forward - 2 * right
egoState.velocity = 12 * forward -2.5 *right

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, egoState)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

for i in range(5):
    name_npc = ["Bicyclist","SUV"]
    state = lgsvl.AgentState()
    state.transform.position = spawns[0].position + (30 * i* forward) #+ 1 *i* right) 
    state.transform.rotation = spawns[0].rotation
    npc = sim.add_agent(random.choice(name_npc), lgsvl.AgentType.NPC, state)
    npc.follow_closest_lane(True,5)

# NPC
npcstate = lgsvl.AgentState()
npcstate.transform.position = egoState.transform.position + 69.0 * forward -  6.8* right
npcstate.transform.rotation.y = spawns[0].rotation.y +0
npc = sim.add_agent("BoxTruck", lgsvl.AgentType.NPC, npcstate)
npc.follow_closest_lane(True,3)
sim.run(6)

c = lgsvl.VehicleControl()
c.throttle = -0.5
c.steering = 0.007
ego.apply_control(c, True)
sim.run(3.2)
c = lgsvl.VehicleControl()
c.breaking=0.5
ego.apply_control(c, True)
sim.run(0.5)
npc.follow_closest_lane(True,7)
c = lgsvl.VehicleControl()
c.throttle = 0.1
c.steering = -0.007
ego.apply_control(c, True)
sim.run(1.5)
c = lgsvl.VehicleControl()
c.throttle = 0.1
c.steering = -0.007
ego.apply_control(c, True)
sim.run(13)