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

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
env = Env()
scene = "JTA_R1"
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


sim.set_time_of_day(22.00, False)
print(sim.time_of_day)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

for i in range(10 * 2):
    # Create controllables in a block
    start = (
        spawns[0].position
        + (100 + (1.0 * (i // 4))) * forward
        + ( 0 + (1.0 * (i % 4))) * right
    )
    end = start + 10 * forward
    state = lgsvl.ObjectState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    '''# Set velocity and angular_velocity
    state.velocity = 10 * up
    state.angular_velocity = 6.5 * right'''

    # add controllable
    o = sim.controllable_add("TrafficCone", state)


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
for i in range(1 * 10):
    # Create peds in a block
    start = (
        spawns[0].position
        + (110 + (2.0 * (i // 6))) * forward
        + (2 + (2.0 * (i % 6))) * right
    )
    end = start + 10 * forward - 8 *right

    # Give waypoints for the spawn location and 10m ahead
    wp = [lgsvl.WalkWaypoint(start, 0), lgsvl.WalkWaypoint(end, 0)]

    state = lgsvl.AgentState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    name = random.choice(names)

    # Send the waypoints and make the pedestrian loop over the waypoints
    p = sim.add_agent(name, lgsvl.AgentType.PEDESTRIAN, state)
    p.follow(wp,False)

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 7 * forward + 2 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 12 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

vehicles = {
    ego: "EGO",
    o: "TrafficCone",
}


# Executed upon receiving collision callback -- NPC is expected to drive through colliding objects
def on_collision(agent1, agent2, contact):
    name1 = vehicles[agent1] 
    name2 = vehicles[agent2] if agent2 is not None else "OBSTACLE"
    print("{} collided with {}".format(name1, name2))
    sys.exit()

ego.on_collision(on_collision)
#cone.on_collision(on_collision)


print("\nAdded {} Traffic Cones".format(i + 1))

sim.run(16)