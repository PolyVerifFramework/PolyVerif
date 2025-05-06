param map = localPath('maps/JTA_R2.xodr')
param lgsvl_map = 'JTA_R2'
timestep = 1.0/10
param time_step = timestep

model scenic.simulators.lgsvl.model

MAX_BRAKE_THRESHOLD = 1
TERMINATE_TIME = 30 / timestep
STOP_LENGTH = int(5 / timestep)

behavior CollisionAvoidance(safety_distance=10, brake_intensity=1):
    while (distance to other) < safety_distance:
        take SetBrakeAction(brake_intensity), SetThrottleAction(0)

behavior FollowLeadCar(safety_distance=10):
    try: 
        do FollowLaneBehavior(target_speed=25)

    interrupt when ((distance to other) < safety_distance):
        do CollisionAvoidance()

behavior EmergencyLaneChange():
    try:
        do FollowLaneBehavior(target_speed=25)

    interrupt when (distance to other) < 20:
        do ChangeLaneAction(direction='right')

ego = Car with behavior FollowLeadCar(10),
    with blueprint 'vehicle.tesla.model3'

other = Car ahead of ego by 10,
    with behavior FollowLaneBehavior(target_speed=20),
    with blueprint 'vehicle.tesla.model3'

npc1 = NPCCar visible

require ego can see npc1

terminate when ego.lane is None
terminate when other.lane is None
terminate when simulation().currentTime > TERMINATE_TIME
