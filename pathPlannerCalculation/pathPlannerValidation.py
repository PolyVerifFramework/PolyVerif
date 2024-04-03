# -*- coding: utf-8 -*-
"""
Created on Mon May 10 16:38:24 2021

@author: 
"""
import csv  
import os
import math
import pandas as pd
from GenericParamComputation import GenericParams as gp
from utils.acquisition_structures import Deviation_Report
from configparser import ConfigParser

#function to compute localization deviation per frame/timestamp
def ComputeParams(goalPose_loc, lg_ego_loc, location, map_origion_error, avp_demo_flag):
    deviation_report = location + "/deviation_report.csv" 
    
    with open(deviation_report,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Deviation_Report("timestamp_sec", "timestamp_nanosec", "position_x", "position_y",
                        "position_z", "orientation_x","orientation_y", "orientation_z", "orientation_w",
                        "deviation")
        writer.writerow(title)                         

    #goalPose_stamping = gp.TimeStamp_Mapping(goalPose_loc) # Calculate timestamp
    #lg_ego_stamping = gp.TimeStamp_Mapping(lg_ego_loc) # Calculate timestamp
    lengthOfData=len(goalPose_loc)
    if lengthOfData==0:
        raise Exception("No GoalPos Found..") 
    goal_pos_x = goalPose_loc.position_x[lengthOfData-1]
    goal_pos_y = goalPose_loc.position_y[lengthOfData-1]
  
    # Calculate deviation for each frame
    with open(deviation_report,'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for idx_LG in range(lg_ego_loc["timestamp_sec"].count()-1):  
           
          lg_pos_x   = lg_ego_loc.position_x[idx_LG] - map_origion_error[0]
          lg_pos_y   = lg_ego_loc.position_y[idx_LG] - map_origion_error[1]
    
           # Calculate Euclidean distance using x nad y values
          deviation = math.sqrt((math.pow((goal_pos_x-lg_pos_x),2)) + (math.pow((goal_pos_y-lg_pos_y),2)))
          print("deviation", deviation)
          
           # Save data in to csv
          values = Deviation_Report(lg_ego_loc.timestamp_sec[idx_LG], lg_ego_loc.timestamp_nanosec[idx_LG],
                                         lg_ego_loc.position_x[idx_LG],lg_ego_loc.position_y[idx_LG], lg_ego_loc.position_z[idx_LG],
                                         lg_ego_loc.orientation_x[idx_LG],lg_ego_loc.orientation_y[idx_LG], lg_ego_loc.orientation_z[idx_LG],
                                         lg_ego_loc.orientation_w[idx_LG], deviation)
    
          writer.writerow(values)   
             
#function to calculate consolidated data from framewise data 
def DeviationParams(location, deviationFromGoalPos_maxThreshold):
    print("Computing deviation params")
    deviation_report = location + "/deviation_report.csv"
    deviation_data = Read_data(deviation_report) # Read per frame based deviation data
    
    lengthOfData = len(deviation_data)
    deviationFromGoalPos = deviation_data.deviation[lengthOfData - 1]
    deviationFromGoalPos = round(deviationFromGoalPos, 2)
    goalPosAchieved = False
    print("deviationFromGoalPos", deviationFromGoalPos)            

    if(deviationFromGoalPos < deviationFromGoalPos_maxThreshold):
      goalPosAchieved = True
    else:
      goalPosAchieved = False


    deviation_stats_file = location + "/planner_stats.txt" 
    file = open(deviation_stats_file,'w+')
    print("goalPosAchieveD:",goalPosAchieved)
    goalPosD = str(deviationFromGoalPos)
    goalPosAchieveD = str(goalPosAchieved)
    
    noOfCollisionCount = str(collisonCount())

    line = [goalPosD+"\n",goalPosAchieveD+"\n",noOfCollisionCount+"\n"]

    file.writelines(line)
    file.close()

#function to read GT data using given filename
def Read_data(filename):
    data = pd.read_csv(filename) 
    return data


# need to test TODO

# Calculate the collision using the lg simulator colliosn callback function.
# User can overload this function by writing their own logic
def collisonCount():

    noOfCollision = 0
    currentpath = os.getcwd()
    #pos = currentpath.rfind('/')
    #adePath = currentpath[0:pos]
   # 
    location = currentpath + '/'
    f_path = open(location + 'PolyReports/colisionCount.txt', 'r')
    path = f_path.readline()
    noOfCollision = path.strip()
    f_path.close()
    print("collision count : ", noOfCollision)
    return noOfCollision

#main function for calling various functions available in various classes
def main(args=None):

    currentpath = os.getcwd()
    #print("location : ", currentpath)

    pos = currentpath.rfind('/')
  #  adePath = currentpath[0:pos]
    location = currentpath + '/'
    f_path = open(location + 'PolyReports/config.txt', 'r')
    path = f_path.readline()
    file_path = path.strip()
    f_path.close()

   # print("adepath : ", adePath)
    print("Calculating Path Planner Validation.")
   
    deviationFromGoalPos_maxThreshold=5
    avp_demo_flag = False
    
    map_origion_error = [0,0,0]

    goalPose_loc_file =  file_path + '/Goal_Pose_PathPlanning.csv'
    lg_ego_file = file_path + '/GNSS_Localization.csv'
    
    goalPose_loc = Read_data(goalPose_loc_file)
    lg_ego_loc = Read_data(lg_ego_file)
    
    ComputeParams(goalPose_loc, lg_ego_loc, file_path, map_origion_error, avp_demo_flag)
    DeviationParams(file_path, deviationFromGoalPos_maxThreshold)
    

    # Need to read from the config file for map error
    # instantiate
   #config = ConfigParser()

    # parse existing file
   # config.read(currentpath + '/config.ini')

    # read values from a section
'''
    bool_val_taltech = config.getboolean('autoware_stack_map', 'taltech')
    bool_val_JTA = config.getboolean('autoware_stack_map', 'JTA_R1')
    bool_val_autonomoustuff = config.getboolean('autoware_stack_map', 'autonomoustuff')
    deviationFromGoalPos_maxThreshold = config.getint('autonomous_stack_config', 'planner_goalpose_max_deviation')

    #print("Avp taltech  :", bool_val_taltech)
    #print("planner goal pos max threshold : ", deviationFromGoalPos_maxThreshold)

    origin_x = config.getint('error_map_offset', 'map_lanelet2_scene_offset_x')
    origin_y = config.getint('error_map_offset', 'map_lanelet2_scene_offset_y')
    origin_z = config.getint('error_map_offset', 'map_lanelet2_scene_offset_z')
 
    avp_demo_flag = False
    if bool_val_taltech or bool_val_JTA == True:
        avp_demo_flag = True
   '''

   # map_origion_error = [origin_x, origin_y, origin_z]
    # Need to read from the config file for map error
    # Taltech
    #map_origion_error = [0,-300,0]
   

    
if __name__ == '__main__':
    main()
