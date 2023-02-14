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
#scene = "06773677-1ce3-492f-9fe2-b3147e126e27"
#scene = "5d272540-f689-4355-83c7-03bf11b6865f" # BorregasAve
scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map
file = open('pid','w+')
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()
'''
if sys.argv[1]: 
   rain = float(sys.argv[1])
   fog = float(sys.argv[2])
   wetness = float(sys.argv[3])
   cloudiness = float(sys.argv[4])
   damage = float(sys.argv[5])
   '''


sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)
sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)
spawns = sim.get_spawn()
print(spawns)
# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

# NPC
state = lgsvl.AgentState()
state.transform.position = spawns[0].position +40 * forward  -3.5 * right 
state.transform.rotation = spawns[0].rotation
npc1 = sim.add_agent("SUV", lgsvl.AgentType.NPC, state)
npc1.velocity = 9 * forward
npc1.follow_closest_lane(True,25)


state.transform = spawns[0]
state.transform.position = spawns[0].position- 0.5 * right# + 20 * forward + 3 * right
state.transform.rotation.y = spawns[0].rotation.y - 3
state.velocity = 10 * forward #+ 4.8 *right
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, state)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)
'''

for i in range(1 * 3):
        names = ["Bicyclist", "Jeep", "Hatchback"]
        # Create controllables in a block
        start = (
            spawns[0].position
            + (50 + (3.0 * (i // 4))) * forward
            + (1 + (3.0 * (i % 4))) * right
        )
        state = lgsvl.AgentState()
        state.transform.position = start
        state.transform.rotation = spawns[0].rotation
        name1 = random.choice(names)
        npc = sim.add_agent(name1, lgsvl.AgentType.NPC, state)
        npc.follow_closest_lane(True, 11.1)
'''
agents = []

def on_lane_change(agent):
    return True
    #agents.append(agent)
'''
npc1.on_lane_change(on_lane_change)
sim.run(1)
npc1.change_lane(True)
a = (npc1.state.position - target).magnitude()
print("a",a)'''

npc1.on_lane_change(on_lane_change)
sim.run(1)
npc1.change_lane(False)
sim.run(10)
'''npc1.on_lane_change(on_lane_change)
sim.run(1)
npc1.change_lane(True)
sim.run(10)'''

