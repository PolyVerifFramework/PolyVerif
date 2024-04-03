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
from std_msgs.msg import Int32
from rclpy.node import Node
from nav_msgs.msg import Odometry
from std_msgs.msg import String
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
file_path = os.getcwd()

class LocalizationValidation(Node):
    
    def __init__(self):
       super().__init__('localization_validation')
          
       self.subNdtPose  = self.create_subscription(PoseWithCovarianceStamped,'/localization/pose_with_covariance',self.ndt_pose_callback,1)
       self.subGnssOdm = self.create_subscription(PoseWithCovarianceStamped,'/sensing/gnss/pose_with_covariance',self.gnss_callback,1)
      
       self.subNdtPose # prevent unused variable warning
       self.subGnssOdm # prevent unused variable warning

    def filePath(self):
       global file_path 
       
       f_path = open('PolyReports/config.txt', 'r')
       path = f_path.readline()
       file_path = path.strip()
       f_path.close()

       csv_gnss = open(file_path + "/GNSS_Localization.csv", "w")
       csv_gnss_write = csv.writer(csv_gnss)
       fields = ["frame_id", "child_frame_id", "timestamp_sec" ,"timestamp_nanosec", "position_x", 
            "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w"]
       csv_gnss_write .writerow(fields)
       csv_gnss.close()

       csv_ndt = open(file_path + "/NDT_Pose_Localization.csv", "w")
       csv_ndt_write = csv.writer(csv_ndt)
       field_pose=["frame_id","timestamp_sec" , "timestamp_nanosec" ,"position_x",
            "position_y", "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w"]
       csv_ndt_write.writerow(field_pose)
       csv_ndt.close()
       
    def gnss_callback(self, msg):
      
        csv_gnss = open(file_path +"/GNSS_Localization.csv", "a")
        csv_gnss_write = csv.writer(csv_gnss)
        Gnss_data=[msg.header.frame_id, "-", msg.header.stamp.sec, msg.header.stamp.nanosec,
        msg.pose.pose.position.x,msg.pose.pose.position.y, msg.pose.pose.position.z,
        msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, 
        msg.pose.pose.orientation.w]
        print("Localization Node Running.....")
        csv_gnss_write.writerow(Gnss_data)
        csv_gnss.close()

    def ndt_pose_callback(self,msg):
      
        csv_pose = open(file_path +"/NDT_Pose_Localization.csv", "a")
        csv_pose_write = csv.writer(csv_pose)
        ndt_pose=[msg.header.frame_id, msg.header.stamp.sec, msg.header.stamp.nanosec, 
        msg.pose.pose.position.x,msg.pose.pose.position.y,msg.pose.pose.position.z,
        msg.pose.pose.orientation.x,msg.pose.pose.orientation.y,msg.pose.pose.orientation.z,msg.pose.pose.orientation.w]
        csv_pose_write.writerow(ndt_pose)
        csv_pose.close() 

def main(args=None):

    rclpy.init(args=args)
   
    localization_validation = LocalizationValidation()
    localization_validation.filePath()

    rclpy.spin(localization_validation)
    print("Localization Node Started...............")
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    localization_validation.destroy_node()
    rclpy.shutdown()


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