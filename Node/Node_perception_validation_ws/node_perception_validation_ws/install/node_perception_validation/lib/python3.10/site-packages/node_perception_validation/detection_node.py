#!/usr/bin/env python

import rclpy
import math
import os
import time
import sys
import csv
from numpy import *
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int32
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from autoware_auto_perception_msgs.msg import DetectedObjects
from rclpy.qos import qos_profile_sensor_data, QoSProfile


framenum = 0
file_path = os.getcwd()

class Detection_Subcriber(Node):

    def __init__(self):
        super().__init__('detetction_subscriber')
        qos_profile = QoSProfile(reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
                                          history=rclpy.qos.HistoryPolicy.KEEP_LAST,
                                          depth=1)


        self.subdectauto = self.create_subscription(DetectedObjects,'/perception/object_recognition/detection/objects',self.auto_callback,1)
        self.subdectsim = self.create_subscription(DetectedObjects,'/awsim/ground_truth/perception/object_recognition/detection/objects',self.sim_callback,qos_profile=qos_profile)
        self.subdectsim  # prevent unused variable warning
        self.subdectauto # prevent unused variable warning

    def filePath(self):
        
       global file_path 
       print("CurrDir:",file_path)
       f_path = open('PolyReports/config.txt', 'r')
       path = f_path.readline()
       file_path = path.strip()
       f_path.close() 
       
       with open(file_path + '/Objects_GTD_Perception.csv','w', newline='') as csvfile:
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
              
                 
    def sim_callback(self, msg):
        global framenum
        msgLen=0
        msgLen=len(msg.objects)
          
        if msgLen==0:   
          Gt_objects=["Object_Sensor",framenum,msg.header.stamp.sec, msg.header.stamp.nanosec,False,False,"no_object",
            0.0,0.0,0.0, 0.0, 0.0,0.0, 0.0]
          with open(file_path + '/Objects_GTD_Perception.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)          
            writer.writerow(Gt_objects)
         
        if msgLen > 0:
            c_lg_bbox = 0
            with open(file_path + '/Objects_GTD_Perception.csv','a', newline='') as csvfile:
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
                print("Detection Node Running.....")
                writer = csv.writer(csvfile)          
                writer.writerow(Gt_objects)
                if msgLen-1 == c_lg_bbox :   
                    break
                c_lg_bbox = c_lg_bbox + 1
        framenum = framenum+1
       
        
        
  
    def auto_callback(self, msg):   
       global file_path
       global framenum  
       c_autoware_boxes = 0
       autoware_boxes=msg.objects
       
       with open(file_path + '/Autoware_PerceptionData.csv','a', newline='') as csvfile:   
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
       

def main(args=None):
    rclpy.init(args=args)

    detetction_subscriber = Detection_Subcriber()
    detetction_subscriber.filePath()
    
    rclpy.spin(detetction_subscriber)
    print("Detection Node Started...............")
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    detetction_subscriber.destroy_node()
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