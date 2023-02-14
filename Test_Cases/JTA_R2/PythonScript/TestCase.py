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

'''sim.set_time_of_day(18.00, False)
print(sim.time_of_day)'''
sim.run(1)
spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])

state = lgsvl.AgentState()
state.transform = spawns[0]
state.transform.position = spawns[0].position + 45 * forward #+ 5.5 * right
state.transform.rotation = spawns[0].rotation
state.velocity = 10 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)

state2 = lgsvl.AgentState()
state2.transform.position = spawns[0].position + 35 * forward + 2.8 * right 
state2.transform.rotation = spawns[0].rotation
npc2 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state2)

state1 = lgsvl.AgentState()
state1.transform.position = spawns[0].position + 30 * forward - 2.78 * right 
state1.transform.rotation = spawns[0].rotation
npc1 = sim.add_agent("Sedan", lgsvl.AgentType.NPC, state1)

'''state5 = lgsvl.AgentState()
state5.transform.position = state.transform.position - 5 * forward - 2 * right 
state5.transform.rotation = spawns[0].rotation
npc5 = sim.add_agent("SUV", lgsvl.AgentType.NPC, state5)'''
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
sim.run(2)

a = {
    ego: "EGO",
    npc2: "Jeep",
}


# Executed upon receiving collision callback -- NPC is expected to drive through colliding objects
def on_collision(agent1, agent2, contact):
    name1 = a[agent1]
    name2 = a[agent2] if agent2 is not None else "OBSTACLE"
    print("{} collided with {}".format(name1, name2))
    #sys.exit()

ego.on_collision(on_collision)
#ped.on_collision(on_collision)
#sim.run(1)
npc1.follow_closest_lane(True,10)
#npc5.follow_closest_lane(True,25)

c = lgsvl.agent.NPCControl()
c.e_stop = True
npc2.apply_control(c)
sim.run(1)
npc2.follow_closest_lane(True,15)

c1 = lgsvl.VehicleControl()    
c1.braking = 1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c1, True)
#sim.run(2)
'''c2 = lgsvl.VehicleControl()
c2.throttle = 0.5
#c.steering = 0.2
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c2, True)'''
sim.run(5)