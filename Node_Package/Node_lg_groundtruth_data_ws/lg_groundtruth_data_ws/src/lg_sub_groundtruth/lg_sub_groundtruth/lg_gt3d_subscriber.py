import rclpy # Import the ROS client library for Python
from rclpy.node import Node # Enables the use of rclpy's Node class
from std_msgs.msg import Float64MultiArray # Enable use of the std_msgs/Float64MultiArray message type
from lgsvl_msgs.msg import Detection3DArray
from autoware_auto_msgs.msg import BoundingBoxArray
import numpy as np # NumPy Python library
from scipy.spatial import ConvexHull
import cmath
from scipy.spatial import distance

import time
import sys
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler 
from numpy import *

import csv
from .acquisition_structures import Objects_GTD
from .acquisition_structures import Autoware_Objects

lgstamp = 0
autostamp = 0
autoware_boxes = BoundingBoxArray.boxes
framenum = 0
file_path = ""


class Handler(FileSystemEventHandler): 
    @staticmethod
    def on_any_event(event): 
        if event.is_directory: 
            return None
        elif event.event_type == 'modified': 
            # Event is modified, you can process it now 
            print("Watchdog received modified event - % s." % event.src_path) 
            global file_path
            f_path = open('PolyReports/Validation_report/config.txt', 'r')
            path = f_path.readline()
            file_path = path.strip()
            print("read path :  ",file_path)
            f_path.close()

            print("file path modified : ",file_path)
            with open(file_path + '/Objects_GTD_Perception.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 objects_title = Objects_GTD("sensor_name", "frame_id", "timestamp_sec" ,"timestamp_nanosec", "available", "verified", "label", "position_x", "position_y" ,
                  "position_z", "size_x", "size_y", "size_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w",
                  "linear_velocity_x", "linear_velocity_y", "linear_velocity_z", "angular_velocity_x", "angular_velocity_y", "angular_velocity_z")
                 writer.writerow(objects_title)

                    # Create subscriber(s)    
            with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
                 writer = csv.writer(csvfile)
                 autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec" , "timestamp_nanosec" , "available", "verified", "vehicle_label", "signal_label", "class_likelihood",
                    "centroid_x", "centroid_y", "centroid_z", "size_x", "size_y", "size_z", 
                    "corner_1_x", "corner_1_y", "corner_1_z", "corner_2_x","corner_2_y", "corner_2_z", "corner_3_x",   
                    "corner_3_y", "corner_3_z", "corner_4_x", "corner_4_y", "corner_4_z", "orientation_x",    
                    "orientation_y", "orientation_z", "orientation_w", "velocity", "heading", "heading_rate","value")
                 writer.writerow(autoware_percep_title)

