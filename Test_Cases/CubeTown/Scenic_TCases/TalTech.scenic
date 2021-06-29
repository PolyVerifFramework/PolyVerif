
#SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/CubeTown.xodr')  # or other CARLA map that definitely works
param carla_map = 'CubeTown'
model scenic.domains.driving.model

#																																																		CONSTANTS
SAFETY_DISTANCE = 10
INITIAL_DISTANCE_APART = -10
timestep = 1.0/10
param time_step = timestep
TERMINATE_TIME = 55 / timestep
CAR_POSITION_OFFSET = Range(-0.1,0.1)
EGO_TO_OBSTACLE = Range(-20, -15)

model scenic.core.simulators.Action


x= -50
y= 2
z= 0


#pos = [x,y] @ 1
#pos = 0 @ 0
#position = pos
#viewAngle =56

#start = Point on road   
#ego = Car               #at start

#ego = Car 
#print("start : ",viewAngle,position)
#dist = 1.5

#VectorField("myfield",pos)
#print("",VectorField)

# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.lanes'
initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)

#PLACEMENT
spawnPt = OrientedPoint on initLaneSec.centerline

#p=VectorField.followFrom(pos,*dist)

#obstacle = Car at spawnPt offset by CAR_POSITION_OFFSET @ 1
#print("obs:",obstacle)
ego = Car at spawnPt

#ego = Car following roadDirection from spawnPt for EGO_TO_OBSTACLE

#ego =Car with behavior DriveTo(0 @ 1)

#print("ego :",ego)


terminate when simulation().currentTime > TERMINATE_TIME

