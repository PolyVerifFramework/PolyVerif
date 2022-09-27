param map = localPath('../../tests/formats/opendrive/maps/LGSVL/cubeTown.xodr')
param lgsvl_map = 'cubeTown'
param time_step = 1.0/10

model scenic.domains.driving.model
from scenic.simulators.lgsvl.model import Car

ego = Car
Car