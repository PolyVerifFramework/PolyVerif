# -*- coding: utf-8 -*-
"""
Created on Mon Mar 18 15:49:46 2024

@author: Acclivis Technologies Pvt Ltd.
"""
from typing import NamedTuple

# Structure 
class User(NamedTuple):
    name: str
    
# Test Structure
class MyStruct(NamedTuple):
    foo: str
    bar: int
    baz: list
    qux: User

# Structure for lidar data
class Lidar(NamedTuple):
    name         : str
    frame_id     : int
    timestamp    : int
    available    : bool
    verified     : bool
    rawdata      : list
      
# Structure for camera data
class Camera(NamedTuple):
    name         : str
    frame_id     : int
    timestamp    : int
    available    : bool
    verified     : bool
    rawdata      : list

# Structure for radar data
class Radar(NamedTuple):
    name         : str
    frame_id     : int
    timestamp    : int
    available    : bool
    verified     : bool
    rawdata      : list

# Structure for object's ground truth data
class Objects_GTD(NamedTuple):
    sensor_name       : str
    frame_id          : int
    timestamp_sec     : int
    timestamp_nanosec : int
    available         : bool
    object_label      : int
    position_x        : float
    position_y        : float
    position_z        : float
    orientation_x     : float
    orientation_y     : float
    orientation_z     : float
    orientation_w     : float
    linear_x          : float
    linear_y          : float
    linear_z          : float
    

# Structure for Ego Vehicle, data recieved from Can Bus 
class Ego_CanData(NamedTuple):
    frame_id                : int
    timestamp_sec           : int
    timestamp_nanosec       : int
    longitudinal_velocity   : float
    lateral_velocity        : float
    heading_rate            : float
   
    
# Structure for Autoware perceptionoutput data
class Autoware_Objects(NamedTuple):
    frame_id          : int
    timestamp_sec     : int
    timestamp_nanosec : int
    available         : bool
    verified          : bool
    object_label      : int
    position_x        : float
    position_y        : float
    position_z        : float
    orientation_x     : float
    orientation_y     : float
    orientation_z     : float
    orientation_w     : float
    linear_x          : float
    linear_y          : float
    linear_z          : float

# Structure for Autoware localization ndt data
class PathPlanner_GoalPose(NamedTuple):
	frame_id           : str
	timestamp_sec      : int
	timestamp_nanosec  : int
	position_x         : float
	position_y         : float
	position_z         : float
	orientation_x      : float
	orientation_y      : float
	orientation_z      : float
	orientation_w      : float

# Structure for localization GNSS data
class GNSS_Odom(NamedTuple):
	frame_id          : str
	child_frame_id    : str
	timestamp_sec     : int
	timestamp_nanosec : int
	position_x        : float
	position_y        : float
	position_z        : float
	orientation_x     : float
	orientation_y     : float
	orientation_z     : float
	orientation_w     : float
 
 # Structure for Autoware localization ndt data
class Localization_Ndt(NamedTuple):
	frame_id          : str
	timestamp_sec     : int
	timestamp_nanosec : int
	position_x        : float
	position_y        : float
	position_z        : float
	orientation_x     : float
	orientation_y     : float
	orientation_z     : float
	orientation_w     : float

