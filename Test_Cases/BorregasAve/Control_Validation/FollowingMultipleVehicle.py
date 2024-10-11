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
env = Env()


# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene = "aae03d2a-b7ca-4a88-9e41-9035287a12cc"


file = open('pid','w')
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

if sys.argv[1]: 
   rain = float(sys.argv[1])
   fog = float(sys.argv[2])
   wetness = float(sys.argv[3])
   cloudiness = float(sys.argv[4])
   damage = float(sys.argv[5])
   

print("Scenario with some NPC's")

SIMULATOR_HOST = env.str("LGSVL__SIMULATOR_HOST", 'localhost')
SIMULATOR_BRIDGE = env.str("LGSVL__SIMULATOR_BRIDGE", 'localhost')
SIMULATOR_BRIDGE_PORT = env.str("LGSVL__SIMULATOR_BRIDGE_PORT", '9090')

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
#state.transform.position = spawns[1].position + 40 * forward
#state.transform.rotation = spawns[1].rotation
state.transform.position = spawns[0].position - 2 * forward
state.transform.rotation = spawns[0].rotation
state.velocity = 12 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, state)

# An EGO will not connect to a bridge unless commanded to

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

print("Bridge connected:", ego.bridge_connected)

forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + 2 * right + 40 *forward
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 8 * forward
jeep = sim.add_agent("Jeep", lgsvl.AgentType.NPC, statej)

jeep.follow_closest_lane(True, 5.0)  # 11.1 m/s is ~40 km/h


statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + 30 * forward
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 8 * forward
sedan = sim.add_agent("Sedan", lgsvl.AgentType.NPC, statej)
sedan.follow_closest_lane(True, 12.0)  # 11.1 m/s is ~40 km/h

# statej = lgsvl.AgentState()
# statej.transform.position = spawns[0].position + 30 * forward
# statej.transform.rotation = spawns[0].rotation 
# statej.velocity = 2 * forward
# sedan1 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, statej)
# sedan1.follow_closest_lane(True, 10)  # 11.1 m/s is ~40 km/h

statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + (100 * forward) 
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 2 * forward
suv = sim.add_agent("SchoolBus", lgsvl.AgentType.NPC, statej)

suv.follow_closest_lane(True, 5.0)
statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + (80 * forward) 
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 5 * forward
suv1 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, statej)

suv1.follow_closest_lane(True, 5.0)

right = lgsvl.utils.transform_to_right(spawns[0])

#input("Press Enter to drive forward for 25 seconds (1x)")
t0 = time.time()
sim.run(time_limit=15, time_scale=1)
t1 = time.time()
