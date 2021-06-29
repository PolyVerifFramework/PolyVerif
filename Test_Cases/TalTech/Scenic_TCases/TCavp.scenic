
#SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/CubeTown.xodr')  # or other CARLA map that definitely works
param carla_map = 'CubeTown'
model scenic.domains.driving.model

#CONSTANTS
SAFETY_DISTANCE = 10
INITIAL_DISTANCE_APART = -10
timestep = 1.0/10
param time_step = timestep
TERMINATE_TIME = 45 / timestep
CAR_POSITION_OFFSET = Range(-0.5,0.5)
EGO_TO_OBSTACLE = Range(-20, -15)



ego = Car 

# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.lanes'
initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)

#PLACEMENT
spawnPt = OrientedPoint on initLaneSec.centerline

obstacle = Car at spawnPt offset by CAR_POSITION_OFFSET @ 1

ego = Car following roadDirection from spawnPt for EGO_TO_OBSTACLE



terminate when simulation().currentTime > TERMINATE_TIME


