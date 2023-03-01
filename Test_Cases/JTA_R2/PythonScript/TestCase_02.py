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
sim.set_time_of_day(19.00, False)
print(sim.time_of_day)

# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

'''# NPC
state = lgsvl.AgentState()
state.transform.position = spawns[0].position + 20 * forward + 2.5 * right 
state.transform.rotation = spawns[0].rotation
npc = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state)
npc.velocity = 15 * forward
npc.follow_closest_lane(True,25)'''

#EGO
state.transform = spawns[0]
state.transform.position = spawns[0].position + 10 * forward# - 2 * right
state.velocity =  10*forward# *10 * right

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, state)
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)
# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

'''print("Real time elapsed =", 0)
print("Simulation time =", sim.current_time)
print("Simulation frames =", sim.current_frame)

input("Press Enter to drive forward for 4 seconds (2x)")

# The simulator can be run for a set amount of time. time_limit is optional and if omitted or set to 0, then the simulator will run indefinitely
t0 = time.time()
sim.run(time_limit=4, time_scale=2)
t1 = time.time()
print("Real time elapsed =", t1 - t0)
print("Simulation time =", sim.current_time)
print("Simulation frames =", sim.current_frame)

current_sim_time = sim.current_time
current_sim_frames = sim.current_frame

input("Press Enter to continue driving for 2 more seconds (0.5x)")

t2 = time.time()
sim.run(time_limit=2, time_scale=0.5)
t3 = time.time()

print("Real time elapsed =", t3 - t2)
print("Simulation time =", sim.current_time - current_sim_time)
print("Simulation frames =", sim.current_frame - current_sim_frames)
'''

# spawn random NPCs
sim.add_random_agents(lgsvl.AgentType.NPC)
sim.add_random_agents(lgsvl.AgentType.PEDESTRIAN)

t0 = time.time()
s0 = sim.current_time
print()
print("Total real time elapsed = {:5.3f}".format(t0))
print("Simulation time = {:5.1f}".format(s0))
print("Simulation frames =", sim.current_frame)

# let simulator initialize and settle a bit before starting
sim.run(time_limit=2)

t1 = time.time()
s1 = sim.current_time
print()
print("Total real time elapsed = {:5.3f}".format(t1 - t0))
print("Simulation settle time = {:5.1f}".format(s1 - s0))
print("Simulation settle frames =", sim.current_frame)

# tell ego to drive forward, or not (if apollo is driving)
if not ego.bridge_connected:
    state = ego.state
    forward = lgsvl.utils.transform_to_forward(state.transform)
    state.velocity = 20 * forward
    ego.state = state
    duration = 15
else:
    duration = 45

step_time = 0.10

step_rate = int(1.0 / step_time)
steps = duration * step_rate
print()
print("Stepping forward for {} steps of {}s per step" .format(steps, step_time))
input("Press Enter to start:")

# The simulator can be run for a set amount of time.
# time_limit is optional and if omitted or set to 0, then the simulator will run indefinitely
t0 = time.time()
for i in range(steps):
    t1 = time.time()
    sim.run(time_limit=step_time)
    t2 = time.time()
    s2 = sim.current_time

    state = ego.state
    pos = state.position
    speed = state.speed * 3.6

    # if Apollo is not driving
    if not ego.bridge_connected:
        state.velocity = 20 * forward
        ego.state = state

    print("Sim time = {:5.2f}".format(s2 - s1) + "; Real time elapsed = {:5.3f}; ".format(t2 - t1), end='')
    print("Speed = {:4.1f}; Position = {:5.3f},{:5.3f},{:5.3f}".format(speed, pos.x, pos.y, pos.z))
    time.sleep(0.2)

t3 = time.time()

# Final statistics
print("Total real time elapsed = {:5.3f}".format(t3 - t0))
print("Simulation time = {:5.1f}".format(sim.current_time))
print("Simulation frames =", sim.current_frame)