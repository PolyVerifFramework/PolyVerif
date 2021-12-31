
#SET MAP AND MODEL (i.e. definitions of all referenceable vehicle types, road library, etc)
param map = localPath('maps/TalTech.xodr')  # or other CARLA map that definitely works
param carla_map = 'TalTech'
model scenic.domains.driving.model

#CONSTANTS
SAFETY_DISTANCE = 10
INITIAL_DISTANCE_APART = -10
timestep = 1.0/10
param time_step = timestep
TERMINATE_TIME = 55 / timestep
CAR_POSITION_OFFSET = Range(0,0)
EGO_TO_OBSTACLE = Range(-20, -15)


#Car offset by Range(-10, 10) @ Range(20, 40)
#VectorField("myfield",pos)
#print("",VectorField)


behavior EgoBehavior(speed=10):
    do FollowLaneBehavior(speed)


# make sure to put '*' to uniformly randomly select from all elements of the list, 'network.lanes'
initLane = Uniform(*network.lanes)
initLaneSec = Uniform(*initLane.sections)

#PLACEMENT
spawnPt = OrientedPoint on initLaneSec.centerline
ego = Car
ego = Car at spawnPt, 
      with behavior EgoBehavior()

#pos = x @ y#(x,y) 


#ego = AutowareEgoCar
#obstacle = AutowareCar
#obstacle = NPCCar
#obstacle = LGSVLObject

#print("NCP : ",ego.getProperties)


'''
class Car:
    position: Point on road
    heading: roadDirection at self.position
    width: self.model.width
    height: self.model.height
   # model:  scenic.domains.driving.model
'''

#p=VectorField.followFrom(pos,*dist)
#start = Point on road  
#ego = Car at spawnPt #offset by CAR_POSITION_OFFSET @ 0

#spot = OrientedPoint on visible curb
#Car left of spot by 0.25

#Region.orient(vec)
print("val :",OrientedPoint,visible curb)


#ego = Car at start 

#Start = Point on

terminate when simulation().currentTime > TERMINATE_TIME

