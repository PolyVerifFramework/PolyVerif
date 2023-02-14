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

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene =scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map

file = open('pid','w+');
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

spawns = sim.get_spawn()

'''sim.set_time_of_day(18.00, False)
print(sim.time_of_day)'''

# EGO
egoState = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

egoState.transform = spawns[0]
egoState.transform.position = spawns[0].position + 30 * forward #+ 4.5 * right
egoState.velocity =13 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,egoState)

# spawn NPC
npcState = lgsvl.AgentState()
npcState.transform = egoState.transform
npcState.transform.position = spawns[0].position + 30 * forward -4 *right
print("npc",egoState.position + 20 * forward)# NPC is 20m ahead of the EGO
npc = sim.add_agent("Sedan", lgsvl.AgentType.NPC, npcState)
# spawn NPC
npc1State = lgsvl.AgentState()
npc1State.transform = npcState.transform
npc1State.transform.position = npcState.position + 10 * forward 
npc1 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, npc1State)
# spawn NPC
npc2State = lgsvl.AgentState()
npc2State.transform = egoState.transform
npc2State.transform.position = npcState.position + 20 * forward 
npc2 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, npc2State)

# spawn NPC
npc3State = lgsvl.AgentState()
npc3State.transform = egoState.transform
npc3State.transform.position = npcState.position - 10 * forward 
npc3 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, npc3State)

sim.run(2)


# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

def on_collision(agent1, agent2, contact):
    raise Exception("{} collided with {}".format(agent1, agent2))

ego.on_collision(on_collision)
npc.on_collision(on_collision)

npc3.follow_closest_lane(True,10)
npc2.follow_closest_lane(True,11)
npc1.follow_closest_lane(True,8)
npc.follow_closest_lane(True,14)

agents = []
def on_lane_change(agent):
    return True
    #agents.append(agent)
npc3.on_lane_change(on_lane_change)
sim.run(1)
npc3.change_lane(False)
sim.run(0.5)

c = lgsvl.VehicleControl()
c.throttle = -0.5
c.steering = 0.007
ego.apply_control(c, True)
sim.run(3.2)
c = lgsvl.VehicleControl()
c.breaking=0.5
ego.apply_control(c, True)
sim.run(0.5)
c = lgsvl.VehicleControl()
c.throttle = 0.2
c.steering = -0.002
ego.apply_control(c, True)
sim.run(10)
sim.run(5)