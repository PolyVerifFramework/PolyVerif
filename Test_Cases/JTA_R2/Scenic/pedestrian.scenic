#import scenic.domains.driving.model as _model
param map = localPath('../../tests/formats/opendrive/maps/CARLA/Town01.xodr')
param lgsvl_map = 'Town01'

model scenic.domains.driving.model 
#model scenic.simulators.lgsvl.model
select_road = Uniform(*network.roads)
select_lane = Uniform(*select_road.lanes)

behavior EgoBehavior(speed=15):
    do FollowLaneBehavior(speed)

ego = Car on select_lane.centerline,
       with behavior EgoBehavior()
       #with behavior DriveAvoidingCollisions(avoidance_threshold=10)

for i in range(10):
    Pedestrian ahead of ego from Range(20,100) ,
        with heading 180 deg relative to roadDirection,
        with regionContainedIn None,
        with lgsvlName Uniform('Howard','SegwayKickScooterMaxG30LP'),
        with behavior WalkBehavior(10)


    
    


