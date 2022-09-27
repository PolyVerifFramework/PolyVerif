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

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)


sim.set_time_of_day(18.00, False)
print(sim.time_of_day)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])



state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position +15* forward - 8 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 8 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

#sim.add_random_agents(lgsvl.AgentType.NPC)
#sim.add_random_agents(lgsvl.AgentType.PEDESTRIAN)
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])


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
for i in range(1 * 20):
    # Create peds in a block
    start = (
        spawns[0].position
        + (70 + (1.0 * (i // 6))) * forward
        - (3 + (1.0 * (i % 6))) * right
    )
    end = start + 10 * forward - 8 *right


    state = lgsvl.AgentState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    name = random.choice(names)

    # Send the waypoints and make the pedestrian loop over the waypoints
    p = sim.add_agent(name, lgsvl.AgentType.PEDESTRIAN, state)
    p.walk_randomly(True)

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
for i in range(1 * 20):
    # Create peds in a block
    start = (
        spawns[0].position
        + (90 + (1.0 * (i // 6))) * forward
        + (6 + (1.0 * (i % 6))) * right
    )
    end = start + 10 * forward - 8 *right


    state1 = lgsvl.AgentState()
    state1.transform.position = start
    state1.transform.rotation = spawns[0].rotation
    name = random.choice(names)

    # Send the waypoints and make the pedestrian loop over the waypoints
    p1 = sim.add_agent(name, lgsvl.AgentType.PEDESTRIAN, state1)
    p1.walk_randomly(True)

#random NPC
sim.add_random_agents(lgsvl.AgentType.NPC)

t0 = time.time()
sim.run(time_limit=15, time_scale=1)
