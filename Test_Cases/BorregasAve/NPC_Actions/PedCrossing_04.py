#!/usr/bin/env python3
#
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
scene = "aae03d2a-b7ca-4a88-9e41-9035287a12cc"
rain = 80
fog = 50
wetness = 0
cloudiness = 0
damage = 10

print("adding pedestrian's")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)
print("Test")
sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 15 * forward
state.transform.rotation = spawns[0].rotation
state.velocity = 4  * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842977"), lgsvl.AgentType.EGO, state)

# spawn PED
pedState = lgsvl.AgentState()
pedState.transform.position = spawns[0].position + 45 * forward + 4 * right
ped = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, pedState)

a = {
    ego: "EGO",
    ped: "Bob",
}


# Executed upon receiving collision callback -- NPC is expected to drive through colliding objects
def on_collision(agent1, agent2, contact):
    name1 = a[agent1]
    name2 = a[agent2] if agent2 is not None else "OBSTACLE"
    print("{} collided with {}".format(name1, name2))
    sys.exit()


ego.on_collision(on_collision)
ped.on_collision(on_collision)

# Create the list of waypoints for the pedestrian to follow
waypoints = []
# Fist waypoint is the same position that the PED is spawned. The PED will wait here until the EGO is within 50m
waypoints.append(lgsvl.WalkWaypoint(position=pedState.position, idle=0, trigger_distance=70,speed = 30))
# Second waypoint is across the crosswalk
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(30.73078708637528, -1.03600001335144, -36.234978924813724), idle=0))

# List of waypoints is given to the pedestrian
ped.follow(waypoints,loop = True)

sim.run(15)