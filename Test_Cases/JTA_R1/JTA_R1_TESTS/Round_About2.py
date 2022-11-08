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

sim.set_time_of_day(19.00, False)
print(sim.time_of_day)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
up = lgsvl.utils.transform_to_up(spawns[0])

# spawn EGO
egoState = lgsvl.AgentState()
egoState.transform = sim.get_spawn()[0]

forward = lgsvl.utils.transform_to_forward(egoState.transform) # Unit vector in the forward direction of the EGO
right = lgsvl.utils.transform_to_right(egoState.transform) # Unit vector in the right direction of the EGO
egoState.transform.position = spawns[0].position + 55* forward
egoState.transform.rotation = spawns[0].rotation
egoState.velocity = 8  * forward
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, egoState)


# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
 
for i in range(10 * 2):
    # Create controllables in a block
    start = (
        spawns[0].position
        + (100 + (1.0 * (i // 4))) * forward
        - ( 1 + (1.0 * (i % 4))) * right
    )
    end = start + 10 * forward
    state = lgsvl.ObjectState()
    state.transform.position = start
    state.transform.rotation = spawns[0].rotation
    '''# Set velocity and angular_velocity
    state.velocity = 10 * up
    state.angular_velocity = 6.5 * right'''

    # add controllable
    o = sim.controllable_add("TrafficCone", state)

# spawn NPC
npcState = lgsvl.AgentState()
npcState.transform = sim.map_point_on_lane(egoState.position + 55 * forward + 17 * right) # NPC is 20m ahead of the EGO
npc = sim.add_agent("SUV", lgsvl.AgentType.NPC, npcState)
npc.follow_closest_lane(True, 11.1)

'''
# Create the list of waypoints for the npc to follow
waypoints = []
# First waypoint is the same position that the npc is spawned. The npc will wait here until the EGO is within 50m
waypoints.append(lgsvl.DriveWaypoint(position=npcState.position, speed=20, angle=npcState.rotation, idle=0, deactivate=False, trigger_distance=0))
# Second waypoint is in between of junction
secondPoint = lgsvl.Vector(3.085383259077405, -1.03600001335144, -24.13449770325015)
waypoints.append(lgsvl.DriveWaypoint(position=secondPoint, speed=0, angle=spawns[0].rotation))
#end waypoint 
endPoint = lgsvl.Vector(40.73078708637528, -1.03600001335144, -36.234978924813724)
waypoints.append(lgsvl.DriveWaypoint(position=endPoint, speed=0, angle=npcState.rotation))

# When the NPC is within 0.5m of the waypoint, this will be called
def on_waypoint(agent, index):
    print("waypoint {} reached, waiting for ego to get closer".format(index))


# The above function needs to be added to the list of callbacks for the NPC
npc.on_waypoint_reached(on_waypoint)

npc.follow(waypoints,True)'''

sim.run(8)
