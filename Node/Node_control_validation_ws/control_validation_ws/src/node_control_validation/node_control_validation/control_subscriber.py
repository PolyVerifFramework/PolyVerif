#!/usr/bin/env python

import os
import time
import sys
import json
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
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler 
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from rclpy.qos import qos_profile_sensor_data, QoSProfile
import csv
from pathlib import Path
from .acquisition_structures import Objects_GTD
from .acquisition_structures import Ego_CanData
from .acquisition_structures import Autoware_Objects
file_path = ""

framenum = 0
file_path = os.getcwd()


class Handler(FileSystemEventHandler): 
    @staticmethod
    def on_any_event(event): 
        if event.is_directory: 
            return None
        elif event.event_type == 'modified': 
            # Event is modified, you can process it now 
            print("File modified with new path - % s." % event.src_path) 
            global file_path
            f_path = open('PolyReports/Validation_report/config.txt', 'r')
            path = f_path.readline()
            file_path = path.strip()
            f_path.close()

            #print("New File Writing : ",file_path)
            with open(file_path + '/Objects_GTD.csv','w', newline='') as csvfile:
                writer = csv.writer(csvfile)
                objects_title = Objects_GTD("sensor_name","frame_id", "timestamp_sec" ,"timestamp_nanosec","available","object_label","position_x", 
                "position_y" , "position_z","orientation_x","orientation_y","orientation_z","orientation_w", "linear_x", "linear_y", "linear_z")
                writer.writerow(objects_title)

            with open(file_path + '/Ego_CanData.csv','w', newline='') as csvfile:
                writer = csv.writer(csvfile)
                objects_title = Ego_CanData("frame_id", "timestamp_sec" ,"timestamp_nanosec","longitudinal_velocity","lateral_velocity","heading_rate")
                writer.writerow(objects_title)     
                        
            with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
                writer = csv.writer(csvfile)
                autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec","timestamp_nanosec","available","verified","object_label","position_x", 
                "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w","linear_x", "linear_y", "linear_z")
                writer.writerow(autoware_percep_title)

class Control_Subcriber(Node):

    print("file path : ",file_path)   
    def __init__(self):
        
       global file_path
       f_path = open('PolyReports/Validation_report/config.txt', 'r')
       path = f_path.readline()
       file_path = path.strip()
       f_path.close()
       
       super().__init__('control_subscriber')
       
       with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec","timestamp_nanosec","available","verified","object_label","position_x", 
        "position_y" , "position_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w","linear_x", "linear_y", "linear_z")
        writer.writerow(autoware_percep_title)
        
       with open(file_path + '/Ego_CanData.csv','w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        objects_title = Ego_CanData("frame_id", "timestamp_sec" ,"timestamp_nanosec","longitudinal_velocity","lateral_velocity","heading_rate")
        writer.writerow(objects_title)     
        
       with open(file_path + '/Objects_GTD.csv','w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        objects_title = Objects_GTD("sensor_name","frame_id", "timestamp_sec" ,"timestamp_nanosec","available", "object_label","position_x", 
        "position_y" , "position_z","orientation_x","orientation_y","orientation_z","orientation_w", "linear_x", "linear_y", "linear_z")
        writer.writerow(objects_title)                    
    
       qos_profile = QoSProfile(reliability=rclpy.qos.ReliabilityPolicy.BEST_EFFORT,
                                          history=rclpy.qos.HistoryPolicy.KEEP_LAST,
                                          depth=1)
         
       self.sub1 = self.create_subscription(DetectedObjects,'/perception/object_recognition/detection/objects',self.auto_callback,1)
       self.sub2 = self.create_subscription(DetectedObjects,'/awsim/ground_truth/perception/object_recognition/detection/objects',self.sim_callback,qos_profile=qos_profile)     
      
       self.sub3 = self.create_subscription(VelocityReport,'/vehicle/status/velocity_status',self.status_callback,1)
       #self.subStatus = self.create_subscription(AckermannControlCommand,'/control/command/control_cmd',self.can_callback,1)
       
       self.sub1 # prevent unused variable warning
       self.sub2 # prevent unused variable warning
       self.sub3 # prevent unused variable warning

       
       
    def sim_callback(self, msg):
        global framenum
        global file_path
       # print("sim:",len(msg.objects))
        if len(msg.objects) == 0:   
          print("No vehicle in the LG Scene : ", len(msg.detections)) 
          Sim_objects =  Objects_GTD("Object_Sensor", framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, False, "no_object", 0.0, 0.0 ,
            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
          with open(file_path + '/Objects_GTD.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)          
            writer.writerow(Sim_objects)   
         
        if len(msg.objects)  > 0:
            c_lg_bbox = 0
            with open(file_path + '/Objects_GTD.csv','a', newline='') as csvfile:
              while len(msg.objects)  > 0:
                Sim_objects=  Objects_GTD("Object_Sensor",framenum,msg.header.stamp.sec,msg.header.stamp.nanosec,True,
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
       
  
    
    def status_callback(self, msg):     
        with open(file_path + '/Ego_CanData.csv','a', newline='') as csvfile:
         writer = csv.writer(csvfile)
         ego_Data = Ego_CanData(msg.header.frame_id,msg.header.stamp.sec,msg.header.stamp.nanosec,
                   msg.longitudinal_velocity,msg.lateral_velocity,msg.heading_rate)
         writer.writerow(ego_Data) 
    

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
    file = open(home+'/adehome/Poly_Suite/per_node_pid','w+');
    self_pid = os.getpid()
    s_pid = str(self_pid)
    file.write(s_pid)
    file.close()

    rclpy.init(args=args)
   
    control_subscriber = Control_Subcriber()
   # control_subscriber.filePath()

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

