#!/usr/bin/env python

import rclpy
import math
import os
import time
import sys
import csv
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler 
from numpy import *
from rclpy.node import Node
import rclpy.qos
from std_msgs.msg import String
from std_msgs.msg import Int32
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from autoware_auto_perception_msgs.msg import DetectedObjects
from rclpy.qos import QoSProfile
from pathlib import Path
from .acquisition_structures import Autoware_Objects
from .acquisition_structures import Objects_GTD


framenum = 0
file_path = ""

class Handler(FileSystemEventHandler): 
    @staticmethod
    def on_any_event(event): 
        if event.is_directory: 
            return None
        elif event.event_type == 'modified': 
            # Event is modified, you can process it now 
            print("File modified with new path - % s." % event.src_path) 
            global file_path
            print("path2:",os.getcwd())
            f_path = open('PolyReports/Validation_report/config.txt', 'r')
            path = f_path.readline()
            file_path = path.strip()
            f_path.close()
            
            with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec" , "timestamp_nanosec" , "available", "verified", "object_label", "position_x", 
                 "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w","linear_x", "linear_y", "linear_z")
                 writer.writerow(autoware_percep_title)
            
            with open(file_path + '/Objects_GTD_Perception.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 objects_title = Objects_GTD("sensor_name","frame_id", "timestamp_sec" ,"timestamp_nanosec","available","object_label","position_x", 
                 "position_y" , "position_z","orientation_x","orientation_y","orientation_z","orientation_w", "linear_x", "linear_y", "linear_z")
                 writer.writerow(objects_title)
  
        
          
                 
class Detection_Subcriber(Node):

    def __init__(self):
        global file_path
        f_path = open('PolyReports/Validation_report/config.txt', 'r')
        path = f_path.readline()
        file_path = path.strip()
        f_path.close()
        print("file path : ",file_path)
        
        # Initiate the Node class's constructor and give it a name
        super().__init__('detetction_subscriber')
          
        qos_profile = QoSProfile(reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
                                            durability=rclpy.qos.DurabilityPolicy.VOLATILE,
                                           history=rclpy.qos.HistoryPolicy.KEEP_LAST,
                                           depth=1)
        
        with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec" , "timestamp_nanosec" , "available", "verified", "object_label", "position_x", 
                 "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w","linear_x", "linear_y", "linear_z")
                 writer.writerow(autoware_percep_title)
            
        with open(file_path + '/Objects_GTD_Perception.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 objects_title = Objects_GTD("sensor_name","frame_id", "timestamp_sec" ,"timestamp_nanosec","available","object_label","position_x", 
                 "position_y" , "position_z","orientation_x","orientation_y","orientation_z","orientation_w", "linear_x", "linear_y", "linear_z")
                 writer.writerow(objects_title)

        self.subscription_1 = self.create_subscription(DetectedObjects,'/perception/object_recognition/detection/objects',self.auto_callback,1)
        self.subscription_2 = self.create_subscription(DetectedObjects,'/awsim/ground_truth/perception/object_recognition/detection/objects',self.sim_callback,qos_profile=qos_profile)
        
        self.subscription_1 # prevent unused variable warning
        self.subscription_2  # prevent unused variable warning
       

                               
    def sim_callback(self, msg):
        global framenum
        global file_path
       # print("sim:",len(msg.objects))
        if len(msg.objects) == 0:   
          print("No vehicle in the LG Scene : ", len(msg.detections)) 
          Gt_objects =  Objects_GTD("lidar", framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, False, False, "no_object", 0.0, 0.0 ,
               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
          with open(file_path + '/Objects_GTD_Perception.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)          
            writer.writerow(Gt_objects)   
         
        if len(msg.objects)  > 0:
            c_lg_bbox = 0
            with open(file_path + '/Objects_GTD_Perception.csv','a', newline='') as csvfile:
              while len(msg.objects)  > 0:
                Sim_objects=Objects_GTD("Object_Sensor",framenum,msg.header.stamp.sec,msg.header.stamp.nanosec,True,
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
                             msg.objects[c_lg_bbox].kinematics.twist_with_covariance.twist.linear.z)
               # print("Detection Node Running.....")
                writer = csv.writer(csvfile)          
                writer.writerow(Sim_objects)
                if len(msg.objects) -1 == c_lg_bbox :   
                    break
                c_lg_bbox = c_lg_bbox + 1
        framenum = framenum+1
       
                   
    def auto_callback(self, msg):   
       global file_path
       global framenum  
       c_autoware_boxes = 0
       autoware_boxes=msg.objects
      # print("auto:",len(msg.objects))
       with open(file_path + '/Autoware_PerceptionData.csv','a', newline='') as csvfile:   
        while len(autoware_boxes) > 0 :  
            writer = csv.writer(csvfile)
            autoware_objects = Autoware_Objects(framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, True, False,
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
                                    msg.objects[c_autoware_boxes].kinematics.twist_with_covariance.twist.linear.z)
            writer.writerow(autoware_objects)
            if len(autoware_boxes)-1 ==  c_autoware_boxes:    
                break
            c_autoware_boxes  =  c_autoware_boxes  + 1
       

def main(args=None):
      
  observer = Observer()
  event_handler = Handler() 
  print("path1:",os.getcwd())
  observer.schedule(event_handler, path='PolyReports/Validation_report/config.txt') 
  if(observer.is_alive()):
      observer.stop()
   
  observer.start()
  print('Checking file modification in background .. ')

 # write curernt pid in file
  home = str(Path.home()) 
  file = open(home+'/adehome/Poly_Suite/per_node_pid','w+')
  self_pid = os.getpid()
   # self_pid = os.getppid()
  s_pid = str(self_pid)  
  file.write(s_pid)
  file.close()
  
  rclpy.init(args=args)  
  detetction_subscriber = Detection_Subcriber()
 # detetction_subscriber.filePath()
  rclpy.spin(detetction_subscriber)
  
  print("Detection Node Started...............")
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
  detetction_subscriber.destroy_node()
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