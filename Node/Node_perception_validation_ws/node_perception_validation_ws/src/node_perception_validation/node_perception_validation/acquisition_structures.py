# -*- coding: utf-8 -*-
"""
Created on Thu Feb 18 15:49:46 2021

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
    frame_id          :int
    timestamp_sec     : int
    timestamp_nanosec : int
    available         : bool
    object_label : int
    position_x : float
    position_y : float
    position_z   : float
    orientation_x   : float
    orientation_y   : float
    orientation_z   : float
    orientation_w   : float
    linear_x       : float
    linear_y       : float
    linear_z       : float
    

# Structure for Ego Vehicle, data recieved from Can Bus 
class Ego_CanData(NamedTuple):
    frame_id     : int
    timestamp_sec     : int
    timestamp_nanosec : int
    available    : bool
    verified     : bool
    speed                : float
    throttle             : float
    braking              : float
    steering             : float
    parking_brake_status : bool
    high_beam_status     : bool
    low_beam_status      : bool
    hazard_light_status  : bool
    fog_light_status     : bool
    left_turn_signal_status  : bool
    right_turn_signal_status : bool
    wiper_status         : bool
    reverse_gear_status  : bool
    selected_gear        : int
    engine_status        : bool
    engine_rpm           : int
    gps_latitude         : float
    gps_longitude        : float
    altitude             : int
    orientation_x        : float
    orientation_y        : float
    orientation_z        : float
    orientation_w        : float
    velocity_x           : float
    velocity_y           : float
    velocity_z           : float
    
# Structure for Autoware perceptionoutput data
class Autoware_Objects(NamedTuple):
    frame_id     : int
    timestamp_sec     : int
    timestamp_nanosec : int
    available    : bool
    verified     : bool
    object_label : int
    position_x : float
    position_y : float
    position_z   : float
    orientation_x   : float
    orientation_y   : float
    orientation_z   : float
    orientation_w   : float
    linear_x       : float
    linear_y       : float
    linear_z       : float





