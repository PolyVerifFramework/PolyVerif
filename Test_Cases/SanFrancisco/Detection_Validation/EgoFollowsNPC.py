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
scene = "5d272540-f689-4355-83c7-03bf11b6865f"
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

print("Running Scenario in which there is no Vehicle available in any Lane")
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
state.transform.position = spawns[0].position - 3.2 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 12 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)



# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)


for i, name in enumerate(["Sedan", "SUV"]):
    state1 = lgsvl.AgentState()

    # Spawn NPC vehicles 10 meters ahead of the EGO
    state1.transform.position = spawns[0].position + (50 * forward) - (4.0 * i * right) # + 10.0 * forward
    state1.transform.rotation = spawns[0].rotation
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, state1)
    npc.follow_closest_lane(True, 15)
#input("Press Enter to drive forward for 25 seconds (1x)")
t0 = time.time()
sim.run(time_limit=20, time_scale=1)
t1 = time.time()


