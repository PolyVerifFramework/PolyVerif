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

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene = "JTA_R1"
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


print("adding pedestrian's")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)
print("Test")
#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)

sim.set_time_of_day(18.00, False)
print(sim.time_of_day)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 25 * forward + 0 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 14  * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)


# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

# spawn PED
pedState = lgsvl.AgentState()
pedState.transform.position = spawns[0].position + 55 * forward - 5 * right
ped = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, pedState)
print(spawns[0].position + 55 * forward + 5 * right)
#Vector(7.510133101372058, 1.506469030736279, 24.38467988560467)
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
waypoints.append(lgsvl.WalkWaypoint(position=pedState.position,speed = 20, idle=0, trigger_distance=70))
# Second waypoint is across the crosswalk
waypoints.append(lgsvl.WalkWaypoint(position=lgsvl.Vector(7.510133101372058, 1.506469030736279, 24.38467988560467), idle=0))
#Vector(21.944195246164846, 1.7022884871983026, 11.711104828000328)
# List of waypoints is given to the pedestrian
ped.follow(waypoints,loop = True)

sim.run(12)