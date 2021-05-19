
#SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/CubeTown.xodr')  # or other CARLA map that definitely works
param carla_map = 'CubeTown'
model scenic.domains.driving.model

#CONSTANTS
SAFETY_DISTANCE = 10
INITIAL_DISTANCE_APART = -10
timestep = 1.0/10
param time_step = timestep
TERMINATE_TIME = 60 / timestep
MAX_BRAKE_THRESHOLD = 1
STOP_LENGTH = int(5 / timestep)

EGO_TO_OBSTACLE = Range(-20, -15)
CAR_POSITION_OFFSET = Range(-0.5,0.5)


behavior LeadCarSuddenlyStopsAndGo():

	sudden_stop_time = Range(3, 6) * 10
	last_stop = 0
	try:
		do FollowLaneBehavior(target_speed=25)

	interrupt when simulation().currentTime - last_stop > sudden_stop_time:
		for i in range(STOP_LENGTH):
			take SetBrakeAction(MAX_BRAKE_THRESHOLD), SetThrottleAction(0)
		last_stop = simulation().currentTime

# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.lanes'
initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)

#PLACEMENT
pos = (OrientedPoint at initLaneSec.centerline[-1]) offset by Range(-2, -2) @ 0
ego = Car following roadDirection from pos by Range(-100, -98)

#ego = Car at pos, facing roadDirection, with speed 2


#obstacle = Car at spawnPt offset by CAR_POSITION_OFFSET @ 1

#other = Car ahead of ego by 10,
#		with behavior LeadCarSuddenlyStopsAndGo,
#		with blueprint 'vehicle.tesla.model3'

#terminate when ego.lane is None
#terminate when simulation().currentTime > TERMINATE_TIME


