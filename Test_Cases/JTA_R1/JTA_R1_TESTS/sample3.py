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
scene = "JTA_R1"
file = open('pid','w');
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

'''if sys.argv[1]: 
   rain = float(sys.argv[1])
   fog = float(sys.argv[2])
   wetness = float(sys.argv[3])
   cloudiness = float(sys.argv[4])
   damage = float(sys.argv[5])
   scene = sys.argv[6]
'''
print("Scenario with some NPC's")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

sim.set_time_of_day(18.00, False)
print(sim.time_of_day)
#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
#state.transform.position = spawns[1].position + 40 * forward
#state.transform.rotation = spawns[1].rotation
state.transform.position = spawns[0].position + 1.8 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 15 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))


forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position - 5 * right + 40 *forward
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 10 * forward
jeep = sim.add_agent("Jeep", lgsvl.AgentType.NPC, statej)

jeep.follow_closest_lane(True, 11.5)  # 11.1 m/s is ~40 km/h


statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + 30 * forward
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 10 * forward
sedan = sim.add_agent("Sedan", lgsvl.AgentType.NPC, statej)
sedan.follow_closest_lane(True, 10)  # 11.1 m/s is ~40 km/h

statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + 10 * forward
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 10 * forward
sedan1 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, statej)
sedan1.follow_closest_lane(True, 10)  # 11.1 m/s is ~40 km/h

statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + (100 * forward) 
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 25 * forward
suv = sim.add_agent("SUV", lgsvl.AgentType.NPC, statej)

suv.follow_closest_lane(True, 13.5)
statej = lgsvl.AgentState()
statej.transform.position = spawns[0].position + (80 * forward) 
statej.transform.rotation = spawns[0].rotation 
statej.velocity = 35 * forward
suv1 = sim.add_agent("SUV", lgsvl.AgentType.NPC, statej)

suv1.follow_closest_lane(True, 15.5)

right = lgsvl.utils.transform_to_right(spawns[0])

#input("Press Enter to drive forward for 25 seconds (1x)")
t0 = time.time()
sim.run(time_limit=17, time_scale=1)
t1 = time.time()
