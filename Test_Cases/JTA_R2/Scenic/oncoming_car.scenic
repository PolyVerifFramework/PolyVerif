
## SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/CARLA/Town01.xodr')  
param carla_map = 'Town01'
param weather = 'ClearNoon' 
# param record = '/home/tarang/Code/carla994/PythonAPI/Scenic/oncoming_car_recordings'
model scenic.simulators.carla.model #located in scenic/simulators/carla/model.scenic

model scenic.domains.driving.model 
## CONSTANTS
MAX_BREAK_THRESHOLD = 1
SAFETY_DISTANCE = 22
EGO_SPEED = 7
DIST_THRESHOLD = 20
BYPASS_DIST = 18
ONCOMING_CAR_SPEED = 7

roads = network.roads
## DEFINING BEHAVIORS
behavior CollisionAvoidance():
    while withinDistanceToAnyObjs(self, SAFETY_DISTANCE):
        take SetBrakeAction(MAX_BREAK_THRESHOLD)

behavior OncomingCarBehavior():
    try:
        do FollowLaneBehavior(ONCOMING_CAR_SPEED, is_oppositeTraffic=True)
    interrupt when withinDistanceToAnyObjs(self, SAFETY_DISTANCE):
        do CollisionAvoidance()


behavior EgoBehavior(speed=10):
    try: 
        do FollowLaneBehavior(speed)

    interrupt when withinDistanceToAnyObjs(self, DIST_THRESHOLD):
    
        # change to left (overtaking)
        faster_lane = self.laneSection.fasterLane
        do LaneChangeBehavior(laneSectionToSwitch=faster_lane, target_speed=speed)
        do FollowLaneBehavior(speed, laneToFollow=faster_lane.lane) #until (distance to oncomingCar) > BYPASS_DIST

        # change to right
        slower_lane = self.laneSection.slowerLane
        do LaneChangeBehavior(laneSectionToSwitch=slower_lane, target_speed=speed)
        do FollowLaneBehavior(speed) for 5 seconds
        terminate


# make sure to put '*' to uniformly randomly select from all elements of the list of roads
select_road = Uniform(*roads)

# in roads.py, the 'class Road' contains 'lanes' which is a list of lanes whose rightmost lane is indexed 0
ego_lane = select_road.lanes[0]

start = OrientedPoint on ego_lane.centerline
ego = Car at start,
        with behavior EgoBehavior(speed=EGO_SPEED)

oncomingCar = Car following roadDirection for Range(25, 50),
    with heading 180 deg relative to roadDirection,
    with behavior OncomingCarBehavior()

# require ego can see oncomingCar
require (distance to intersection) > 50
require (ego.laneSection._fasterLane is not None)

#TODO Spawn vehicles in nearby lanes instead of randomly
lane1 = Uniform(*select_road.lanes[1:])
require lane1 is not ego_lane
spot1 = OrientedPoint on lane1.centerline
background_car1 = Car at spot1,
        with behavior OncomingCarBehavior()
require background_car1 can see ego
