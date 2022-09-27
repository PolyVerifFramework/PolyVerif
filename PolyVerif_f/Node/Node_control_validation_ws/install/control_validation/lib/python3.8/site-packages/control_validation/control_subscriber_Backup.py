import rclpy # Import the ROS client library for Python
from rclpy.node import Node # Enables the use of rclpy's Node class
from std_msgs.msg import Float64MultiArray # Enable use of the std_msgs/Float64MultiArray message type
from lgsvl_msgs.msg import CanBusData
from lgsvl_msgs.msg import Detection3DArray
import numpy as np # NumPy Python library
from scipy.spatial import ConvexHull
import cmath
from scipy.spatial import distance
import matplotlib.pyplot as plt 

from numpy import *
l_vehicle_speed = []
l_brake = []
lgstamp = 0
autostamp = 0
ego_vehicle_speed = 0.0
ego_linear_velocities = 0.0
ego_brake_pct = 0
#autoware_boxes = BoundingBoxArray.boxes
class ControlValidation(Node):

  def __init__(self):
    """
    Class constructor to set up the node
    """
   
    # Initiate the Node class's constructor and give it a name
    super().__init__('control_validation')


    # Create subscriber(s)    
 
    # from lg simulator
    self.subscriber = self.create_subscription(CanBusData,'/lgsvl/state_report',self.lg_statereport_callback,1)

    # from the autoware ad stack
    self.subscriber_non_ego = self.create_subscription(Detection3DArray,'/simulator/ground_truth/detections',self.lg_groundtdetection_callback,1)
    
    self.subscriber  # prevent unused variable warning
    self.subscriber_non_ego 

#for lg_data
  def lg_statereport_callback(self, msg):
      global lgstamp
      global autostamp
      lgstamp = msg.header.stamp.sec
      #print("Time stamp : ", lgstamp)
      global ego_vehicle_speed 
      ego_vehicle_speed= msg.speed_mps
      global ego_linear_velocities 
      ego_linear_velocities= msg.linear_velocities.x
      global ego_brake_pct 
      ego_brake_pct = msg.brake_pct

     
      steer_pct = msg.steer_pct
      #print("Steering Left/Right  : ", steer_pct)

  def lg_groundtdetection_callback(self, msg):
      global lgstamp
      global ego_vehicle_speed 
      global ego_linear_velocities
      global ego_brake_pct
      global l_brake
      global l_vehicle_speed
      lg_gt_stamp = msg.header.stamp.sec
      report_file = open("script/validation_report/report_control.txt",'a+')
      if ego_brake_pct == 0:
         print("**Brake not Applied and speed of the Ego :",ego_linear_velocities)

      l_vehicle_speed.append(ego_linear_velocities)
      l_brake.append(ego_brake_pct)

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


