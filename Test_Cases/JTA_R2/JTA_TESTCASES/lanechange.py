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

spawns = sim.get_spawn()

sim.set_time_of_day(18.00, False)
print(sim.time_of_day)

# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

state.transform = spawns[0]
state.transform.position = spawns[0].position + 20 * forward + 0.8 * right
print(spawns[0].position + 10 * forward + 0.8 * right)
state.velocity =10 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)
sim.run(2)
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
sim.run(1)

# NPC
state2 = lgsvl.AgentState()
state2.transform.position = spawns[0].position + 88 * forward #+ 1 * right 
state2.transform.rotation = spawns[0].rotation
npc2 = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state2)
npc2.follow_closest_lane(True,25)
sim.run(1)
npc2.change_lane(True)
sim.run(5)

def on_lane_change(agent, index):
  print("waypoint {} reached".format(index))

npc2.change_lane(True)
npc2.on_lane_change(on_lane_change)

'''# t0 is the time when the Simulation started
t0 = time.time()

# This will keep track of if the NPC has already changed lanes
npc2ChangedLanes = False

# Run Simulation for 4 seconds before checking cut-in or end conditions
sim.run(4)

# The Simulation will pause every 0.5 seconds to check 2 conditions
while True:
    sim.run(0.5)

    # If the NPC has not already changed lanes then the distance between the NPC and EGO is calculated
    if not npcChangedLanes:
        egoCurrentState = ego.state
        npcCurrentState = npc.state

        separationDistance = (egoCurrentState.position - npcCurrentState.position).magnitude()

        # If the EGO and NPC are within 15m, then NPC will change lanes to the right (in front of the EGO)
        if separationDistance <= 15:
            npc.change_lane(True)
            npcChangedLanes = True

    # Simulation will be limited to running for 30 seconds total
    if time.time() - t0 > 26:
        break
'''

''' # Simulation will be limited to running for 30 seconds total
if time.time() - t0 > 26:
    break
'''