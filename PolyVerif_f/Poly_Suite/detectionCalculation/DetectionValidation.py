# -*- coding: utf-8 -*-
"""
Created on Tue Mar  2 13:19:14 2021

@author: 
"""
import os
import pandas as pd
import csv  

#from scipy.spatial import distance

from GenericParamComputation import GenericParams as gp
from DetectionParamsComputation import DetectionParams as pp
from utils.acquisition_structures import Objects_Report
from utils.acquisition_structures import DetectionRangeReport_Multi

 
#function to save matching report
def Detection_Validation(gtd_data, auto_percep_data,file_path):
    matching_report_File = file_path + '/Perception_Report.csv'
    with open(matching_report_File,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Objects_Report("timestamp_sec" ,"timestamp_nanosec", "label", "position_x", "position_y", "position_z", "size_x", "size_y", "size_z", "match_found")
        writer.writerow(title)
    
    #read only relevant data
    # object_gtd_data = gtd_data[["timestamp_sec", "timestamp_nanosec", "label", "position_x", "position_y"]]
    # object_percep_data = auto_percep_data[["timestamp_sec","timestamp_nanosec","vehicle_label","corner_1_x","corner_1_y","corner_2_x","corner_2_y","corner_3_x","corner_3_y","corner_4_x","corner_4_y",]]
    
    gtd_stamping = gp.TimeStamp_Mapping(gtd_data) 
    percep_stamping = gp.TimeStamp_Mapping(auto_percep_data)
    
    # Call Object Detection_Rule based method 
    matching_report = pp.ObjectDetection_RuleBased(gtd_data, auto_percep_data, gtd_stamping, percep_stamping)
    
    # matching_data = pd.DataFrame(columns=["timestamp_sec" ,"timestamp_nanosec", "label", "position_x", "position_y", "position_z", "size_x", "size_y", "size_z", "match_found"])
    #Save csv report
    with open(matching_report_File,'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for idx_LG in range(len(matching_report)):
            if(matching_report[idx_LG] == "match_found"):
                    matched_data = Objects_Report(gtd_data.timestamp_sec[idx_LG],gtd_data.timestamp_nanosec[idx_LG],
                                                  gtd_data.label[idx_LG], gtd_data.position_x[idx_LG], 
                                                  gtd_data.position_y[idx_LG], gtd_data.position_z[idx_LG],
                                                  gtd_data.size_x[idx_LG], gtd_data.size_y[idx_LG],
                                                  gtd_data.size_z[idx_LG], True)
                    writer.writerow(matched_data)
            elif(matching_report[idx_LG] == "no_match_found"):
                    unmatched_data = Objects_Report(gtd_data.timestamp_sec[idx_LG],gtd_data.timestamp_nanosec[idx_LG],
                                                gtd_data.label[idx_LG], gtd_data.position_x[idx_LG], 
                                                gtd_data.position_y[idx_LG], gtd_data.position_z[idx_LG],
                                                gtd_data.size_x[idx_LG], gtd_data.size_y[idx_LG],
                                                gtd_data.size_z[idx_LG], False)
                    writer.writerow(unmatched_data)
            else :
                      unmatched_data = Objects_Report(gtd_data.timestamp_sec[idx_LG],gtd_data.timestamp_nanosec[idx_LG],
                                                 gtd_data.label[idx_LG], gtd_data.position_x[idx_LG], 
                                                 gtd_data.position_y[idx_LG], gtd_data.position_z[idx_LG],
                                                 gtd_data.size_x[idx_LG], gtd_data.size_y[idx_LG],
                                                 gtd_data.size_z[idx_LG], False)
                      writer.writerow(unmatched_data)

#function to compute various parameters
def ComputeParams(gtd_data, auto_percep_data,file_path):
    Detection_Validation(gtd_data, auto_percep_data,file_path)
    matching_report_File = file_path +'/Perception_Report.csv'

    matched_report = Read_data(matching_report_File) 
    
    maxrange = pp.ObjectDetection_Range(matched_report)
      
    detectionRate = pp.ObjectDetection_Rate(matched_report)
    detectionRate = round(detectionRate, 2)
    
    multirange_detection_rate = pp.ObjectDetection_Rate_MultiRange(matched_report, maxrange)
    
    print("Max Range Object Detected by Autoware Detection : ", maxrange[0:2])
    print("Max Range Object in LG GroundTruth : ", maxrange[2:4])
    print("Object Detection Success Rate in Percentage : ", detectionRate)
    #print("Object Detection Failure Rate in Rercentage : ", 100 - detectionRate)
    
    auto_range = str(round(maxrange[0]))+ " to " +  str(round(maxrange[1]))
    lg_range = str(round(maxrange[2]))+ " to " +  str(round(maxrange[3]))
    
    #line = [auto_range+"\n",lg_range+"\n", str(detectionRate)+"\n",str(100-detectionRate)+"\n"]
    line = [auto_range+"\n",lg_range+"\n", str(detectionRate)+"\n"]

    f = open(file_path +"/perception_stats.txt", "w+")
    f.writelines(line)
    f.close()

    with open(file_path + "/rangeReport.csv",'w+', newline='') as csvfile:
            writer = csv.writer(csvfile)
            title = DetectionRangeReport_Multi("Range", "SuccessRate")
            writer.writerow(title) 
    with open(file_path + "/rangeReport.csv",'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for idx in range(len(multirange_detection_rate)):
            print("minRange", multirange_detection_rate.MinRange[idx])
            print("maxRange", multirange_detection_rate.MaxRange[idx])
            print("multirange_detection_rate - Success" , multirange_detection_rate.SuccessRate[idx])
            print("multirange_detection_rate - Failure" , multirange_detection_rate.FailureRate[idx])
            DetectionRange =  str(multirange_detection_rate.MinRange[idx]) + " to " + str(multirange_detection_rate.MaxRange[idx])
    
            rangedata = DetectionRangeReport_Multi(DetectionRange,
                                                   multirange_detection_rate.SuccessRate[idx])
                
            if(multirange_detection_rate.SuccessRate[idx] ==-9999):  #@shiv
                    rangedata = DetectionRangeReport_Multi(DetectionRange, 'NA')#@shiv
            writer.writerow(rangedata)
            
    print("Check Computed Params")
    
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
    print("Calculating Detection Params.")
    #set files and thier paths
    gtd_filename = location + file_path + "/Objects_GTD_Perception.csv"
    auto_percep_file = location + file_path+ "/Autoware_PerceptionData.csv"
    
    gtd_data = Read_data(gtd_filename) # read ground truth data
    auto_percep_data = Read_data(auto_percep_file) # read perception data from Autoware
    ComputeParams(gtd_data, auto_percep_data, location + file_path)
    
    
    
if __name__ == '__main__':
    main()