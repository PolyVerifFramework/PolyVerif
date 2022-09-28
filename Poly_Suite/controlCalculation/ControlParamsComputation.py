# -*- coding: utf-8 -*-
"""
Created on Tue Feb 23 14:48:13 2021

@author: 
"""
import pandas as pd
import numpy as np
import csv  


from utils.acquisition_structures import Control_Val_Report
class ControlValidationParams(object):
        
  def __init__(self, filename=None):
      self.filename = filename
      
  def TTC(inputData):
      print("ENtering TTC function")
      print("Exiting from TTC funvtion")
      
  #function to compute Time to Collision using GT data   
  def TTC_GT(inputData, control_data, gtd_stamping, ctl_stamping,opfilename):
    print("Entering in TTC_GT function")
    #opfilename = "control_params_gt.csv"
    ttc_op = pd.DataFrame(index=np.arange(0, inputData["timestamp_sec"].count()), data = [Control_Val_Report("timestamp_sec", "timestamp_nanosec", "label", "position_x", "position_y",
                                                     "position_z", "size_x","size_y","size_z", "ttc_val", "brake_state",
                                                     "accel_deaccel_rate")])
    with open(opfilename,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Control_Val_Report("timestamp_sec", "timestamp_nanosec", "label", "position_x", "position_y",
                                                      "position_z", "size_x","size_y","size_z", "ttc_val", "brake_state",
                                                      "accel_deaccel_rate")
        writer.writerow(title)                         
    max_Y_deviation = 2.0
    count = 0
    with open(opfilename,'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for idx_LG in range(inputData["timestamp_sec"].count()-1):  
          if inputData.label[idx_LG] != "no_object":
              for idx_ctl in range(1,control_data["timestamp_sec"].count()-1):
                  # print("idx_LG", idx_LG)
                  # print("idx_ctl", idx_ctl)
                  if(inputData.timestamp_sec[idx_LG] == control_data.timestamp_sec[idx_ctl]):
                      # print("idx_LG", idx_LG)
                      # print("idx_ctl", idx_ctl)
                      if(gtd_stamping[idx_LG] == ctl_stamping[idx_ctl]):
                          # print("gtd_stamping", gtd_stamping[idx_LG])
                          # print("ctl_stamping", ctl_stamping[idx_ctl])
                          # if lgstamp == lg_gt_stamp or lgstamp == lg_gt_stamp -1:
                          #    report_file.write("Time Stamp : "+ str(lgstamp) +"\n") 
                          lg_pos_x = inputData.position_x[idx_LG]
                          lg_pos_y = abs(inputData.position_y[idx_LG])
                          ego_linear_velocities = control_data.Speed[idx_ctl]
                          #print("Lg box x position : ", lg_pos_x)
                          lg_velocity_x = inputData.linear_velocity_x[idx_LG]
                          #print("Speed of the Non Ego : ", lg_velocity_x)
                          
                          # ego, nonego velocities,  nonego position, ego brake
                          # distance 
                          #ttc = (ego_linear_velocities - 4) /(ego_linear_velocities - lg_velocity_x)
                          # validation to check lane position
                          if(lg_pos_y <= max_Y_deviation): 
                              count = count+1
                              ttc = abs((lg_pos_x - 4) /(ego_linear_velocities - lg_velocity_x))
                              
                              vel_change = control_data.Speed[idx_ctl] - control_data.Speed[idx_ctl-1]
                              print(" Time to Collision : ", ttc)
                              
                              matched_data = Control_Val_Report(inputData.timestamp_sec[idx_LG], inputData.timestamp_nanosec[idx_LG],
                                                    inputData.label[idx_LG], inputData.position_x[idx_LG], 
                                                    inputData.position_y[idx_LG], inputData.position_z[idx_LG],
                                                    inputData.size_x[idx_LG], inputData.size_y[idx_LG],
                                                    inputData.size_z[idx_LG], ttc, control_data.Braking[idx_ctl], round(vel_change,2))
                              writer.writerow(matched_data)
                              # print("ttc_op", ttc_op)
                              # print("ttc_data", ttc_data)
                          
                               

    print("Exiting from TTC_GT function")
    return ttc_op

  #fuction to compute time to collision afer perception of software stack
  def TTC_Perception(inputData, control_data, percep_stamping, ctl_stamping, ttc_gt, opfilename):
      print("Entering in TTC_Perception function")
      #opfilename = "control_params_percep.csv"
     
      with open(opfilename,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Control_Val_Report("timestamp_sec", "timestamp_nanosec", "label", "position_x", "position_y",
                                                      "position_z", "size_x","size_y","size_z", "ttc_val", "brake_state",
                                                      "accel_deaccel_rate")
        writer.writerow(title)                         
      max_Y_deviation = 2.0
      detected_Vehicle_Size = 3.0
      count = 0
      with open(opfilename,'a', newline='') as csvfile:
          writer = csv.writer(csvfile)
          for idx_LG in range(inputData["timestamp_sec"].count()-1):  
            if inputData.vehicle_label[idx_LG] != "no_object":
             if(inputData.size_y[idx_LG]<=detected_Vehicle_Size):
              for idx_ctl in range(1,control_data["timestamp_sec"].count()-1):
                  # print("idx_LG", idx_LG)
                  # print("idx_ctl", idx_ctl)
                  if(inputData.timestamp_sec[idx_LG] == control_data.timestamp_sec[idx_ctl]):
                      # print("idx_LG", idx_LG)
                      # print("idx_ctl", idx_ctl)
                    
                      if(percep_stamping[idx_LG] == ctl_stamping[idx_ctl]):
                          # print("gtd_stamping", gtd_stamping[idx_LG])
                          # print("ctl_stamping", ctl_stamping[idx_ctl])
                          # if lgstamp == lg_gt_stamp or lgstamp == lg_gt_stamp -1:
                          #    report_file.write("Time Stamp : "+ str(lgstamp) +"\n") 
                          lg_pos_x = inputData.corner_1_x[idx_LG]
                          lg_pos_y = 50
    
                          #lg_pos_y = abs(inputData.corner_1_y[idx_LG])
                          for idx_corners in range(0,3):
                             if idx_corners ==0:
                                temp_y = abs(inputData.corner_1_y[idx_LG])
                                if lg_pos_y > temp_y:
                                  lg_pos_y = temp_y
                             elif idx_corners==1:
                                temp_y = abs(inputData.corner_2_y[idx_LG])
                                if lg_pos_y > temp_y:
                                  lg_pos_y = temp_y
                             elif idx_corners==2:
                                temp_y = abs(inputData.corner_3_y[idx_LG])
                                if lg_pos_y > temp_y:
                                  lg_pos_y = temp_y
                             else:
                                temp_y = abs(inputData.corner_4_y[idx_LG])
                                if lg_pos_y > temp_y:
                                  lg_pos_y = temp_y
    
                          ego_linear_velocities = control_data.Speed[idx_ctl]
                          #print("Lg box x position : ", lg_pos_x)
                          lg_velocity_x = inputData.velocity[idx_LG]
                          #print("Speed of the Non Ego : ", lg_velocity_x)
                          
                          # ego, nonego velocities,  nonego position, ego brake
                          # distance 
                          #ttc = (ego_linear_velocities - 4) /(ego_linear_velocities - lg_velocity_x)
                          # validation to check lane position
                          if(lg_pos_y <= max_Y_deviation): 
                              ttc_gt_avail = False
                              for idx_ttc_gt in range (ttc_gt["timestamp_sec"].count()-1):
                                 #print("idx_ttc_gt", idx_ttc_gt)
                                 if(inputData.timestamp_sec[idx_LG] == ttc_gt.timestamp_sec[idx_ttc_gt]):
                                        #print("idx_LG", idx_LG)
                                         ttc_gt_avail = True
                                         break;
                              if(ttc_gt_avail ==True):
                                  count = count+1
                                  ttc = abs((lg_pos_x - 4) /(ego_linear_velocities - lg_velocity_x))
                                  
                                  vel_change = control_data.Speed[idx_ctl] - control_data.Speed[idx_ctl-1]
                                  print(" Time to Collision : ", ttc)
                                  
                                  matched_data = Control_Val_Report(inputData.timestamp_sec[idx_LG], inputData.timestamp_nanosec[idx_LG],
                                                        inputData.vehicle_label[idx_LG], inputData.corner_1_x[idx_LG], 
                                                        inputData.corner_1_y[idx_LG], inputData.corner_1_z[idx_LG],
                                                        inputData.size_x[idx_LG], inputData.size_y[idx_LG],
                                                        inputData.size_z[idx_LG], ttc, control_data.Braking[idx_ctl], round(vel_change,2))
                                  writer.writerow(matched_data)      
      
      print("Exiting from TTC_Perception function")
     
  def Initial_TTC(ttc_op):
      initial_ttc = 0
      print("Entering in Initial_TTC function")
      if(len(ttc_op)>0):
          initial_ttc = ttc_op.ttc_val[0]

      print("Exiting from Initial_TTC function")
      return initial_ttc

  #function to compute acceleration rate and deacceleration rate of ego vehicle
  def Accel_Deacceleration_Rate(control_data):
      print("Entering in Accel_DeaccelerationRate function")
      max_Y_deviation = 2.0
      accel_deaccel_rate = []
      accel_deaccel_rate.append(0.0)
      for idx in range(control_data["timestamp_sec"].count()-1):  
           vel_change = control_data.Speed[idx+1]- control_data.Speed[idx]
           accel_deaccel_rate.append(vel_change)
           
      print("Exiting from Accel_DeaccelerationRate function")
      return accel_deaccel_rate
        
  def Brake_Appied(control_data):
      brake_applied_status = False
      for idx in range(control_data["timestamp_sec"].count()-1):
          if(control_data.Braking[idx]==1):
              brake_applied_status = True
      
      return brake_applied_status