""" Scenario Description
Voyage OAS Scenario Unique ID: 2-2-XX-CF-STR-CAR
The ego vehicle follows the lead car
"""

#SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/BorregasAve.xodr')  # or other CARLA map that definitely works
param carla_map = 'BorregasAve'
#model scenic.domains.driving.model
from scenic.simulators.lgsvl.model import *


#CONSTANTS
SAFETY_DISTANCE = 10
INITIAL_DISTANCE_APART = -50

##DEFINING BEHAVIORS
behavior CollisionAvoidance(brake_intensity=0.3):
	while withinDistanceToAnyObjs(self, SAFETY_DISTANCE):
		take SetBrakeAction(brake_intensity)


##DEFINING SPATIAL RELATIONS
# Please refer to scenic/domains/driving/roads.py how to access detailed road infrastructure
# 'network' is the 'class Network' object in roads.py

# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.roads'
initLane = Uniform(*network.lanes)
roads = network.roads

select_road = Uniform(*roads)
select_lane = Uniform(*select_road.lanes)

#OBJECT PLACEMENT
ego = Car on select_lane.centerline,
		with behavior FollowLaneBehavior()
for i in range(2):
	npc3 = NPCCar visible

require ego can see npc3
#ego = Car following roadDirection from leadCar for INITIAL_DISTANCE_APART,
#		with behavior FollowLeadCarBehavior()

