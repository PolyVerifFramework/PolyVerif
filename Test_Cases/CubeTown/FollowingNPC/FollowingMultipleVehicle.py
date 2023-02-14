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
scene = "06773677-1ce3-492f-9fe2-b3147e126e27" # BorregasAve
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
state.velocity = 5 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842977"), lgsvl.AgentType.EGO, state)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))


forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])


for i, name in enumerate(["Sedan", "SUV", "Hatchback"]):
    state1 = lgsvl.AgentState()

    # Spawn NPC vehicles 10 meters ahead of the EGO
    state1.transform.position = spawns[0].position + (40 * forward) - (4.0 * i * right) # + 10.0 * forward
    state1.transform.rotation = spawns[0].rotation
    state1.velocity = 10 * forward
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, state1)
    npc.follow_closest_lane(True, 12)

#input("Press Enter to drive forward for 25 seconds (1x)")
t0 = time.time()
sim.run(time_limit=25, time_scale=1)
t1 = time.time()