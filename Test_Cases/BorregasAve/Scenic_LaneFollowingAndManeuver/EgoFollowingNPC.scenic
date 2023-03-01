""" Scenario Description
Voyage OAS Scenario Unique ID: 2-2-XX-CF-STR-CAR
The ego vehicle follows the lead car
"""

#SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
#param map = localPath('maps/06773677-1ce3-492f-9fe2-b3147e126e27')  # or other CARLA map that definitely works'
#param carla_map = 'CubeTown'

param map = localPath('maps/BorregasAve.xodr')
param lgsvl_map = 'aae03d2a-b7ca-4a88-9e41-9035287a12cc'
model scenic.domains.driving.model




#CONSTANTS
SAFETY_DISTANCE = 10
INITIAL_DISTANCE_APART = -10

##DEFINING BEHAVIORS
behavior CollisionAvoidance(brake_intensity=0.3):
	while withinDistanceToAnyObjs(self, SAFETY_DISTANCE):
		take SetBrakeAction(brake_intensity)


behavior FollowLeadCarBehavior():
	try: 
		do FollowLaneBehavior()

	interrupt when withinDistanceToAnyObjs(self, SAFETY_DISTANCE):
		do CollisionAvoidance()

##DEFINING SPATIAL RELATIONS
# Please refer to scenic/domains/driving/roads.py how to access detailed road infrastructure
# 'network' is the 'class Network' object in roads.py

# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.roads'
initLane = Uniform(*network.lanes)
roads = network.roads

select_road = Uniform(*roads)
select_lane = Uniform(*select_road.lanes)

#OBJECT PLACEMENT
leadCar = Car on select_lane.centerline,
		with behavior FollowLaneBehavior()
print("new -- ",roadDirection)
ego = Car following roadDirection from leadCar for INITIAL_DISTANCE_APART,
		with behavior FollowLeadCarBehavior()
