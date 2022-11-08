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

# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
env = Env()
scene = "JTA_R1"
file = open('pid','w+')
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

spawns = sim.get_spawn()
sim.set_time_of_day(18.00, False)
print(sim.time_of_day)

# EGO
egoState = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

# spawn EGO
egoState = lgsvl.AgentState()
egoState.transform = sim.get_spawn()[0]
forward = lgsvl.utils.transform_to_forward(egoState.transform) # Unit vector in the forward direction of the EGO
right = lgsvl.utils.transform_to_right(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 20 * forward - 10 * right
egoState.velocity = 10 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, egoState)



# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)


# NPC
npcstate = lgsvl.AgentState()
npcstate.transform.position = egoState.transform.position + 75.0 * forward -  17* right
npcstate.transform.rotation.y = spawns[0].rotation.y + 90
npc = sim.add_agent("SUV", lgsvl.AgentType.NPC, npcstate)
npc.follow_closest_lane(True,5)

# NPC
state = lgsvl.AgentState()
state.transform.position = npcstate.transform.position + 1* forward - 20* right
state.transform.rotation.y = spawns[0].rotation.y + 90
npc1 = sim.add_agent("Hatchback", lgsvl.AgentType.NPC, state)
npc1.follow_closest_lane(True,7)
sim.run(4)

c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = 0.13
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(1.5)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = -0.12
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.0
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2)
#sim.run(15)