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
scene = "06773677-1ce3-492f-9fe2-b3147e126e27"
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
state.transform = spawns[0]
state.transform.position = spawns[0].position - 1 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 9 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, state)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

print("Bridge connected:", ego.bridge_connected)


sim.add_random_agents(lgsvl.AgentType.PEDESTRIAN)


state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

# 10 meters ahead, on left lane
state.transform.position = spawns[0].position + 20.0 * forward - 5.0 *right 
state.transform.rotation = spawns[0].rotation
print("npcvector",spawns[0].position + 21.0 * forward - 6.0 *right )
npc1 = sim.add_agent("BoxTruck", lgsvl.AgentType.NPC, state)

state = lgsvl.AgentState()
# 10 meters ahead, on right lane
state.transform.position = spawns[0].position + 4.0 * right + 20.0 * forward
state.transform.rotation = spawns[0].rotation
npc2 = sim.add_agent("SUV", lgsvl.AgentType.NPC, state, lgsvl.Vector(1, 1, 0))
npc2.follow_closest_lane(True, 5.6)


state = lgsvl.ObjectState()
state.transform.position = spawns[0].position + 24 * forward + 8 * right 
state.transform.rotation = spawns[0].rotation
# add controllable
o = sim.controllable_add("ChargingStation", state)

t0 = time.time()
sim.run(time_limit=10, time_scale=1)
