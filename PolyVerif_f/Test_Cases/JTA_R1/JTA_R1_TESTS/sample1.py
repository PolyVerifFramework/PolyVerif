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
state.transform.position = spawns[0].position + 8.0 * forward
state.transform.rotation.y = spawns[0].rotation.y 
state.velocity = 8 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)


# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))


state = lgsvl.AgentState()
# Spawn the pedestrian in front of car
state.transform.position = spawns[0].position + 100 * forward
state.transform.rotation = spawns[0].rotation

p = sim.add_agent("Bob", lgsvl.AgentType.PEDESTRIAN, state)
# Pedestrian will walk to a random point on sidewalk
p.walk_randomly(True)


sim.run(15)