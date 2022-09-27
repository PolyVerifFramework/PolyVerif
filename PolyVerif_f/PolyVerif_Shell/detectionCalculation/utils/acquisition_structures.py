# -*- coding: utf-8 -*-
"""
Created on Thu Feb 18 15:49:46 2021

@author:
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

# Structure to get initial params    
class InitialConfig(NamedTuple):
    fps          : int
    object_num   : int

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
    sensor_name         : str
    frame_id            : int
    timestamp_sec       : int
    timestamp_nanosec   : int
    available           : bool
    verified            : bool
    label               : str
    position_x          : float
    position_y          : float
    position_z          : float
    size_x              : float
    size_y              : float
    size_z              : float
    orientation_x       : float
    orientation_y       : float
    orientation_z       : float
    orientation_w       : float
    linear_velocity_x   : float
    linear_velocity_y   : float
    linear_velocity_z   : float
    angular_velocity_x  : float
    angular_velocity_y  : float
    angular_velocity_z  : float

# Structure for Ego Vehicle, data recieved from Can Bus 
class Ego_CanData(NamedTuple):
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
    velocity_x           : float
    velocity_y           : float
    velocity_z           : float

# Structure for Autiware perceptionoutput data
class Autoware_Objects(NamedTuple):
    frame_id          : int
    timestamp_sec     : int
    timestamp_nanosec : int
    available         : bool
    verified          : bool
    vehicle_label     : float
    signal_label      : float
    class_likelihood  : float
    centroid_x        : float
    centroid_y        : float
    centroid_z        : float
    size_x            : float
    size_y            : float
    size_z            : float
    corner_1_x        : float
    corner_1_y        : float
    corner_1_z        : float   
    corner_2_x        : float
    corner_2_y        : float
    corner_2_z        : float
    corner_3_x        : float
    corner_3_y        : float
    corner_3_z        : float
    corner_4_x        : float
    corner_4_y        : float
    corner_4_z        : float
    orientation_x      : float
    orientation_y      : float
    orientation_z      : float
    orientation_w      : float
    velocity           : float
    heading            : float
    heading_rate       : float
    value              : float
    
#structure to capture object matching data
class  Objects_Report(NamedTuple):
    timestamp_sec       : int
    timestamp_nanosec   : int
    label               : str
    position_x          : float
    position_y          : float
    position_z          : float
    size_x              : float
    size_y              : float
    size_z              : float
    match_found         : bool

class Control_Val_Report(NamedTuple):
    timestamp_sec       : int
    timestamp_nanosec   : int
    label               : str
    position_x          : float
    position_y          : float
    position_z          : float
    size_x              : float
    size_y              : float
    size_z              : float
    ttc_val             : float
    brake_state         : int
    accel_deaccel_rate  : float
    
class DetectionRangeReport_Multi(NamedTuple):
    Range               : str
    SuccessRate         : float 

