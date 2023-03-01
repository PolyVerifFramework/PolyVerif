param map = localPath('maps/CubeTown.xodr')
param lgsvl_map = 'CubeTown'
param time_step = 1.0/10

from scenic.simulators.lgsvl.model import *


ego = Car with behavior FollowLaneBehavior()
c2 = Car offset by Range(-10, 10) @ Range(20, 40), with viewAngle 30 deg
c3 = Car at c2 offset by Range(-10, 10) @ 0, with viewAngle 30 deg,with behavior FollowLaneBehavior()
require c2 can see ego
require c3 can see ego