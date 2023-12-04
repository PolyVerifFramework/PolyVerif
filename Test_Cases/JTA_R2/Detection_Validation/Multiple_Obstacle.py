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

'''sim.set_time_of_day(20.00, False)
print(sim.time_of_day)'''

spawns = sim.get_spawn()
def ego_breaking():
    for i in range(3):
        sim.run(2)
        for j in range(i):
            sim.run(2.5)
        c = lgsvl.VehicleControl()
        c.throttle = -0.5
        c.steering = 0.007
        ego.apply_control(c, True)
        sim.run(3.2)
        c = lgsvl.VehicleControl()
        c.breaking=0.5
        ego.apply_control(c, True)
        sim.run(0.4)
        c = lgsvl.VehicleControl()
        c.throttle = 0.3
        c.steering = -0.004
        ego.apply_control(c, True)
        sim.run(3)

    
# EGO
egoState = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

for i in range(7):
    ped_name=['SegwayKickScooterMaxG30LP','Johny']
    name_npc = ["Bicyclist",'SUV','Sedan']
    state = lgsvl.AgentState()
    pstate = lgsvl.AgentState()
    state.transform.position = spawns[0].position + (38 *(0.39+i) * forward) - (3.5 *i* right) 
    pstate.transform.position = spawns[0].position + (47 *(0.12+i) * forward) - (3.5 *i* right) 
    state.transform.rotation = spawns[0].rotation
    npc = sim.add_agent(random.choice(name_npc), lgsvl.AgentType.NPC, state)
    p = sim.add_agent(random.choice(ped_name), lgsvl.AgentType.PEDESTRIAN, pstate)
    sim.run(0.1)  
    npc.follow_closest_lane(True,7)
    p.walk_randomly(True)
# spawn EGO
egoState = lgsvl.AgentState()
egoState.transform = sim.get_spawn()[0]

forward = lgsvl.utils.transform_to_forward(egoState.transform) # Unit vector in the forward direction of the EGO
right = lgsvl.utils.transform_to_right(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 28 * forward  - 2 * right
egoState.velocity = 13 * forward -5*right
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, egoState)
# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

ego_breaking()
sim.run(5)