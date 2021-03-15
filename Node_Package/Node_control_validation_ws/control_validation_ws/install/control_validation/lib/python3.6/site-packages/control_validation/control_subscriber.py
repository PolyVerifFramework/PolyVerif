import rclpy # Import the ROS client library for Python
from rclpy.node import Node # Enables the use of rclpy's Node class
from std_msgs.msg import Float64MultiArray # Enable use of the std_msgs/Float64MultiArray message type
from lgsvl_msgs.msg import CanBusData
from lgsvl_msgs.msg import Detection3DArray
from autoware_auto_msgs.msg import BoundingBoxArray
import numpy as np # NumPy Python library
from scipy.spatial import ConvexHull
import cmath
from scipy.spatial import distance
import matplotlib.pyplot as plt 

import csv
from .acquisition_structures import Objects_GTD
from .acquisition_structures import Ego_CanData
from .acquisition_structures import Autoware_Objects

from numpy import *
l_vehicle_speed = []
l_brake = []
lgstamp = 0
autostamp = 0
ego_vehicle_speed = 0.0
ego_linear_velocities = 0.0
ego_brake_pct = 0
framenum = 0
#autoware_boxes = BoundingBoxArray.boxes
class ControlValidation(Node):

  def __init__(self):
    """
    Class constructor to set up the node
    """
   
    # Initiate the Node class's constructor and give it a name
    super().__init__('control_validation')

    
    with open('script/validation_report/Objects_GTD_20210310.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         objects_title = Objects_GTD("sensor_name", "frame_id", "timestamp_sec" ,"timestamp_nanosec", "available", "verified", "label", "position_x", "position_y" ,
          "position_z", "size_x", "size_y", "size_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w",
          "linear_velocity_x", "linear_velocity_y", "linear_velocity_z", "angular_velocity_x", "angular_velocity_y", "angular_velocity_z")
         writer.writerow(objects_title)

    with open('script/validation_report/Ego_CanData_20210310.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         objects_title = Ego_CanData("frame_id", "timestamp_sec" ,"timestamp_nanosec", "available", "verified","Speed_[m/s]","Throttle_[%]","Braking_[%]","Steering_[%]","Parking_Brake_Status_[bool]",
    "High_Beam_Status[bool]","Low_Beam_Status_[bool]","Hazard_Light_Status_[bool]","Fog_Light_Status_[bool]","Left_Turn_Signal_Status_[bool]",
    "Right_Turn_Signal_Status_[bool]","Wiper_Status_[bool]","Reverse_Gear_Status_[bool]","Selected_Gear_[Int]","Engine_Status_[bool]",
    "Engine_RPM_[RPM]","GPS_Latitude_[Latitude]","GPS_Longitude_[Longitude]","Altitude_[m]","orientation_x", "orientation_y", "orientation_z", "orientation_w",
    "velocity_x", "velocity_y", "velocity_z")
         writer.writerow(objects_title)     
                        # Create subscriber(s)    
    with open('script/validation_report/Autoware_PerceptionData_20210310.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec" , "timestamp_nanosec" , "available", "verified", "vehicle_label", "signal_label", "class_likelihood",
            "centroid_x", "centroid_y", "centroid_z", "size_x", "size_y", "size_z", 
            "corner_1_x", "corner_1_y", "corner_1_z", "corner_2_x","corner_2_y", "corner_2_z", "corner_3_x",   
            "corner_3_y", "corner_3_z", "corner_4_x", "corner_4_y", "corner_4_z", "orientation_x",    
            "orientation_y", "orientation_z", "orientation_w", "velocity", "heading", "heading_rate","value")
         writer.writerow(autoware_percep_title)

    # Create subscriber(s)    
 
    # from lg simulator
    self.subscriber = self.create_subscription(CanBusData,'/lgsvl/state_report',self.lg_statereport_callback,1)

    # from the autoware ad stack
    self.subscriber_non_ego = self.create_subscription(Detection3DArray,'/simulator/ground_truth/detections',self.lg_groundtdetection_callback,1)
    
    # from the autoware ad stack
    self.subscription_autoware = self.create_subscription(BoundingBoxArray,'/lidars/lidar_bounding_boxes',self.autoware_callback,1)
   
    self.subscriber  # prevent unused variable warning
    self.subscriber_non_ego 
    self.subscription_autoware 


  def autoware_callback(self, msg):
      global lgstamp
      global autostamp
      global autoware_boxes
      global framenum
      
      autostamp = msg.header.stamp.sec
      autoware_boxes = msg.boxes
      #print("Autoware Data : ", msg)
      print("number of box : ", len(autoware_boxes))
    
      c_autoware_boxes = 0
      while len(autoware_boxes) > 0 :
        with open('script/validation_report/Autoware_PerceptionData_20210310.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)
            autoware_percep_data = Autoware_Objects(framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, True, False,
                autoware_boxes[c_autoware_boxes].vehicle_label, 
                autoware_boxes[c_autoware_boxes].signal_label, 
                autoware_boxes[c_autoware_boxes].class_likelihood,
                autoware_boxes[c_autoware_boxes].centroid.x,
                autoware_boxes[c_autoware_boxes].centroid.y,
                autoware_boxes[c_autoware_boxes].centroid.z,
                autoware_boxes[c_autoware_boxes].size.x,
                autoware_boxes[c_autoware_boxes].size.y,
                autoware_boxes[c_autoware_boxes].size.z,
                autoware_boxes[c_autoware_boxes].corners[0].x,
                autoware_boxes[c_autoware_boxes].corners[0].y,
                autoware_boxes[c_autoware_boxes].corners[0].z,
                autoware_boxes[c_autoware_boxes].corners[1].x,
                autoware_boxes[c_autoware_boxes].corners[1].y,
                autoware_boxes[c_autoware_boxes].corners[1].z,
                autoware_boxes[c_autoware_boxes].corners[2].x,
                autoware_boxes[c_autoware_boxes].corners[2].y,
                autoware_boxes[c_autoware_boxes].corners[2].z,
                autoware_boxes[c_autoware_boxes].corners[3].x,
                autoware_boxes[c_autoware_boxes].corners[3].y,
                autoware_boxes[c_autoware_boxes].corners[3].z,
                autoware_boxes[c_autoware_boxes].orientation.x,
                autoware_boxes[c_autoware_boxes].orientation.y,
                autoware_boxes[c_autoware_boxes].orientation.z,
                autoware_boxes[c_autoware_boxes].orientation.w,
                autoware_boxes[c_autoware_boxes].velocity,
                autoware_boxes[c_autoware_boxes].heading,
                autoware_boxes[c_autoware_boxes].heading_rate,
                autoware_boxes[c_autoware_boxes].value)

            writer.writerow(autoware_percep_data)
            if len(autoware_boxes)-1 == c_autoware_boxes :
                break;
            c_autoware_boxes = c_autoware_boxes + 1
#for lg_data
  def lg_statereport_callback(self, msg):
      global lgstamp
      global autostamp
      lgstamp = msg.header.stamp.sec
      print("Ego Data : ", msg)
      global ego_vehicle_speed 
      ego_vehicle_speed= msg.speed_mps
      global ego_linear_velocities 
      ego_linear_velocities= msg.linear_velocities.x
      global ego_brake_pct 
      ego_brake_pct = msg.brake_pct
      global framenum
      framenum = framenum+1
      steer_pct = msg.steer_pct

      with open('script/validation_report/Ego_CanData_20210310.csv','a', newline='') as csvfile:
         writer = csv.writer(csvfile)
         ego_Data = Ego_CanData(framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, False, False,
          msg.speed_mps,msg.throttle_pct, msg.brake_pct, msg.steer_pct, msg.parking_brake_active, msg.high_beams_active, msg.low_beams_active, 
          msg.hazard_lights_active, msg.fog_lights_active, msg.left_turn_signal_active, msg.right_turn_signal_active, msg.wipers_active, 
          msg.reverse_gear_active, msg.selected_gear, msg.engine_active, msg.engine_rpm, msg.gps_latitude, msg.gps_longitude, 
          msg.gps_altitude, msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w, msg.linear_velocities.x,
          msg.linear_velocities.y, msg.linear_velocities.z)
         writer.writerow(ego_Data) 
     
      #print("Steering Left/Right  : ", steer_pct)

  def lg_groundtdetection_callback(self, msg):
      global lgstamp
      global ego_vehicle_speed 
      global ego_linear_velocities
      global ego_brake_pct
      global l_brake
      global l_vehicle_speed
      global framenum

      print("modified by Shiv")
      lg_gt_stamp = msg.header.stamp.sec
      lg_gt_nanosec = msg.header.stamp.nanosec

      report_file = open("script/validation_report/report_control.txt",'a+')
      
      print(framenum)
      print(len(msg.detections))
      if ego_brake_pct == 0:
         print("**Brake not Applied and speed of the Ego :",ego_linear_velocities)

      l_vehicle_speed.append(ego_linear_velocities)
      l_brake.append(ego_brake_pct)
      if len(msg.detections)==0:
         print("No Object")
         objects =  Objects_GTD("lidar", framenum, lg_gt_stamp, lg_gt_nanosec, False, False, "no_object", 0.0, 0.0 ,
               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
         #print(objects)
         with open('script/validation_report/Objects_GTD_20210310.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)          
            writer.writerow(objects)

      framenum = framenum+1

      if len(msg.detections) >  0:
         c_lg_bbox = 0
         #print("number of box : ", len(msg.detections))
         while len(msg.detections) > 0:
               if lgstamp == lg_gt_stamp or lgstamp == lg_gt_stamp -1:
                  report_file.write("Time Stamp : "+ str(lgstamp) +"\n") 
                  lg_pos_x = msg.detections[c_lg_bbox].bbox.position.position.x
                  #print("Lg box x position : ", lg_pos_x)
                  lg_velocity_x = msg.detections[c_lg_bbox].velocity.linear.x
                  print("Speed of the Non Ego : ", lg_velocity_x)
                  report_file.write("Speed of NPC's : "+ str(lg_velocity_x) +"\n") 
                  # ego, nonego velocities,  nonego position, ego brake
                  # distance 
                  #ttc = (ego_linear_velocities - 4) /(ego_linear_velocities - lg_velocity_x)
                  ttc = (lg_pos_x - 4) /(ego_linear_velocities - lg_velocity_x)
                  vehicle_label = msg.detections[c_lg_bbox].label

                  objects =  Objects_GTD("lidar", framenum, lg_gt_stamp, lg_gt_nanosec, False, False, vehicle_label, 
                  msg.detections[c_lg_bbox].bbox.position.position.x ,
                  msg.detections[c_lg_bbox].bbox.position.position.y, 
                  msg.detections[c_lg_bbox].bbox.position.position.z,
                  msg.detections[c_lg_bbox].bbox.size.x,
                  msg.detections[c_lg_bbox].bbox.size.y, 
                  msg.detections[c_lg_bbox].bbox.size.y,
                  msg.detections[c_lg_bbox].bbox.position.orientation.x, 
                  msg.detections[c_lg_bbox].bbox.position.orientation.y,
                  msg.detections[c_lg_bbox].bbox.position.orientation.z,
                  msg.detections[c_lg_bbox].bbox.position.orientation.w,
                  msg.detections[c_lg_bbox].velocity.linear.x,
                  msg.detections[c_lg_bbox].velocity.linear.y,
                  msg.detections[c_lg_bbox].velocity.linear.z,
                  msg.detections[c_lg_bbox].velocity.angular.x,
                  msg.detections[c_lg_bbox].velocity.angular.y,
                  msg.detections[c_lg_bbox].velocity.angular.z)
                  #print(objects)
                  with open('script/validation_report/Objects_GTD_20210310.csv','a', newline='') as csvfile:
                        writer = csv.writer(csvfile)          
                        writer.writerow(objects)

                  print("Vehicle Label : ", vehicle_label, " Time to Collision : ", abs(ttc))
                  report_file.write("Time to collision with : "+ vehicle_label + " is : "+ str(abs(ttc)) +"\n") 
                  if ego_brake_pct == 0:
                     print("**Brake not Applied and speed of the Ego :",ego_linear_velocities)
                     report_file.write("Speed of Ego : "+ str(abs(ego_linear_velocities)) +"\n") 
                  elif ego_brake_pct == 1:
                     print("Brake Applied and speed of Ego decreased :",ego_linear_velocities)
                     report_file.write("Brake Applied and Speed of Ego decreased : "+ str(ego_linear_velocities) +"\n") 
                     arr = []
                    
                     for i ,val in enumerate(l_vehicle_speed):
                         arr.append(i)
                     #plt.plot(arr,l_vehicle_speed)
                     #plt.ylabel('Speed of the vehicle')
                     #plt.xlabel('Time')
                    # plt.show()
                     #plt.clf();

                  if (ttc < 1 and ego_linear_velocities < 1 and lg_velocity_x < 1):
                     print("***********Ego Vehicle Collided with the :",msg.detections[c_lg_bbox].label)
                     report_file.write("\nEgo vehicle collided with  : "+ str(msg.detections[c_lg_bbox].label) +"\n") 
                     arr = []
                    
                     for i ,val in enumerate(l_vehicle_speed):
                         arr.append(i)
                     #plt.plot(arr,l_vehicle_speed)
                     #plt.ylabel('Speed of the vehicle')
                     #plt.xlabel('Time')
                     #plt.show()
                     #plt.clf();

               if len(msg.detections)-1 == c_lg_bbox :
                  break;
               c_lg_bbox = c_lg_bbox + 1
      report_file.close();

def main(args=None):
 
  # Initialize the rclpy library
  rclpy.init(args=args)
 
  # Create the node
  control_validation = ControlValidation()
 
  # Spin the node so the callback function is called.
  # Pull messages from any topics this node is subscribed to.
  # Publish any pending messages to the topics.
  rclpy.spin(control_validation)
 
  # Destroy the node explicitly
  # (optional - otherwise it will be done automatically
  # when the garbage collector destroys the node object)
  control_validation.destroy_node()
 
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
 
if __name__ == '__main__':
  main()


