
param map = localPath('maps/cubetown.xodr')
param lgsvl_map = 'cubeTown'
param apolloHDMap = 'cubeTown'
param time_step = 1.0/2

model scenic.simulators.lgsvl.model

# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.roads'
initLane = Uniform(*network.lanes)
roads = network.roads

select_road = Uniform(*roads)
select_lane = Uniform(*select_road.lanes)

egoStartPos = Point on select_lane.centerline
egoDestination = follow roadDirection from egoStartPos for 100
require egoDestination in road

behavior EgoBehavior(speed=5):
    do FollowLaneBehavior(speed)

ego =  Car on select_lane.centerline,
    #with behavior DriveTo(egoDestination)
    with behavior FollowLaneBehavior
print("***** : ",ego)

npcStartPos = egoStartPos offset by -3.5 @ 0

npcWP0 = Waypoint at npcStartPos,
    with speed Range(1, 2)
npcWP1 = Waypoint following roadDirection from npcStartPos for 50,
    with speed Range(1, 2)
npcWP2 = Waypoint following roadDirection from egoStartPos for 75,
    with speed Range(1, 2)
npcWP3 = Waypoint following roadDirection from egoStartPos for 100,
    with speed 0
waypoints = [npcWP0, npcWP1, npcWP2, npcWP3]
for waypoint in waypoints:
    print("wp",waypoint)
    #require waypoint in road


Pedestrian on visible intersection.boundary ,
      with regionContainedIn None,
      
      with behavior FollowWaypoints(waypoints)
      #with behavior WalkBehavior(1.4)
      
#Require NPC to be headed approximately the same way as the ego
#require abs(relative heading of npc) <= 20 deg

