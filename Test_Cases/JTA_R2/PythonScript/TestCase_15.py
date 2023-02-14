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
scene = scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map

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
sim.run(2)


# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# spawn NPC
npcState = lgsvl.AgentState()
npcState.transform = egoState.transform
npcState.transform.position = lgsvl.Vector(206.8834391523562, 9.0, -9.70887766413405) 
print("npc",egoState.position + 20 * forward)# NPC is 20m ahead of the EGO
npc = sim.add_agent("Sedan", lgsvl.AgentType.NPC, npcState)
# spawn PED
pedState = lgsvl.AgentState()
pedState.transform.position = spawns[0].position + 107 * forward - 2.8 * right
ped = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, pedState)
print(spawns[0].position + 120 * forward + 9 * right)
# This function will be called if a collision occurs
def on_collision(agent1, agent2, contact):
    raise Exception("{} collided with {}".format(agent1, agent2))

ego.on_collision(on_collision)
npc.on_collision(on_collision)

for i in range(1*8):
  # Create controllables in a block
  start = spawns[0].position + (80 + (0.5 * (i//8))) * forward  + (5 + (0.5 * (i % 8))) * right
  
  #print("cone", spawns[0].position + (50 + (1.0 * (i//10))) * forward  + (0 + (2.0 * (i % 10))) * right)
  state = lgsvl.ObjectState()
  state.transform.position = start
  state.transform.rotation = spawns[0]
  # add controllable
  cone = sim.controllable_add("TrafficCone", state)


# Create the list of waypoints for the pedestrian to follow
waypoints = []
# Fist waypoint is the same position that the PED is spawned. The PED will wait here until the EGO is within 50m
waypoints.append(lgsvl.WalkWaypoint(position=pedState.transform.position,speed = 2, idle=0, trigger_distance=30))
# Second waypoint is across the crosswalk
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(91.59509715110754, 7.5, 24.781674645203097), idle=0))
#Vector(21.944195246164846, 1.7022884871983026, 11.711104828000328)
# List of waypoints is given to the pedestrian
ped.follow(waypoints,loop = True)

npc.follow_closest_lane(True,14)
sim.run(5.5)
c = lgsvl.agent.NPCControl()
c.e_stop = True
npc.apply_control(c)
sim.run(5)

c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.07
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
c = lgsvl.VehicleControl()
c.throttle = 0.2
c.steering = -0.07
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
#sim.run(2)