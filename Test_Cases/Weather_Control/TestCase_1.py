#!/usr/bin/env python3
#
# Copyright (c) 2019-2020 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

from environs import Env
import lgsvl
import time
import sys
import os

env = Env()

#0.1 0.2 0.1 0.1 0.1 BorregasAve
# Taking arguments for weather parameters and scene
rain = 0.1
fog = 0.2
wetness = 0.1
cloudiness = 0.1
damage = 0.1
scene = "BorregasAve"


print("Running Scenario in which Ego Vehicle run in straight lane and applied Brake")
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
state.transform.position = spawns[0].position - 5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 20 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)



# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))


forward = lgsvl.utils.transform_to_forward(spawns[1])
#right = lgsvl.utils.transform_to_right(spawns[1])
statej = lgsvl.AgentState()
statej.transform.position = spawns[1].position #- 5 * right
statej.transform.rotation = spawns[1].rotation 
statej.velocity = 20 * forward
jeep = sim.add_agent("Jeep", lgsvl.AgentType.NPC, statej)

jeep.follow_closest_lane(True, 15)  # 11.1 m/s is ~40 km/h

statej = lgsvl.AgentState()
statej.transform.position = spawns[1].position + 10 * forward
statej.transform.rotation = spawns[1].rotation 
statej.velocity = 20 * forward
sedan = sim.add_agent("Sedan", lgsvl.AgentType.NPC, statej)
sedan.follow_closest_lane(True, 15)  # 11.1 m/s is ~40 km/h


statej = lgsvl.AgentState()
statej.transform.position = spawns[1].position + 20 * forward
statej.transform.rotation = spawns[1].rotation 
statej.velocity = 20 * forward
suv = sim.add_agent("SUV", lgsvl.AgentType.NPC, statej)

suv.follow_closest_lane(True, 13.5)

#input("Press Enter to drive forward for 25 seconds (1x)")
t0 = time.time()
print("before running")
sim.run(time_limit=20, time_scale=2)
c = lgsvl.VehicleControl()
c.braking = 1
ego.apply_control(c, True)

#sim.run()
print("After running")
t1 = time.time()


