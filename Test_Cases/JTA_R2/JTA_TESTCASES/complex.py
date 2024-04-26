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
scene = "JTA_R2"
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
right = lgsvl.utils.transform_to_right(egoState.transform) 
up =lgsvl.utils.transform_to_up(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 20 * forward #- 10 * right
egoState.velocity = 10 * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, egoState)



# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

for i in range(1*10):
  # Create controllables in a block
  start = spawns[0].position + (170 + (1.0 * (i//10))) * forward  + (2 + (1.0 * (i % 10))) * right
  

  state = lgsvl.ObjectState()
  state.transform.position = start
  state.transform.rotation = spawns[0]
  # Set velocity and angular_velocity
  #state.velocity = 50 * up
  #state.angular_velocity = 6.5 * right 

  # add controllable
  cone = sim.controllable_add("TrafficCone", state)


# NPC
npcstate = lgsvl.AgentState()
npcstate.transform.position = spawns[0].position + 50.0 * forward   #-7* right
npcstate.transform.rotation = spawns[0].rotation
npc = sim.add_agent("SUV", lgsvl.AgentType.NPC, npcstate)
npc.follow_closest_lane(True,12)


npc1state = lgsvl.AgentState()
npc1state.transform.position = spawns[0].position + 190.0 * forward + 6* right +10* up
npc1state.transform.rotation = spawns[0].rotation + 60
npc1 = sim.add_agent("BoxTruck", lgsvl.AgentType.NPC, npc1state)



vehicles = {
    npc: "npc",
    cone: "TrafficCone",
   
}


# Executed upon receiving collision callback -- NPC is expected to drive through colliding objects
def on_collision(agent1, agent2, contact):
    name1 = vehicles[agent1]
    name2 = vehicles[agent2] if agent2 is not None else "OBSTACLE"
    print("{} collided with {}".format(name1, name2))
    sys.exit()
#npc.on_collision(on_collision)
if npc.on_collision(on_collision) == True:

    c = lgsvl.agent.NPCControl()
    c.e_stop = True
    npc.apply_control(c)
sim.run(10)
c = lgsvl.VehicleControl()
#c.throttle = 0.5
c.steering = -0.2
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(2) 
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.2
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(3)
c = lgsvl.VehicleControl()
c.throttle = 0.0
c.steering = 0.1
# a True in apply_control means the control will be continuously applied ("sticky"). False means the control will be applied for 1 frame
ego.apply_control(c, True)
sim.run(5)
#sim.run(15)