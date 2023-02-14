""" Scenario Description
Based on 2019 Carla Challenge Traffic Scenario 03.
Leading vehicle decelerates suddenly due to an obstacle and 
ego-vehicle must react, performing an emergency brake or an avoidance maneuver.
"""
param map = localPath('../../../tests/formats/opendrive/maps/CARLA/Town01.xodr')  # or other CARLA map that definitely works
param carla_map = 'Town01'
model scenic.domains.driving.model

#CONSTANTS
EGO_SPEED = 10
THROTTLE_ACTION = 0.6
BRAKE_ACTION = 1.0
EGO_TO_OBSTACLE = Range(-20, -15)
EGO_BRAKING_THRESHOLD = 11
CAR_POSITION_OFFSET = Range(-0.5,0.5)

#EGO BEHAVIOR: Follow lane and brake when reaches threshold distance to obstacle
behavior EgoBehavior(speed=10):
	
	try:
		do FollowLaneBehavior(speed)

	interrupt when withinDistanceToObjs(self, EGO_BRAKING_THRESHOLD):
		take SetBrakeAction(BRAKE_ACTION)

#GEOMETRY
initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)

#PLACEMENT
spawnPt = OrientedPoint on initLaneSec.centerline

obstacle = Car at spawnPt offset by CAR_POSITION_OFFSET @ 0
'''
ego = Car following roadDirection from spawnPt for EGO_TO_OBSTACLE,
	with behavior EgoBehavior(EGO_SPEED)


Car offset by Range(-5, 5) @ Range(20, 40)
'''
'''
ego = Car following roadDirection from spawnPt or EGO_TO_OBSTACLE , 
	with behavior EgoBehavior(EGO_SPEED)
'''
'''for i in range(5):
	#Car visible
	Pedestrian visible,with regionContainedIn None,with behavior WalkBehavior(15)
ego = Car
c2 = Car offset by Range(-10, 10) @ Range(20, 40), with viewAngle 60 deg
c3 = Car at c2 offset by Range(-10, 10) @ 0, with viewAngle 45 deg
c4 = Car offset by Range(-10, 10) @ Range(30, 50), with viewAngle 90 deg
require c4 can see ego
require c2 can see ego
require c3 can see ego'''

ego = Car
c2 = Car offset by Range(-10, 10) @ Range(20, 40),
	facing Range(-10 deg, 10 deg) relative to roadDirection

def angled(angle, epsilon=10 deg):
	a = apparent heading of c2
	return (abs(a - angle) <= epsilon) or (abs(a + angle) <= epsilon)

require angled(90 deg)

Car at c2 offset by Range(-10, 10) @ Range(-10, 10),
	facing Range(-10 deg, 10 deg) relative to roadDirection
