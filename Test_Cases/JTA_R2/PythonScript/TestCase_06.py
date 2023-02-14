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
#scene = "aae03d2a-b7ca-4a88-9e41-9035287a12cc" # BorregasAve
scene = "781b04c8-43b4-431e-af55-1ae2b2efc877"
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
   #cene = sys.argv[6]

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)


# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])


#EGO
state.transform = spawns[0]
state.transform.position = spawns[0].position + 20 * forward#+ 4.5 * right
state.velocity = 11 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, state)
def lanechnage():
        agents = []
        def on_lane_change(agent):
            return True
        #agents.append(agent)
        npc.on_lane_change(on_lane_change)
        sim.run(1)
        npc.change_lane(False)
        
name1 = ["Sedan", "SUV", "Jeep"]
for i in range(3):
    # Create controllables in a block
    start = (
        spawns[0].position
        + (50 + (3.0 * (i // 4))) * forward
        - (0 + (3.0 * (i % 4))) * right
    )
    npcstate = lgsvl.AgentState()
    npcstate.transform.position = start
    npcstate.transform.rotation = spawns[0].rotation
    name = random.choice(name1)
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, npcstate)
    npc.follow_closest_lane(True,13)
    lanechnage()

'''
for i, name in enumerate(["Sedan", "SUV", "Jeep","SchoolBus"]):
    npcstate = lgsvl.AgentState()
     # Spawn NPC vehicles 10 meters ahead of the EGO
    npcstate.transform.position = spawns[0].position + (30*i *forward)- (2 * i * right) - (29 * forward)
    npcstate.transform.rotation = spawns[0].rotation
    npc = sim.add_agent(name, lgsvl.AgentType.NPC, npcstate)
    #sim.run(1)
    npc.follow_closest_lane(True,13)
    lanechnage()
    '''
sim.run(0.5)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)
# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)
sim.run(0.5)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.005
ego.apply_control(c, True)
sim.run(10)
