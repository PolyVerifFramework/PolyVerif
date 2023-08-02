# -*- coding: utf-8 -*-
"""
Created on Wed Feb 24 13:05:09 2021

@author:
"""
#from scipy.spatial import distance
import math
import pandas as pd
from utils.acquisition_structures import DetectionRangeReport_Multi

class DetectionParams(object):
  def __init__(self, filename=None):
      self.filename = filename

  #function to check detection range of different objects
  def ObjectDetection_Range(matched_report):
      print("Entering in ObjectDetectionRange function")
      maxrange = [0.0, 0.0, 0.0, 0.0]
      for idx_match in range(matched_report["timestamp_sec"].count()):
          if (matched_report.match_found[idx_match] == True):
             if(maxrange[0] > matched_report.position_x[idx_match]):
                 maxrange[0] = matched_report.position_x[idx_match]
             elif(maxrange[1] < matched_report.position_x[idx_match]):
                 maxrange[1] = matched_report.position_x[idx_match]
          elif(matched_report.match_found[idx_match] == False):
             if(maxrange[2] > matched_report.position_x[idx_match]):
                 maxrange[2] = matched_report.position_x[idx_match]
             elif(maxrange[3] < matched_report.position_x[idx_match]):
                 maxrange[3] = matched_report.position_x[idx_match]
        
      print("Exiting from ObjectDetectionRange function")
      return maxrange
     
  #function to compute detection rate of objects using lidar sensor
  #comparison between GT and detetcion using lidar sensor 
  def ObjectDetection_Rate(matched_report):
      print("Entering in ObjectDetectionRate function")
      detections = 0
      count_no_objects = 0

      if(len(matched_report)==0):
          return 'NA'

      for idx_match in range(matched_report["timestamp_sec"].count()):
          if (matched_report.match_found[idx_match] == True):
              detections = detections + 1
          if (matched_report.label[idx_match] =="no_object"):
              count_no_objects = count_no_objects + 1
    
      
      detectionRate = (detections /(matched_report["timestamp_sec"].count() - count_no_objects)*100) 
      print("Exiting from ObjectDetectionRate function")
      return detectionRate
      
  #function to compare LG and Autoware data for object detection
  def ObjectDetection_RuleBased(inputData_GT, inputData_Per, gtd_stamping, percep_stamping):
      max_Y_deviation = 2.0 # denotes about lane 
      max_distance = 3.0 # change of position possible
      
      gtd_data = inputData_GT
      auto_percep_data = inputData_Per
      matching_report = []
      print("Entering in ObjectDetectionRate function")
      for idx_LG in range(gtd_data["timestamp_sec"].count()-1): 
        match_found = False
        if(gtd_data.label[idx_LG]!="no_object"):
            
            for idx_Auto in range(auto_percep_data["timestamp_sec"].count()-1):
                # print("idx_LG", idx_LG)
                # print("idx_Auto", idx_Auto)            
                if(gtd_data.timestamp_sec[idx_LG] == auto_percep_data.timestamp_sec[idx_Auto]):
                    if(gtd_stamping[idx_LG] == percep_stamping[idx_Auto]):
                        lg_pos = [gtd_data.position_x[idx_LG], gtd_data.position_y[idx_LG],0]
                        auto_pos = [auto_percep_data.corner_1_x[idx_Auto], auto_percep_data.centroid_y[idx_Auto],0]
                        # print(lg_pos)
                        # print(auto_pos)
                        #print("timestamp",auto_percep_data.timestamp_sec[idx_Auto])
                        #dist = distance.euclidean(lg_pos, auto_pos)
                        dist = math.sqrt((lg_pos[0]-auto_pos[0])**2 + (lg_pos[1]-auto_pos[1])**2 + (lg_pos[2]-auto_pos[2])**2)
                        diff_of_y = abs(auto_pos[1] - lg_pos[1])
                        #print("dist", dist)
                        if(dist < max_distance and diff_of_y < max_Y_deviation):
                            match_found = True
                        
            if match_found == True:
                matching_report.append("match_found")
                #print("matchfound")
                
            else:
                matching_report.append("no_match_found")
                #print("no match found")
                
        else:
            matching_report.append("no_object")
            print("no_object")

      print("Exiting from ObjectDetectionRate function")
      return matching_report
  
  #function to check detection range of different objects
  def ObjectDetection_Rate_MultiRange(matched_report, maxrange):
      # minrangeVal = round(maxrange[2]) # min range object from GroundTruth Data
      # maxrangeVal = round(maxrange[3]) # max range object from GroundTruth Data
      
      minrangeVal = -50
      maxrangeVal = 50
      interval = 10
      numRows = 10
      multirange_detection_rate  = pd.DataFrame(index=range(numRows), columns =['MinRange', 'MaxRange', 'SuccessRate', 'FailureRate'])
      count = 0
      temp = 0
      print("Entering in ObjectDetection_Rate_MultiRange function")
      for idx_minrange in range(minrangeVal, maxrangeVal, interval):
          count_det_success = 0
          count_det_failure = 0
          idx_maxrange = idx_minrange + interval
          # print("idx_minrange : ", idx_minrange)
          # print("idx_maxrange : ", idx_maxrange)
          
          for idx_match in range(matched_report["timestamp_sec"].count()-1):
              if(matched_report.label[idx_match] != "no_object"):
                  if(idx_minrange == minrangeVal):
                      if(matched_report.position_x[idx_match] <= idx_maxrange):
                          idx_minrange = float('-inf') 
                          if(matched_report.match_found[idx_match] == True):
                              count_det_success = count_det_success + 1 
                          else :
                              count_det_failure = count_det_failure + 1
                  
                  elif(idx_maxrange == maxrangeVal):
                      if(matched_report.position_x[idx_match] > idx_minrange):
                          idx_maxrange = float('inf') 
                          if(matched_report.match_found[idx_match] == True):
                              count_det_success = count_det_success + 1 
                          else :
                              count_det_failure = count_det_failure + 1

                  else:
                      if((matched_report.position_x[idx_match] > idx_minrange  and matched_report.position_x[idx_match] <= idx_maxrange)):
                          if(matched_report.match_found[idx_match] == True):
                              count_det_success = count_det_success + 1 
                          else :
                              count_det_failure = count_det_failure + 1

          # if(count_det_success !=0 or count_det_failure!=0):
          # print("count_det_success", count_det_success)
          # print("count_det_failure", count_det_failure)
          temp = temp +count_det_success +count_det_failure
          if(count ==0):
            multirange_detection_rate.MinRange[count]   = float('-inf')
            multirange_detection_rate.MaxRange[count]   = idx_maxrange
          elif(count==9):
            multirange_detection_rate.MinRange[count]   = idx_minrange
            multirange_detection_rate.MaxRange[count]   = float('inf')
          else:
            multirange_detection_rate.MinRange[count]   = idx_minrange
            multirange_detection_rate.MaxRange[count]   = idx_maxrange

          if(count_det_success !=0 or count_det_failure!=0):
            multirange_detection_rate.SuccessRate[count] = count_det_success*100 / (count_det_success + count_det_failure)
            multirange_detection_rate.FailureRate[count] = count_det_failure*100 / (count_det_success + count_det_failure)
          else:
            multirange_detection_rate.SuccessRate[count] = -9999
            multirange_detection_rate.FailureRate[count] = -9999
      
          count = count + 1
          
      print("Exiting from ObjectDetection_Rate_MultiRange function")
      return multirange_detection_rate