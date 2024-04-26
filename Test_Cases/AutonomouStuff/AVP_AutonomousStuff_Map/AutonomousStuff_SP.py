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
from pathlib import Path
env = Env()

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene = "BorregasAve"
home = str(Path.home())
file = open(home+'/pid','w');
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()
print("pid : ",pid)
if sys.argv[1]: 
   rain = float(sys.argv[1])
   fog = float(sys.argv[2])
   wetness = float(sys.argv[3])
   cloudiness = float(sys.argv[4])
   damage = float(sys.argv[5])
   scene = sys.argv[6]

print("Running Scenario in which there is no Vehicle available in any Lane")
sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])


state = lgsvl.AgentState()
#state.transform = spawns[0]
#state.transform.position = spawns[0].position + 1 * right
#state.transform.rotation = spawns[0].rotation - 10
#state.transform.position = spawns[0].position - 5 * right
#state.transform.rotation = spawns[0].rotation
# state.velocity = 5 * forward
#tr = spawns[0]
# t1 = sim.map_from_gps(
#     northing=4137773.15130157,
#     easting=596690.508709717,
#     altitude=-19.1056592464447,
#     orientation=310,
# )
t1 = sim.map_from_gps(
    northing=4137772.17434235,
    easting=596691.283272553,
    altitude=-19.1056592464447,
    orientation=310,
)
# print("Transform from northing/easting: {}".format(t1))


# tr = spawns[0]
# t1 = sim.map_from_gps(
#     northing=6585998.77935791,
#     easting=367443.326144669,
#     altitude=5.47475310256,
#     orientation=-100,
# )
state.transform = t1
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "AVPCar"), lgsvl.AgentType.EGO, state)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
#ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
ego.connect_bridge(os.environ.get("BRIDGE_HOST", "127.0.0.1"), 9090)


for i, name in enumerate(["SUV"]):
    state1 = lgsvl.AgentState()
    state1.transform.position = spawns[0].position + (5 * forward) - (5.0 * i * right) # + 10.0 * forward
    state1.transform.rotation = spawns[0].rotation
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, state1)
    npc.follow_closest_lane(True, 12)

# for i, name in enumerate(["SUV", "Jeep"]):
#     state1 = lgsvl.AgentState()
#     state1.transform.position = spawns[0].position + (5 * forward) - (5.0 * i * right) # + 10.0 * forward
#     state1.transform.rotation = spawns[0].rotation
#     npc = sim.add_agent(name, lgsvl.AgentType.NPC, state1)
#     npc.follow_closest_lane(True, 5)


# for i, name in enumerate(["SUV", "SUV"]):
#     state1 = lgsvl.AgentState()
#     state1.transform.position = spawns[0].position + (15 * forward) - (3.0 * i * right) # + 10.0 * forward
#     state1.transform.rotation = spawns[0].rotation
#     npc = sim.add_agent(name, lgsvl.AgentType.NPC, state1)
#     npc.follow_closest_lane(True, 5)

#input("press Enter to run ")
#sim.run()

t0 = time.time()
sim.run(time_limit=25, time_scale=1)
t1 = time.time()
sim.stop()