class PublishingSubscriber(Node):
  """
  Create a PublishingSubscriber class, which is a subclass of the Node class.
  """
  def __init__(self):
    global file_path
    f_path = open('PolyReports/Validation_report/config.txt', 'r')
    path = f_path.readline()
    file_path = path.strip()
    f_path.close()
    #self.observer = Observer()


    """
    Class constructor to set up the node
    """
   
    # Initiate the Node class's constructor and give it a name
    super().__init__('Perception_Validation')
    #super().__init__('publishing_subscriber')

    print("file path : ",file_path)
    with open(file_path + '/Objects_GTD_Perception.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         objects_title = Objects_GTD("sensor_name", "frame_id", "timestamp_sec" ,"timestamp_nanosec", "available", "verified", "label", "position_x", "position_y" ,
          "position_z", "size_x", "size_y", "size_z", "orientation_x", "orientation_y", "orientation_z", "orientation_w",
          "linear_velocity_x", "linear_velocity_y", "linear_velocity_z", "angular_velocity_x", "angular_velocity_y", "angular_velocity_z")
         writer.writerow(objects_title)

            # Create subscriber(s)    
    with open(file_path + '/Autoware_PerceptionData.csv','w', newline='') as csvfile:
         writer = csv.writer(csvfile)
         autoware_percep_title = Autoware_Objects("frame_id","timestamp_sec" , "timestamp_nanosec" , "available", "verified", "vehicle_label", "signal_label", "class_likelihood",
            "centroid_x", "centroid_y", "centroid_z", "size_x", "size_y", "size_z", 
            "corner_1_x", "corner_1_y", "corner_1_z", "corner_2_x","corner_2_y", "corner_2_z", "corner_3_x",   
            "corner_3_y", "corner_3_z", "corner_4_x", "corner_4_y", "corner_4_z", "orientation_x",    
            "orientation_y", "orientation_z", "orientation_w", "velocity", "heading", "heading_rate","value")
         writer.writerow(autoware_percep_title)
    # The node subscribes to messages of type std_msgs/Float64MultiArray, over a topic named:
    #   /simulator/ground_truth/detections
    # The callback function is called as soon as a message is received.
    # The maximum number of queued messages is 10.
 
    # from lg simulator
    self.subscription_1 = self.create_subscription(Detection3DArray,'/simulator/ground_truth/detections',self.lg_callback,1)

    # from the autoware ad stack
    self.subscription_2 = self.create_subscription(BoundingBoxArray,'/lidars/lidar_bounding_boxes',self.autoware_callback,1)
    
    self.subscription_1  # prevent unused variable warning
    self.subscription_2 
    
  def run(self): 
    event_handler = Handler() 
    self.observer.schedule(event_handler, path='PolyReports/Validation_report/config.txt') 
    self.observer.start()
    try:
     while True:
       time.sleep(1)
    except:
     self.observer.stop()
     print('Error')
    self.observer.join()

  def getfileName(self):
    global file_path
    f_path = open('PolyReports/Validation_report/config.txt', 'r')
    path = f_path.readline()
    file_path = path.strip()
    f_path.close()  

