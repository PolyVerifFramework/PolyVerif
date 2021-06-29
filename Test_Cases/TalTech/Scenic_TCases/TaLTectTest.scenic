
param map = localPath('maps/cubetown.xodr')
param lgsvl_map = 'CubeTown'
timestep = 1.0/10
param time_step = timestep

model scenic.simulators.lgsvl.model
timestep = 1.0/10
param time_step = timestep
TERMINATE_TIME = 10 / timestep
EGO_TO_OBSTACLE = Range(80, 75)


x= 200
y= 0
z= 0

pos = [x,y] @ 1
position = pos
#viewAngle =56


VectorField("myfield",pos)

initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)

#PLACEMENT
spawnPt = OrientedPoint on initLaneSec.centerline
ego = Car following roadDirection from spawnPt for EGO_TO_OBSTACLE
#ego = Car at position


terminate when simulation().currentTime > TERMINATE_TIME
