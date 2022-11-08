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
def ComputeParams(auto_loc, lg_ego_loc, location, map_origion_error, avp_demo_flag):
    deviation_report = location + "/deviation_report.csv" 
    
    with open(deviation_report,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Deviation_Report("timestamp_sec", "timestamp_nanosec", "position_x", "position_y",
                        "position_z", "orientation_x","orientation_y", "orientation_z", "orientation_w",
                        "deviation")
        writer.writerow(title)                         

    auto_loc_stamping = gp.TimeStamp_Mapping(auto_loc) # Calculate timestamp
    lg_ego_stamping = gp.TimeStamp_Mapping(lg_ego_loc) # Calculate timestamp
    
    # Calculate deviation for each frame
    with open(deviation_report,'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for idx_LG in range(lg_ego_loc["timestamp_sec"].count()-1):  
            for idx_AUTO in range(auto_loc["timestamp_sec"].count()-1):
               # print("idx_LG", idx_LG)
               # print("idx_ctl", idx_ctl)
               if(auto_loc.timestamp_sec[idx_AUTO] == lg_ego_loc.timestamp_sec[idx_LG]):
                  if(auto_loc_stamping[idx_AUTO] == lg_ego_stamping[idx_LG]):
                       auto_pos_x = auto_loc.position_x[idx_AUTO]
                       auto_pos_y = auto_loc.position_y[idx_AUTO]
                       
                       # # Autonomous Stuff
                       # lg_pos_y   = lg_ego_loc.position_x[idx_LG] - map_origion_error[0]
                       # lg_pos_x   = -(lg_ego_loc.position_y[idx_LG] - map_origion_error[1])
    
                       # # Taltech 
                       # if avp_demo_flag == True:
                       #  lg_pos_x   = lg_ego_loc.position_x[idx_LG] - map_origion_error[0]
                       #  lg_pos_y   = lg_ego_loc.position_y[idx_LG] - map_origion_error[1]
                       
                       lg_pos_x   = lg_ego_loc.position_x[idx_LG] - map_origion_error[0]
                       lg_pos_y   = lg_ego_loc.position_y[idx_LG] - map_origion_error[1]
                    
                       # Calculate Euclidean distance using x nad y values
                       deviation = math.sqrt((math.pow((auto_pos_x-lg_pos_x),2)) + (math.pow((auto_pos_y-lg_pos_y),2)))
                       print("deviation", deviation)
    
                       # Save data in to csv

                       # # Autonomous Stuff
                       # values = Deviation_Report(lg_ego_loc.timestamp_sec[idx_LG], lg_ego_loc.timestamp_nanosec[idx_LG],
                       #                               -(lg_ego_loc.position_y[idx_LG]),lg_ego_loc.position_x[idx_LG], lg_ego_loc.position_z[idx_LG],
                       #                               lg_ego_loc.orientation_x[idx_LG],lg_ego_loc.orientation_y[idx_LG], lg_ego_loc.orientation_z[idx_LG],
                       #                               lg_ego_loc.orientation_w[idx_LG], deviation)
    
                       # # Taltech
                       # if avp_demo_flag == True:
                       #      values = Deviation_Report(lg_ego_loc.timestamp_sec[idx_LG], lg_ego_loc.timestamp_nanosec[idx_LG],
                       #                               lg_ego_loc.position_x[idx_LG],lg_ego_loc.position_y[idx_LG], lg_ego_loc.position_z[idx_LG],
                       #                               lg_ego_loc.orientation_x[idx_LG],lg_ego_loc.orientation_y[idx_LG], lg_ego_loc.orientation_z[idx_LG],
                       #                               lg_ego_loc.orientation_w[idx_LG], deviation)

                       values = Deviation_Report(lg_ego_loc.timestamp_sec[idx_LG], lg_ego_loc.timestamp_nanosec[idx_LG],
                                                     lg_ego_loc.position_x[idx_LG],lg_ego_loc.position_y[idx_LG], lg_ego_loc.position_z[idx_LG],
                                                     lg_ego_loc.orientation_x[idx_LG],lg_ego_loc.orientation_y[idx_LG], lg_ego_loc.orientation_z[idx_LG],
                                                     lg_ego_loc.orientation_w[idx_LG], deviation)
                            
                       writer.writerow(values)   
                   
#function to calculate consolidated data from framewise data 
def DeviationParams(location):
    print("Computing deviation params")
    deviation_report = location + "/deviation_report.csv"
    deviation_data = Read_data(deviation_report) # Read per frame based deviation data
    
    maxDeviation = deviation_data.deviation.max() # Calculate max deviation
    minDeviation = deviation_data.deviation.min() # Calculate min deviation
    meanDeviation = deviation_data.deviation.mean() # Calculate mnean deviation
    maxDeviation = round(maxDeviation, 2)
    minDeviation = round(minDeviation, 2)
    meanDeviation = round(meanDeviation, 2)
    print("Min Deviation ::", minDeviation)
    print("Max Deviation ::", maxDeviation)
    print("Mean Deviation ::", meanDeviation)
    deviation_stats_file = location + "/localize_stats.txt" 
    file = open(deviation_stats_file,'w+');

    maxD = str(maxDeviation)
    minD = str(minDeviation)
    meanD = str(meanDeviation)
    line = [maxD+"\n",minD+"\n", meanD+"\n"]

    file.writelines(line)
    file.close()

#function to read GT data using given filename
def Read_data(filename):
    data = pd.read_csv(filename)
    #print(data.to_string()) 
    return data

#main function for calling various functions available in various classes
def main(args=None):

    currentpath = os.getcwd()
    print("location : ", currentpath)

    pos = currentpath.rfind('/')
    adePath = currentpath[0:pos]
    location = adePath + '/'
    f_path = open(location + 'PolyReports/Validation_report/config1.txt', 'r')
    path = f_path.readline()
    file_path = path.strip()
    f_path.close()

    print("adepath : ", adePath)
    print("Calculating Localization Validation.")
    # /home/acclivis/adehome/PolyReports/GNSS_ODOM_Localization.csv

    # Need to read from the config file for map error
    # instantiate
    config = ConfigParser()

    # parse existing file
    config.read(currentpath + '/config.ini')

    # read values from a section
    bool_val_taltech = config.getboolean('autoware_stack_map', 'taltech')
    bool_val_JTA = config.getboolean('autoware_stack_map', 'JTA_R1')
    bool_val_autonomoustuff = config.getboolean('autoware_stack_map', 'autonomoustuff')

   # print("Avp taltech  :", bool_val_taltech)

    origin_x = config.getint('error_map_offset', 'map_lanelet2_scene_offset_x')
    origin_y = config.getint('error_map_offset', 'map_lanelet2_scene_offset_y')
    origin_z = config.getint('error_map_offset', 'map_lanelet2_scene_offset_z')
 
    avp_demo_flag = False
    if bool_val_taltech or bool_val_JTA == True:
        avp_demo_flag = True
    
    

    map_origion_error = [origin_x, origin_y, origin_z]


    # # for taltech map
    # #map_origion_error = [0,-300,0] 

    # #for Autonomous stuff   
    # map_origion_error = [0,0,0]

    #location = '/home/acclivis/adehome/PolyReports'
    auto_loc_file = location  + file_path + '/NDT_Pose_Localization.csv'
    lg_ego_file = location  + file_path + '/GNSS_ODOM_Localization.csv'
    
    auto_loc = Read_data(auto_loc_file)
    lg_ego_loc = Read_data(lg_ego_file)
    
    ComputeParams(auto_loc, lg_ego_loc, location + file_path, map_origion_error, avp_demo_flag)
    DeviationParams(location + file_path)
    
    
if __name__ == '__main__':
    main()