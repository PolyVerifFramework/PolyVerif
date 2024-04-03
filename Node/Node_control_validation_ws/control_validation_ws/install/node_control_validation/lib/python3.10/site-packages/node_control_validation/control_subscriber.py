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
from autoware_auto_perception_msgs.msg import DetectedObjects
from autoware_auto_vehicle_msgs.msg import VelocityReport
from autoware_auto_control_msgs.msg import AckermannControlCommand
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from rclpy.qos import qos_profile_sensor_data, QoSProfile
file_path = ""

framenum = 0
file_path = os.getcwd()

class Control_Subcriber(Node):
    
    def __init__(self):
       super().__init__('control_subscriber')
       qos_profile = QoSProfile(reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
                                          history=rclpy.qos.HistoryPolicy.KEEP_LAST,
                                          depth=1)
         
       self.subdectauto = self.create_subscription(DetectedObjects,'/perception/object_recognition/detection/objects',self.auto_callback,1)
       self.subDete = self.create_subscription(DetectedObjects,'/awsim/ground_truth/perception/object_recognition/detection/objects',self.sim_callback,qos_profile=qos_profile)     
      
       self.subStatus = self.create_subscription(VelocityReport,'/vehicle/status/velocity_status',self.status_callback,1)
       #self.subStatus = self.create_subscription(AckermannControlCommand,'/control/command/control_cmd',self.can_callback,1)
       self.subDete # prevent unused variable warning
       self.subdectauto # prevent unused variable warning

    def filePath(self):
       global file_path 
       f_path = open('PolyReports/config.txt', 'r')
       path = f_path.readline()
       file_path = path.strip()
       f_path.close()

       with open(file_path + '/Objects_GTD.csv','w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        objects_title =["sensor_name","frame_id", "timestamp_sec" ,"timestamp_nanosec","available","verified", "object_label","position_x", 
            "position_y" , "position_z","orientation_x","orientation_y","orientation_z","orientation_w", "linear_x", "linear_y", "linear_z"]
        writer.writerow(objects_title)
        csvfile.close()
        
       with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        autoware_percep_title = ["frame_id","timestamp_sec","timestamp_nanosec","available","verified","object_label","position_x", 
            "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w","linear_x", "linear_y", "linear_z"]
        writer.writerow(autoware_percep_title)
        csvfile.close()
        
        with open(file_path + '/Ego_CanData.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         can_title =["frame_id", "timestamp_sec" ,"timestamp_nanosec","longitudinal_velocity","lateral_velocity","heading_rate"]
         writer.writerow(can_title)
         csvfile.close()
       
        # with open(file_path + '/Ego_CanData.csv','w', newline='') as csvfile:
        #  writer = csv.writer(csvfile)
        #  objects_title = Ego_CanData("frame_id", "timestamp_sec" ,"timestamp_nanosec", "available", "verified","Speed","Throttle","Braking","Steering","Parking_Brake_Status",
        #  "High_Beam_Status","Low_Beam_Status","Hazard_Light_Status","Fog_Light_Status","Left_Turn_Signal_Status",
        #  "Right_Turn_Signal_Status","Wiper_Status","Reverse_Gear_Status","Selected_Gear","Engine_Status",
        #  "Engine_RPM","GPS_Latitude","GPS_Longitude","Altitude","orientation_x", "orientation_y", "orientation_z", "orientation_w",
        #  "velocity_x", "velocity_y", "velocity_z")
        #  writer.writerow(objects_title)
       
    def sim_callback(self, msg):
       # print("linear_vel:",msg)
        #print("linear_vel:",msg.objects[0].kinematics.twist_with_covariance.twist.linear.x)
        global framenum
        msgLen=0
        msgLen=len(msg.objects)
       
       
        if msgLen==0:   
          Gt_objects=["Object_Sensor",framenum,msg.header.stamp.sec, msg.header.stamp.nanosec,False,False,"no_object",
            0.0,0.0,0.0, 0.0, 0.0,0.0, 0.0]
          with open(file_path + '/Objects_GTD.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)          
            writer.writerow(Gt_objects) 
        if msgLen > 0:
            c_lg_bbox = 0
            with open(file_path + '/Objects_GTD.csv','a', newline='') as csvfile:
              while msgLen > 0:
               
                Gt_objects=["Object_Sensor",framenum,msg.header.stamp.sec,msg.header.stamp.nanosec,True,False,
                             msg.objects[c_lg_bbox].classification[0].label,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.position.x,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.position.y,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.position.z,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.orientation.x,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.orientation.y,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.orientation.z,
                             msg.objects[c_lg_bbox].kinematics.pose_with_covariance.pose.orientation.w,
                             msg.objects[c_lg_bbox].kinematics.twist_with_covariance.twist.linear.x,
                             msg.objects[c_lg_bbox].kinematics.twist_with_covariance.twist.linear.y,
                             msg.objects[c_lg_bbox].kinematics.twist_with_covariance.twist.linear.z]
                print("Control Node Running.....")
                writer = csv.writer(csvfile)          
                writer.writerow(Gt_objects)
                if msgLen-1 == c_lg_bbox :
                    #print("GT_b:",msgLen-1,c_lg_bbox)   
                    break
                #print("GT_len:",msgLen-1,c_lg_bbox)
                c_lg_bbox = c_lg_bbox + 1
        framenum = framenum+1
        
        
    def auto_callback(self, msg):
       global file_path
       global framenum
       
       c_autoware_boxes = 0
       autoware_boxes=msg.objects
       with open(file_path + '/Autoware_PerceptionData.csv','a', newline='') as csvfile:
       # print("autoLen:",len(autoware_boxes)) 
       
        while len(autoware_boxes) > 0 :
            
            writer = csv.writer(csvfile)
            autoware_percep_data = [framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, True, False,
                                    msg.objects[c_autoware_boxes ].classification[0].label, 
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.position.x,
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.position.y,
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.position.z,
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.orientation.x,
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.orientation.y,
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.orientation.z,
                                    msg.objects[c_autoware_boxes].kinematics.pose_with_covariance.pose.orientation.w,
                                    msg.objects[c_autoware_boxes].kinematics.twist_with_covariance.twist.linear.x,
                                    msg.objects[c_autoware_boxes].kinematics.twist_with_covariance.twist.linear.y,
                                    msg.objects[c_autoware_boxes].kinematics.twist_with_covariance.twist.linear.z]
            writer.writerow(autoware_percep_data)
            if len(autoware_boxes)-1 ==  c_autoware_boxes:    
                break
            c_autoware_boxes  =  c_autoware_boxes  + 1
            
    # def can_callback(self, msg):
    #     print("csd")
    #     with open(file_path + '/Ego_CanData.csv','a', newline='') as csvfile:
    #      writer = csv.writer(csvfile)   
    #      vel_data=[msg.stamp.sec,msg.stamp.nanosec,
    #                msg.longitudinal_velocity,msg.lateral_velocity,msg.heading_rate]
    #      writer.writerow(vel_data)  
    
    def status_callback(self, msg):
        #print("status:",msg.longitudinal_velocity) 
        with open(file_path + '/Ego_CanData.csv','a', newline='') as csvfile:
         writer = csv.writer(csvfile)   
         vel_data=[msg.header.frame_id,msg.header.stamp.sec,msg.header.stamp.nanosec,
                   msg.longitudinal_velocity,msg.lateral_velocity,msg.heading_rate]
         writer.writerow(vel_data)  
    

def main(args=None):

    rclpy.init(args=args)
   
    control_subscriber = Control_Subcriber()
    control_subscriber.filePath()

    rclpy.spin(control_subscriber )
    print("Control Node Started...............")
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    control_subscriber.destroy_node()
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

