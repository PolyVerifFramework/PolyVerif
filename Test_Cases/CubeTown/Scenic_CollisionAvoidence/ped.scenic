""" Scenario Description
Traffic Scenario 01.
Control loss without previous action.
The ego-vehicle loses control due to bad conditions on the road and it must recover, coming back to
its original lane.
"""


## SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/CubeTown.xodr')    # or other CARLA map that definitely works

model scenic.simulators.lgsvl.model


select_road = Uniform(*network.roads)
select_lane = Uniform(*select_road.lanes)


#BEHAVIORs

behavior PedestrianBehavior(min_speed=1, threshold=5):
    do CrossingBehavior(ego, min_speed, threshold)

behavior EgoBehavior(speed=5):
    do FollowLaneBehavior(speed)
    

ego = Car on select_lane.centerline,with behavior DriveAvoidingCollisions

right_sidewalk = network.laneGroupAt(ego)._sidewalk

Pedestrian on visible road 

p = Pedestrian right of ego
        
 




