#!/usr/bin/env python3
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
import math


env = Env()

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
scene = scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map

file = open('pid','w+');
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

#if sys.argv[1]: 
   #rain = float(sys.argv[1])
   #fog = float(sys.argv[2])
   #wetness = float(sys.argv[1])
   #cloudiness = float(sys.argv[4])
   #damage = float(sys.argv[5])
   #scene = sys.argv[6]


print("adding pedestrian's")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)
print("Test")
#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)
'''
sim.set_time_of_day(18.00, False)
print(sim.time_of_day)'''

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 20 * forward# + 3.5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 12  * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)
for i in range(10 * 2):
    # Create controllables in a block
    start = (
        spawns[0].position
        + (100 + (1.0 * (i // 4))) * forward
        - (3.9 + (1.0 * (i % 4))) * right
    )
    end = start + 10 * forward
    state = lgsvl.ObjectState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    o = sim.controllable_add("TrafficCone", state)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))

state1 = lgsvl.AgentState()
state1.transform.position = spawns[0].position + 35 * forward + 4.78 * right 
state1.transform.rotation = spawns[0].rotation
npc1 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, state1)

state2 = lgsvl.AgentState()
state2.transform.position = spawns[0].position + 25 * forward - 5.8 * right 
state2.transform.rotation = spawns[0].rotation
npc2 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state2)

state3 = lgsvl.AgentState()
state3.transform.position = state2.transform.position + 20 * forward + 4.78 * right 
state3.transform.rotation = spawns[0].rotation
npc3 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state3)


npc3.follow_closest_lane(True,10)
npc2.follow_closest_lane(True,15)
npc1.follow_closest_lane(True,8)


agents = []
def on_lane_change(agent):
    return True
    #agents.append(agent)
npc3.on_lane_change(on_lane_change)
sim.run(1)
#npc3.change_lane(True)
sim.run(1.5)
npc3.change_lane(False)
npc1.change_lane(True)
npc2.change_lane(False)
sim.run(0.2)
c = lgsvl.VehicleControl()
c.throttle = -0.8
c.steering = 0.010
ego.apply_control(c, True)
sim.run(3.2)
c = lgsvl.VehicleControl()
c.breaking=0.7
ego.apply_control(c, True)
sim.run(0.1)
c = lgsvl.VehicleControl()
c.throttle = 0.2
c.steering = -0.005
ego.apply_control(c, True)
npc1.change_lane(False)
sim.run(13)

#sim.run(10)