# -*- coding: utf-8 -*-
"""
Created on Thu Feb 18 16:05:14 2021

@author: Acclivis Technologies Pvt Ltd.
"""

import os
import sys
import csv  

from utils.acquisition_structures import Lidar
from utils.acquisition_structures import Camera
from utils.acquisition_structures import User
from utils.acquisition_structures import Objects_GTD

#lid = Lidar("Sensor Name", 0, {1,2,3,4}, "Data Availability", "Data Validated","raw data")

with open('script/validation_report/Objects_GTD.csv','w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    objects_title = Objects_GTD("sensor_name", "frame_id", "timestamp_sec" ,"timestamp_nanosec", "available", "verified", "label", "position_x", "position_y" ,
          "position_z", "size_x", "size_y", "size_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w",
          "linear_velocity_x", "linear_velocity_y", "linear_velocity_z", "angular_velocity_x", "angular_velocity_y", "angular_velocity_z")
    writer.writerow(objects_title)


objects = Objects_GTD("lidar", framenum, lg_gt_stamp, lg_gt_nanosec, False, False, "no_object", 0.0, 0.0 ,
               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
         #print(objects)
for x in range(6):
    with open('script/validation_report/Objects_GTD.csv','a', newline='') as csvfile:
        writer = csv.writer(csvfile)          
        writer.writerow(objects)



