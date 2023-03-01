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
scene = "06773677-1ce3-492f-9fe2-b3147e126e27"

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
for s in spawns:
    print(s)
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])


state = lgsvl.AgentState()
state.transform = spawns[0]
'''
Pedstate = lgsvl.AgentState()
Pedstate.transform.position = lgsvl.Vector(3.8499956130981428, 0.0, 16.770004272460902)
Pedstate.transform.rotation = spawns[0].rotation
p = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, state)
# Pedestrian will walk to a random point on sidewalk
p.walk_randomly(True)

Pedstate = lgsvl.AgentState()
Pedstate.transform.position = lgsvl.Vector(3.84999561309814, 0.0, 38.7700042724609)
Pedstate.transform.rotation = spawns[0].rotation

p = sim.add_agent("Howard", lgsvl.AgentType.PEDESTRIAN, state)
# Pedestrian will walk to a random point on sidewalk
p.walk_randomly(True)'''

names = [
    "Bob",
    "EntrepreneurFemale",
    "Howard",
    "Johny",
    "Pamela",
    "Presley",
    "Robin",
    "Stephen",
    "Zoe",
]
for i in range(1 * 7):
    # Create peds in a block
    start = (
        spawns[0].position
        + (50 + (1.0 * (i // 6))) * forward
        - (10 + (1.0 * (i % 6))) * right
    )
    end = start + 10 * forward - 8 *right
    '''print("sp1 left side",spawns[0].position
        - (10 + (1.0 * (i // 6))) * forward
        - (5 + (1.0 * (i % 6))) * right)
    print("sp2 right side",spawns[0].position
        + (10 + (1.0 * (i // 6))) * forward
        - (5 + (1.0 * (i % 6))) * right)'''
    # Give waypoints for the spawn location and 10m ahead
    wp = [lgsvl.WalkWaypoint(start, 0), lgsvl.WalkWaypoint(end, 0)]

    state = lgsvl.AgentState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    name = random.choice(names)

    # Send the waypoints and make the pedestrian loop over the waypoints
    p = sim.add_agent(name, lgsvl.AgentType.PEDESTRIAN, state)
    p.follow(wp, True)
for i in range(1 * 4):
    # Create peds in a block
    start = (
        spawns[0].position
        - (10 + (1.0 * (i // 6))) * forward
        - (5 + (1.0 * (i % 6))) * right
    )
    end = start + 10 * forward - 8 *right
    '''print("sp1 left side",spawns[0].position
        - (10 + (1.0 * (i // 6))) * forward
        - (5 + (1.0 * (i % 6))) * right)
    print("sp2 right side",spawns[0].position
        + (10 + (1.0 * (i // 6))) * forward
        - (5 + (1.0 * (i % 6))) * right)'''
    # Give waypoints for the spawn location and 10m ahead
    wp = [lgsvl.WalkWaypoint(start, 0), lgsvl.WalkWaypoint(end, 0)]

    state = lgsvl.AgentState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    name = random.choice(names)

    # Send the waypoints and make the pedestrian loop over the waypoints
    p = sim.add_agent(name, lgsvl.AgentType.PEDESTRIAN, state)
    p.walk_randomly(True)
# Spawns one of each of the listed types of NPCS
# The first will be created in front of the EGO and then they will be created to the left
# The available types of NPCs can be found in NPCManager prefab
for i, name in enumerate(["SUV", "Jeep", "Hatchback"],1):
    state = lgsvl.AgentState()

    # Spawn NPC vehicles 10 meters ahead of the EGO
    state.transform.position = spawns[1].position + (10 * forward) + (3.0 * i * right)
    state.transform.rotation = spawns[1].rotation
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, state)
    npc.follow_closest_lane(True, 11.1)
sim.run(2)

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position +   10 * forward -2.8 *right
state.transform.rotation = spawns[0].rotation
state.velocity = 10 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842977"), lgsvl.AgentType.EGO, state)
sim.run(8)
#turn right
# VehicleControl objects can only be applied to EGO vehicles
# You can set the steering (-1 ... 1), throttle and braking (0 ... 1), handbrake and reverse (bool)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.44
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(4.4)
#turn right
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.37
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(3)
'''#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.4
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.4
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)'''
#straight
c = lgsvl.VehicleControl()
c.throttle = 0.1
c.steering = 0.01
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(11)
#turn right
# VehicleControl objects can only be applied to EGO vehicles
# You can set the steering (-1 ... 1), throttle and braking (0 ... 1), handbrake and reverse (bool)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.35
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
#c.breaking = 0.5
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(11)
#turn right
# VehicleControl objects can only be applied to EGO vehicles
# You can set the steering (-1 ... 1), throttle and braking (0 ... 1), handbrake and reverse (bool)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.37
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(3)
#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(18.6)
#turn right
# VehicleControl objects can only be applied to EGO vehicles
# You can set the steering (-1 ... 1), throttle and braking (0 ... 1), handbrake and reverse (bool)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.55
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(4)
#straight
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.01
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(8)