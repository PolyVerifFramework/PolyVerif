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
import math
import unittest
env = Env()

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
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

sim.set_time_of_day(09.00, False)
print(sim.time_of_day)

# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

state.transform = spawns[0]
state.transform.position = spawns[0].position + 20 * forward# + 4.5 * right
state.transform.rotation.y = spawns[0].rotation.y - 3
state.velocity = 10 * forward #+3 * right #+ 10 * up 
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO, state)
print("target pos",spawns[0].position + 35 * forward + 4.5 * right)
Target_pos= lgsvl.Vector(213.5235540537694, 7.8, -2.769934874634476)
# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
print("ego speed",ego.state.speed)
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)
sim.run(time_limit=1)
t0 = time.time()

Duration = 4
step_time = 0.20
step_rate = int(1.0 / step_time)
print("step_rate",step_rate)
steps = Duration * step_rate
print("steps",steps)

for i in range(steps):
    print("loop steps",steps)
    t1 = time.time()
    sim.run(time_limit=step_time)
    state = ego.state
    pos = state.position
    print("pos",pos)
    speed = state.speed * 3.6
    
    '''for sp in range(int(speed)):
        print("sp",sp)
    if sp == 31.2 :
            c = lgsvl.VehicleControl()
            c.breaking=1
            ego.apply_control(c, True)'''
    
    print("Speed = {:4.1f}; Position = {:5.1f},{:5.1f},{:5.1f}".format(speed, pos.x, pos.y, pos.z))
    #time.sleep(0.2)


t3 = time.time()
print("t3",t3)
#sim.run(15)