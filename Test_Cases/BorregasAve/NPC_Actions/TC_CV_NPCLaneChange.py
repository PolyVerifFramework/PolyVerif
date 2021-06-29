#!/usr/bin/env python3
#
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
scene = "BorregasAve"
file = open('pid','w');
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

if sys.argv[1]: 
   rain = float(sys.argv[1])
   fog = float(sys.argv[2])
   wetness = float(sys.argv[3])
   cloudiness = float(sys.argv[4])
   damage = float(sys.argv[5])
   scene = sys.argv[6]

print("Scenario with some NPC's")

sim = lgsvl.Simulator(env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1"), env.int("LGSVL__SIMULATOR_PORT", 8181))
if sim.current_scene == scene:
    sim.reset()
else:
    sim.load(scene)

#sim.weather = lgsvl.WeatherState(rain, fog, wetness, cloudiness, damage)

spawns = sim.get_spawn()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])


state = lgsvl.AgentState()
state.transform.position = spawns[0].position - 5 * forward
state.transform.rotation = spawns[0].rotation
#state.transform.position = spawns[0].position - 5 * right ## for lane change
#state.transform.rotation = spawns[0].rotation
state.velocity = 10 * forward

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "myLexusVehicle"), lgsvl.AgentType.EGO, state)

# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))


state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[0])
right = lgsvl.utils.transform_to_right(spawns[0])
state.velocity = 5 * forward

# 20 meters ahead, on left lane
state.transform.position = spawns[0].position + 20 * forward
state.transform.rotation = spawns[0].rotation #+ 100
npc = sim.add_agent("Sedan", lgsvl.AgentType.NPC, state)

# state.transform.position = spawns[0].position + 40 * forward
# state.transform.rotation = spawns[0].rotation #+ 100
# npc1 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, state)


waypoints = []
x_max = 2
z_delta = 12

layer_mask = 0
layer_mask |= 1 << 0  # 0 is the layer for the road (default)

for i in range(20):
    speed = 10  # if i % 2 == 0 else 12
    px = 0
    pz = (i + 1) * z_delta
    # Waypoint angles are input as Euler angles (roll, pitch, yaw)
    angle = spawns[0].rotation 
    # Raycast the points onto the ground because BorregasAve is not flat
    hit = sim.raycast(
        spawns[0].position + pz * forward, lgsvl.Vector(0, -1, 0), layer_mask
    )

    # NPC will wait for 0 second at each waypoint
    wp = lgsvl.DriveWaypoint(hit.point, speed, angle, 0)
    waypoints.append(wp)


# When the NPC is within 0.5m of the waypoint, this will be called
def on_waypoint(agent, index):
    print("waypoint {} reached".format(index))

# The above function needs to be added to the list of callbacks for the NPC
npc.on_waypoint_reached(on_waypoint)

# The NPC needs to be given the list of waypoints.
# A bool can be passed as the 2nd argument that controls whether or not the NPC loops over the waypoints (default false)
npc.follow(waypoints)


# state = lgsvl.AgentState()
# state.transform.position = spawns[0].position + 40 * forward
# state.transform.rotation = spawns[0].rotation #+ 100
# spawn NPC in left lane
npcState = lgsvl.AgentState()
npcState.transform = sim.get_spawn()[0]
npc1 = sim.add_agent("Jeep", lgsvl.AgentType.NPC, npcState)


# NPC will drive forward and then change lanes into the right lane at ~25 mph
npcSpeed = 12
nx = npc.state.position.x
ny = npc.state.position.y
nz = npc.state.position.z
npcWaypoints = []
npcWaypoints.append(lgsvl.DriveWaypoint(lgsvl.Vector(nx-2, ny, nz), npcSpeed))
npcWaypoints.append(lgsvl.DriveWaypoint(lgsvl.Vector(nx-15, ny, nz+3), npcSpeed))
npcWaypoints.append(lgsvl.DriveWaypoint(lgsvl.Vector(nx-50, ny, nz+4), npcSpeed))


npc1.follow(npcWaypoints)

input("Press enter to run simulation")

#input("Press Enter to drive forward for 25 seconds (1x)")
# t0 = time.time()
# sim.run(time_limit=25, time_scale=1)
# t1 = time.time()
sim.run()

