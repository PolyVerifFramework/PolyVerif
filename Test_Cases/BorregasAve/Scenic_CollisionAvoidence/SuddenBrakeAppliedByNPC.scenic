
param map = localPath('maps/BorregasAve.xodr')
param lgsvl_map ='BorregasAve'
timestep = 1.0/10
param time_step = timestep

model scenic.simulators.lgsvl.model

CAR_POSITION_OFFSET = Range(0,0)
MAX_BRAKE_THRESHOLD = 1
TERMINATE_TIME = 30 / timestep
STOP_LENGTH = int(5 / timestep)


behavior CollisionAvoidance(safety_distance=10, brake_intensity=0.5):
	while (distance to other) < safety_distance:
		take SetBrakeAction(brake_intensity), SetThrottleAction(0)


behavior FollowLeadCar(safety_distance=10):

	try: 
		do FollowLaneBehavior(target_speed=25)

	interrupt when ((distance to other) < safety_distance):
		do CollisionAvoidance()


behavior LeadCarSuddenlyStopsAndGo():

	sudden_stop_time = Range(3, 6) * 10
	last_stop = 0
	try:
		do FollowLaneBehavior(target_speed=25)

	interrupt when simulation().currentTime - last_stop > sudden_stop_time:
		for i in range(STOP_LENGTH):
			take SetBrakeAction(MAX_BRAKE_THRESHOLD), SetThrottleAction(0)
		last_stop = simulation().currentTime

start = Point on road  
initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)
print("start : ",start)
#PLACEMENT
spawnPt = OrientedPoint on initLaneSec.centerline
#ego = Car following roadDirection from spawnPt for Range(-50, -30),

#ego = Car at start, 
ego = AutowareEgoCar following roadDirection from spawnPt for Range(-50, -30),
      with behavior FollowLeadCar(10),
	  with blueprint 'vehicle.tesla.model3'

other = Car ahead of ego by 10,
		with behavior LeadCarSuddenlyStopsAndGo,
		with blueprint 'vehicle.tesla.model3'
	
require (Point ahead of ego by 100) in road

terminate when ego.lane is None
terminate when other.lane is None
terminate when simulation().currentTime > TERMINATE_TIME
