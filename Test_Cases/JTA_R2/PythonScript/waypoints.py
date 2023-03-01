#!/usr/bin/env python3
#
# Copyright (c) 2020 LG Electronics, Inc.
#
# This software contains code licensed as described in LICENSE.
#

from datetime import datetime
from environs import Env
import random
import lgsvl
import math
import sys
import os
'''
LGSVL__RANDOM_SEED                  Simulation random seed
LGSVL__SIMULATION_DURATION_SECS     How long to run the simulation for
LGSVL__VEHICLE_0                    ID of EGO vehicle to be loaded in Simulator
'''
# Taking arguments for weather parameters and scene
rain = 0
fog = 0
wetness = 0
cloudiness = 0
damage = 0
env = Env()
scene =scene = "781b04c8-43b4-431e-af55-1ae2b2efc877" #JTA_R2 Map

file = open('pid','w+')
t = os.getpid()
pid = str(t)
file.write(pid)
file.close()

SIMULATOR_HOST = env.str("LGSVL__SIMULATOR_HOST", "127.0.0.1")
SIMULATOR_PORT = env.int("LGSVL__SIMULATOR_PORT", 8181)

LGSVL__SIMULATION_DURATION_SECS = 10.0
LGSVL__RANDOM_SEED = env.int("LGSVL__RANDOM_SEED", 51472)

sim = lgsvl.Simulator(SIMULATOR_HOST, SIMULATOR_PORT)
try:
    print("Loading map {}...".format(scene))
    sim.load(scene, LGSVL__RANDOM_SEED) # laod map with random seed
except Exception:
    if sim.current_scene == scene:
        sim.reset()
    else:
        sim.load(scene)
sim.set_time_of_day(18.00, False)
print(sim.time_of_day)
'''
# reset time of the day
sim.set_date_time(datetime(2022, 6, 27, 11, 0, 0, 0), True)'''

spawns = sim.get_spawn()

# select spawn deterministically depending on the seed
spawn_index = LGSVL__RANDOM_SEED % len(spawns)


spawns = sim.get_spawn()
layer_mask =0
layer_mask |= 1 << 0  # 0 is the layer for the road (default)


'''state = lgsvl.AgentState()
state.transform = spawns[spawn_index]  # TODO some sort of Env Variable so that user/wise can select from list
forward = lgsvl.utils.transform_to_forward(spawns[spawn_index])
right = lgsvl.utils.transform_to_right(spawns[spawn_index])
state.velocity = 8 * forward 
ego = sim.add_agent(env.str("LGSVL__VEHICLE_0", "Jaguar2015XE (AutowareAI)"), lgsvl.AgentType.EGO, state)'''
# EGO
state = lgsvl.AgentState()
forward = lgsvl.utils.transform_to_forward(spawns[spawn_index])
right = lgsvl.utils.transform_to_right(spawns[spawn_index])
spawn_state = spawns[0]
hit = sim.raycast(
    spawn_state.position + forward * 40, lgsvl.Vector(0, 1, 0), layer_mask
)
#spawn_state.position = hit.point
state.transform = spawn_state
state.velocity = forward * 7

ego = sim.add_agent(env.str("LGSVL__VEHICLE_0","5ab8175f-e1f1-427c-a86e-e882fa842978"), lgsvl.AgentType.EGO,state)

# The EGO is now looking for a bridge at the specified IP and port
ego.connect_bridge(env.str("LGSVL__AUTOPILOT_0_HOST", "127.0.0.1"), env.int("LGSVL__AUTOPILOT_0_PORT", 9090))
# An EGO will not connect to a bridge unless commanded to
print("Bridge connected:", ego.bridge_connected)

'''sim.add_random_agents(lgsvl.AgentType.NPC)
sim.add_random_agents(lgsvl.AgentType.PEDESTRIAN)
'''
# NPC
state = lgsvl.AgentState()
npc_position = lgsvl.Vector(-4, -1, -48)
hit = sim.raycast(npc_position, lgsvl.Vector(0, 1, 0), layer_mask)
npc_rotation = lgsvl.Vector(0, 16, 0)
#state.transform.position = hit.point
state.transform.rotation = npc_rotation
npc = sim.add_agent("Sedan", lgsvl.AgentType.NPC, state)

vehicles = {
    ego: "EGO",
    npc: "Sedan",
}


# Executed upon receiving collision callback -- NPC is expected to drive through colliding objects
def on_collision(agent1, agent2, contact):
    name1 = vehicles[agent1]
    name2 = vehicles[agent2] if agent2 is not None else "OBSTACLE"
    print("{} collided with {}".format(name1, name2))
    #sys.exit()

ego.on_collision(on_collision)
npc.on_collision(on_collision)
# This block creates the list of waypoints that the NPC will follow
# Each waypoint is an position vector paired with the speed that the NPC will drive to it
waypoints = []

for i in range(2):
    speed = 8  # if i % 2 == 0 else 12
    # Waypoint angles are input as Euler angles (roll, pitch, yaw)
    angle = npc_rotation
    # Raycast the points onto the ground because BorregasAve is not flat
    npc_position.x += 6
    npc_position.z += 21
    hit = sim.raycast(npc_position, lgsvl.Vector(0, 1, 0), layer_mask)
    trigger = None

if i == 0:

    effector = lgsvl.TriggerEffector("TimeToCollision", {})
    trigger = lgsvl.WaypointTrigger([effector])
wp = lgsvl.DriveWaypoint(

    position=hit.point,
    speed=speed,
    angle=angle,
    idle=0,
    trigger_distance=0,
    trigger=trigger,
)
waypoints.append(wp)


def on_waypoint(agent, index):
    print("waypoint {} reached".format(index))


def agents_traversed_waypoints():
    print("All agents traversed their waypoints.")
    sim.stop()


# The above function needs to be added to the list of callbacks for the NPC
npc.on_waypoint_reached(on_waypoint)
sim.agents_traversed_waypoints(agents_traversed_waypoints)

# The NPC needs to be given the list of waypoints.
# A bool can be passed as the 2nd argument that controls whether or not the NPC loops over the waypoints (default false)
npc.follow(waypoints)


sim.run(LGSVL__SIMULATION_DURATION_SECS)

