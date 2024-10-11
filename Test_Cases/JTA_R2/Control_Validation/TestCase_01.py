#!/usr/bin/env python3
# Copyright (c) 2019-2020 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

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
   #wetness = float(sys.argv[1])
   #cloudiness = float(sys.argv[4])
   #damage = float(sys.argv[5])
   #scene = sys.argv[6]


print("adding pedestrian's")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)
print("Test")
#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)
'''
sim.set_time_of_day(18.00, False)
print(sim.time_of_day)'''

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 25 * forward# + 3.5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 11  * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)


# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
'''
state1 = lgsvl.AgentState()
state1.transform.position = spawns[0].position + 40 * forward - 4.78 * right 
state1.transform.rotation = spawns[0].rotation
npc1 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, state1)
'''
state2 = lgsvl.AgentState()
state2.transform.position = spawns[0].position + 25 * forward + 2.8 * right 
state2.transform.rotation = spawns[0].rotation
npc2 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state2)

state3 = lgsvl.AgentState()
state3.transform.position = state2.transform.position + 20 * forward - 4.78 * right 
state3.transform.rotation = spawns[0].rotation
npc3 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state3)

pedState = lgsvl.AgentState()
pedState.transform.position = spawns[0].position + 85 * forward - 4 * right
ped = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, pedState)
print(spawns[0].position + 85 * forward - 4 * right)
print(spawns[0].position + 85 * forward + 3 * right)

# Create the list of waypoints for the pedestrian to follow
waypoints = []
# Fist waypoint is the same position that the PED is spawned. The PED will wait here until the EGO is within 50m
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(157.640178507605, 6.8, 0.21775358693382874),speed = 25, idle=0, trigger_distance=70))
# Second waypoint is across the crosswalk
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(159.3713254093677, 6.8, 5.055341604096809), idle=0))
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(157.640178507605, 6.8,0.21775358693382874), idle=0))

# List of waypoints is given to the pedestrian
ped.follow(waypoints)

state4 = lgsvl.AgentState()
state4.transform.position = spawns[0].position + 37 * forward - 0 * right 
state4.transform.rotation = spawns[0].rotation
npc4 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state4)
a = {
    ego: "EGO",
    ped: "Bob",
}


#Executed upon receiving collision callback -- NPC is expected to drive through colliding objects
def on_collision(agent1, agent2, contact):
    name1 = a[agent1]
    name2 = a[agent2] if agent2 is not None else "OBSTACLE"
    # print("{} collided with {}".format(name1, name2))
    #sys.exit()


ego.on_collision(on_collision)
ped.on_collision(on_collision)

#npc1.follow_closest_lane(True,8)
npc2.follow_closest_lane(True,15)
npc3.follow_closest_lane(True,12)
npc4.follow_closest_lane(True,10)
sim.run(7)
c = lgsvl.agent.NPCControl()
c.e_stop = True
npc4.apply_control(c)
sim.run(2)
npc2.change_lane(True)
sim.run(1)
npc4.follow_closest_lane(True,4)
npc2.follow_closest_lane(True,4)
sim.run(11)

