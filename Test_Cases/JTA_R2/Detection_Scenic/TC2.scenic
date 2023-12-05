""" Scenario Description
Voyage OAS Scenario Unique ID: 2-2-XX-CF-STR-CAR
The ego vehicle follows the lead car
"""

param map = localPath('maps/JTA_R2.xodr')
param lgsvl_map = 'JTA_R2'
timestep = 1.0/10
param time_step = timestep
model scenic.domains.driving.model
model scenic.simulators.lgsvl.model
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
print("***road",roads)
select_road = Uniform(*roads)
print("***select_road",select_road)
select_lane = Uniform(*select_road.lanes)
print("***select_lane",select_lane)

#OBJECT PLACEMENT
leadCar = Car on select_road,
		with behavior FollowLaneBehavior()
print("new -- ",roadDirection)
ego = Car following roadDirection from leadCar for INITIAL_DISTANCE_APART,
		with behavior FollowLeadCarBehavior()
for i in range(5):
	npc1 = NPCCar visible