#for lg_data
  def lg_callback(self, msg):
      global lgstamp
      global autostamp
      global framenum
      global file_path

      lgstamp = msg.header.stamp.sec
      
      print(framenum)
      # Process only frames which have groundtruth data in LG Simulator  
      if len(msg.detections) >  0:
        #self.itrate_data(msg) 
        #self.perception_validation(msg)
        self.perception_validation_IOU(msg)
        #objprecval.per_vali(msg)
      else:
         print("No vehicle in the LG Scene : ", len(msg.detections))
         #self.get_logger().info('No vehicle available in the LG Scene : %s' %len(msg.detections))
      if len(msg.detections)==0:
         print("No Object")
         objects =  Objects_GTD("lidar", framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, False, False, "no_object", 0.0, 0.0 ,
               0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
         #print(objects)
         with open(file_path + '/Objects_GTD_Perception.csv','a', newline='') as csvfile:
            writer = csv.writer(csvfile)          
            writer.writerow(objects)
      if len(msg.detections) >  0:
          c_lg_bbox = 0
          print("number of box : ", len(msg.detections))
          while len(msg.detections) > 0:
            objects =  Objects_GTD("lidar", framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, True, False,
                  msg.detections[c_lg_bbox].label, 
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
            with open(file_path + '/Objects_GTD_Perception.csv','a', newline='') as csvfile:
                  writer = csv.writer(csvfile)          
                  writer.writerow(objects)
            if len(msg.detections)-1 == c_lg_bbox :
                  break;
            c_lg_bbox = c_lg_bbox + 1
      #self.get_logger().info('Subscribed Data of LG Groundtruth Data : "%s"' % msg.detections['bbox'])  
      framenum = framenum+1

  def autoware_callback(self, msg):
      global lgstamp
      global autostamp
      global autoware_boxes
      global framenum
      global file_path
      
      autostamp = msg.header.stamp.sec
      autoware_boxes = msg.boxes
      #print("Autoware Data : ", msg)
      print("number of box : ", len(autoware_boxes))
      #if len(autoware_boxes) == 0 :
      #    writer = csv.writer(csvfile)
      #    autoware_percep_data = Autoware_Objects(framenum, msg.header.stamp.sec, msg.header.stamp.nanosec, False, False,
      #        "no_object","no_signal",0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,0.0, 0.0,0.0, 0.0, 0.0, 
      #        0.0, 0.0, 0.0, 0.0,0.0, 0.0, 0.0,0.0, 0.0,0.0,0.0,0.0)
      #    writer.writerow(autoware_percep_data)
      c_autoware_boxes = 0
      while len(autoware_boxes) > 0 :
        print("file path from with open *********  : ",file_path)
        with open(file_path + '/Autoware_PerceptionData.csv','a', newline='') as csvfile:
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

  def perception_validation_IOU(self, msg):
      report_file = open("script/validation_report/report_perception.txt",'a+') 
      mini_report_file = open("script/validation_report/mini_report_perception.txt",'a+') 
      #report_file.write("************************* Perception validation *************************\n") 
      self.get_logger().info('************************* Perception validation *************************')

      print(len(msg.detections))
      c_lg_bbox = 0
      while len(msg.detections) > 0:
            if lgstamp == autostamp :
                report_file.write("************************* Perception validation *************************\n") 
                self.get_logger().info('Time stamp matched for Lg frame and Autoware perception stack data : %s' %autostamp)
                #report_file.write("Time stamp matched for Lg frame and Autoware perception stack data : %s" "\n" %autostamp) 
                #print("Time stamp matched for Lg frame and Autoware perception stack data : ", autostamp)
                # return the BoundingBox3D of lg simulator include(position, orientation, size)
                lg_pos = msg.detections[c_lg_bbox].bbox.position.position
                lg_size = msg.detections[c_lg_bbox].bbox.size
                # need to calculte center position
                # c.x =  position.x - (size.x/2)
                #x_center = lg_pos.x + ((lg_size.x / 2))
                x_center = 0
                if lg_pos.x < 0 :
                    x_center = lg_pos.x + ((lg_size.x / 2))
                else :
                    x_center = lg_pos.x - ((lg_size.x / 2))

                y_center = 0
                if lg_pos.y < 0 :
                    y_center = lg_pos.y + ((lg_size.y / 2)) -1
                else :
                    y_center = lg_pos.y - ((lg_size.y / 2)) - 1
                z_center = lg_pos.z + ((lg_size.z / 2))
                #print("LG bounding box center : ",x_center,y_center, z_center)
                c_autoware_boxes = 0
                while len(autoware_boxes) > 0 :
                    #print("LG_Box Label : ",msg.detections[c_lg_bbox].label, " ::Index= ", c_lg_bbox)
                    #print("Autoware_Box : B_Box", " ::Index= ", c_autoware_boxes)
                    lg = str(msg.detections[c_lg_bbox].label) + " :: Index = " + str(c_lg_bbox)
                    self.get_logger().info('LG_Box Label : %s' %lg)
                    #report_file.write("LG_Box Label : %s" "\n" %lg) 
                    #self.get_logger().info('LG_Box Label : %s :: Index = %s ' %msg.detections[c_lg_bbox].label %c_lg_bbox)
                    self.get_logger().info('Autoware_Box : B_Box :: Index =  %s' %c_autoware_boxes)
                    #report_file.write("Autoware_Box : B_Box :: Index =  %s" "\n" %c_autoware_boxes) 
                    ad_bbsize = autoware_boxes[c_autoware_boxes].size
                    ad_bbcentroid = autoware_boxes[c_autoware_boxes].centroid
                    #print("AD bounding box center : ",ad_bbcentroid.x, ad_bbcentroid.y, ad_bbcentroid.z)
                    # Finding the Euclidean Distance                   
                    a = (x_center, y_center, 0)
                    b = (ad_bbcentroid.x, ad_bbcentroid.y, 0)
                    dist = distance.euclidean(a, b)
                    diff_of_y = abs(y_center - ad_bbcentroid.y)
                    print("diff_of_y : ",diff_of_y)
                    #print("distance : ",dist)
                    if dist < 4 and diff_of_y < 2 :
                        report_file.write("Time Stamp : "+ str(autostamp) +"\n") 
                        mini_report_file.write("Time Stamp : "+ str(autostamp) +"\n") 
                        mini_report_file.write("LG_Box Label :" + str(lg) + "\n") 
                        #print("LG bounding box center cordinate's : ", x_center,y_center, z_center)
                        log_lg = "LG bounding box center cordinate's : " + str(x_center) +" , "+ str(y_center) +" , "+ str(z_center)
                        self.get_logger().info(log_lg)
                        report_file.write(log_lg+"\n") 
                        #print("AD bounding box center cordinate's : ", ad_bbcentroid.x, ad_bbcentroid.y, ad_bbcentroid.z)
                        log_ad = "AD bounding box center cordinate's : " + str(ad_bbcentroid.x,) +" , "+ str(ad_bbcentroid.y) +" , "+ str(ad_bbcentroid.z)
                        self.get_logger().info(log_ad)
                        report_file.write(log_ad +"\n") 
                        #print("Distance between both the center's : ", dist)
                        log_adist = "Distance between both the center's : " + str(dist)
                        self.get_logger().info(log_adist)
                        report_file.write(log_adist +"\n") 
                        #print("Vehicle center of both data matched!!")
                        log_adist = "Vehicle center of both data matched!!\n\n "
                        self.get_logger().info(log_adist)
                        report_file.write(log_adist) 
                        mini_report_file.write(log_adist) 
                    if len(autoware_boxes)-1 == c_autoware_boxes :
                        break;
                    c_autoware_boxes = c_autoware_boxes + 1
            if len(msg.detections)-1 == c_lg_bbox :
               break;
            c_lg_bbox = c_lg_bbox + 1
      report_file.close() #to change file access modes   
      mini_report_file.close()

  def itrate_data(self,msg):
      print("Checking time stamp data of lg with autoware : ")
      # Program to show various ways to read and 
      # write data in a file. 
      #report_file = open("validation_report/validation_report.txt","a")       
      report_file = open("script/validation_report/validation_report.txt",'a+') 
  
      # \n is placed to indicate EOL (End of Line) 
      report_file.write("Autoware perception data vehicle ID, stamp ID \n") 

      if lgstamp == autostamp :
         print("lgstamp : ",lgstamp)
         c_lg_bbox = 0
         print("\n\nNumber of box in lG Groundtruth data", len(msg.detections))
         report_file.write("Time Stamp of Groundtruth and AD Stack Data : " + str(lgstamp) + "\n" )

         report_file.write("No. of Vehicle in the above timestamp : " + str(len(msg.detections)) + "\n") 
         #report_file.close()
         while len(msg.detections) > 0:
               # return the BoundingBox3D of lg simulator include(position, orientation, size)
               lg_pos = msg.detections[c_lg_bbox].bbox.position.position
               lg_orient = msg.detections[c_lg_bbox].bbox.position.orientation
               lg_size = msg.detections[c_lg_bbox].bbox.size

               # need to calculte center position
               # c.x =  position.x - (size.x/2)
               x_center = lg_pos.x - ((lg_size.x / 2))
               y_center = lg_pos.y - ((lg_size.y / 2))
               z_center = lg_pos.z - ((lg_size.z / 2))
               print("LG bounding box center : ",x_center,y_center, z_center)
               
               #x_center = lg_pos.x + ((lg_size.x / 2) * lg_orient.x)
               #y_center = lg_pos.y + ((lg_size.y / 2) * lg_orient.y)
               #z_center = lg_pos.z + ((lg_size.z / 2) * lg_orient.z)
               #print("LG bounding box center : ",x_center,y_center, z_center)

               report_file.write("Vehicle label : " + str(c_lg_bbox) + "\n") 
               report_file.write("No. of detected data in AD Stack : " + str(len(autoware_boxes))+ "\n") 
               # Extract data from the autoware subscribe topic
               c_autoware_boxes = 0
               while len(autoware_boxes) > 0 :

                     ad_bbsize = autoware_boxes[c_autoware_boxes].size
                     ad_bbcentroid = autoware_boxes[c_autoware_boxes].centroid
                     print("AD bounding box center : ",ad_bbcentroid)
                     
                     # comment the IOU algo
                     #print("Autoware  :", autoware_boxes[c_autoware_boxes])
                     #print("  lg x : ",msg.detections[c_lg_bbox].bbox.size.x)

                     # get_3d_box(box_size, heading_angle, center)
                     corners_3d_ground_lg  = self.get_3d_box((lg_size.x,lg_size.y, lg_size.z), -1.50, (x_center ,y_center ,z_center)) 
                     corners_3d_predict_ad = self.get_3d_box((ad_bbsize.x, ad_bbsize.y, ad_bbsize.z), -1.21, (ad_bbcentroid.x, ad_bbcentroid.y, ad_bbcentroid.z ))

                     (IOU_3d,IOU_2d) = self.box3d_iou(corners_3d_predict_ad,corners_3d_ground_lg)
                     print ("IOU :  ", IOU_3d,IOU_2d) #3d IoU/ 2d IoU of BEV(bird eye's view)

                     report_file.write("Result intersection over union(IOU) : " + str(IOU_3d) +"  "+ str(IOU_2d) + "\n" ) 
                     if len(autoware_boxes)-1 == c_autoware_boxes :
                        break;
                     c_autoware_boxes = c_autoware_boxes + 1      

               if len(msg.detections)-1 == c_lg_bbox :
                  break;

               c_lg_bbox = c_lg_bbox + 1
               print("lg_box : ",c_lg_bbox)
               print("auto_box : ",c_autoware_boxes)
      else:
         print("Timestamp of lg groundtruth doesn't match with the autoware ")
      report_file.close() #to change file access modes   
       
def main(args=None):
  observer = Observer()
  event_handler = Handler() 
  observer.schedule(event_handler, path='PolyReports/Validation_report/config.txt') 
  observer.start()
  
  print('Stopping the observer !!!!!')
  #observer.join()

  print('after join the observer !!!!!')

  # Initialize the rclpy library
  rclpy.init(args=args)
 
  # Create the node
  publishing_subscriber = PublishingSubscriber()
  #publishing_subscriber.run()
  
  # Spin the node so the callback function is called.
  # Pull messages from any topics this node is subscribed to.
  # Publish any pending messages to the topics.
  rclpy.spin(publishing_subscriber)

  # Destroy the node explicitly
  # (optional - otherwise it will be done automatically
  # when the garbage collector destroys the node object)
  publishing_subscriber.destroy_node()
 
  # Shutdown the ROS client library for Python
  rclpy.shutdown()
 
def run(args=None): 
  observer = Observer()
  event_handler = Handler() 
  observer.schedule(event_handler, path='PolyReports/Validation_report/config.txt') 
  observer.start()
  try:
   while True:
     time.sleep(1)
  except:
   observer.stop()
   print('Stopping the observer !!!!!')
  observer.join() 


if __name__ == '__main__':
  # observer = Observer()
  # event_handler = Handler() 
  # observer.schedule(event_handler, path='PolyReports/Validation_report/config.txt') 
  # observer.start() 
  # try:
  #   while True:
  #       time.sleep(1)
  # except:
  #   self.observer.stop()
  #   print('Error')
  # observer.join()
  main()



