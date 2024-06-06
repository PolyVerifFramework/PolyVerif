#!/usr/bin/env python
import os
import time
import sys
import json
import csv
import rclpy
import math
from pathlib import Path
from numpy import *
import numpy as np 
from std_msgs.msg import Int32
from rclpy.node import Node
from nav_msgs.msg import Odometry
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from .acquisition_structures import GNSS_Odom
from .acquisition_structures import PathPlanner_GoalPose
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler 

file_path = ""
framenum = 0

class Handler(FileSystemEventHandler): 
    @staticmethod
    def on_any_event(event): 
        if event.is_directory: 
            return None
        elif event.event_type == 'modified': 
            print("File modified with new path - % s." % event.src_path) 
            global file_path
            f_path = open('PolyReports/Validation_report/config.txt', 'r')
            path = f_path.readline()
            file_path = path.strip()
            f_path.close()

            with open(file_path + '/GNSS_ODOM_Localization.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 gnss_odom = GNSS_Odom("frame_id", "child_frame_id", "timestamp_sec" ,"timestamp_nanosec", "position_x", "position_y" ,
                 "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w")
                 writer.writerow(gnss_odom)

            with open(file_path + '/Goal_Pose_PathPlanning.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 pathplanner_GoalPose= PathPlanner_GoalPose("frame_id","timestamp_sec" , "timestamp_nanosec" ,"position_x", "position_y",
                 "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w")
                 writer.writerow(pathplanner_GoalPose)

class PathPlannerValidation(Node):
    
    def __init__(self):
       global file_path
       f_path = open('PolyReports/Validation_report/config.txt', 'r')
       path = f_path.readline()
       file_path = path.strip()
       f_path.close()
       
       super().__init__('path_planner_validation')
       
       with open(file_path + '/GNSS_ODOM_Localization.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         gnss_odom = GNSS_Odom("frame_id", "child_frame_id", "timestamp_sec" ,"timestamp_nanosec", "position_x", 
         "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w")
         writer.writerow(gnss_odom)

       with open(file_path + '/Goal_Pose_PathPlanning.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         pathplanner_GoalPose= PathPlanner_GoalPose("frame_id","timestamp_sec" , "timestamp_nanosec" ,"position_x",
         "position_y", "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w")
         writer.writerow(pathplanner_GoalPose)
          
       self.subGoalPos = self.create_subscription(PoseStamped,'/planning/mission_planning/goal',self.goal_pose_callback,1)
       self.subGnssOdm = self.create_subscription(PoseWithCovarianceStamped,'/sensing/gnss/pose_with_covariance',self.gnss_callback,1)
       
       self.subGoalPos # prevent unused variable warning
       self.subGnssOdm # prevent unused variable warning


       
    def gnss_callback(self, msg):
        global file_path
         
        with open(file_path + '/GNSS_ODOM_Localization.csv','a', newline='') as csvfile:
         writer = csv.writer(csvfile)
         Gnss_data=GNSS_Odom(msg.header.frame_id, "child_frame_id", msg.header.stamp.sec, msg.header.stamp.nanosec,
         msg.pose.pose.position.x,msg.pose.pose.position.y, msg.pose.pose.position.z,
         msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w)
         writer.writerow(Gnss_data)
      

    def goal_pose_callback(self,msg):
        global file_path
        with open(file_path + '/Goal_Pose_PathPlanning.csv','a', newline='') as csvfile:
            
         writer = csv.writer(csvfile)        
         goal_pose=PathPlanner_GoalPose(msg.header.frame_id, msg.header.stamp.sec, msg.header.stamp.nanosec, 
         msg.pose.position.x,msg.pose.position.y,msg.pose.position.z,
         msg.pose.orientation.x,msg.pose.orientation.y,msg.pose.orientation.z,msg.pose.orientation.w)
         writer.writerow(goal_pose)
        

def main(args=None):
  
  observer = Observer()
  event_handler = Handler() 
  observer.schedule(event_handler, path='PolyReports/Validation_report/config.txt') 
  if(observer.is_alive()):
      observer.stop()
      
  observer.start()
  print('Checking file modification in background .. ')


# write curernt pid in file
  home = str(Path.home())
  file = open(home+'/adehome/Poly_Suite/per_node_pid','w+')
  self_pid = os.getpid()
  s_pid = str(self_pid)
  file.write(s_pid)
  file.close()
  
  rclpy.init(args=args)
  path_planner_validation= PathPlannerValidation()
  print("Planner Node Started...............")
  rclpy.spin(path_planner_validation)
  
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
  path_planner_validation.destroy_node()
    
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
  observer.join() 

if __name__ == '__main__':
    try:
      main()
      
    except KeyboardInterrupt:
       rclpy.loginfo("Cancelled by user")
    except rclpy.ROSInterruptException:
       pass
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')
    finally:
        rclpy.loginfo("Done")
