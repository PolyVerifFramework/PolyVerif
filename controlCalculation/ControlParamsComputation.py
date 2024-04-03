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
    ttc_op = pd.DataFrame(index=np.arange(0, inputData["timestamp_sec"].count()), data = [Control_Val_Report("timestamp_sec", "timestamp_nanosec", "object_label", "position_x", "position_y",
                                                     "position_z", "orientation_x","orientation_y","orientation_z", "ttc_val", "brake_state",
                                                     "accel_deaccel_rate")])
    with open(opfilename,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Control_Val_Report("timestamp_sec", "timestamp_nanosec", "object_label", "position_x", "position_y",
                                                      "position_z", "orientation_x","orientation_y","orientation_z", "ttc_val", "brake_state",
                                                      "accel_deaccel_rate")
        writer.writerow(title)                         
    max_Y_deviation = 5.0
    detected_Vehicle_Pos=50
    count = 0
    with open(opfilename,'a', newline='') as csvfile:
        writer = csv.writer(csvfile)
        for idx_LG in range(inputData["timestamp_sec"].count()-1):  
          if inputData.object_label[idx_LG] != "no_object":
           if(abs(inputData.position_x[idx_LG])<=detected_Vehicle_Pos):  
              for idx_ctl in range(1,control_data["timestamp_sec"].count()-1):
                  if(inputData.timestamp_sec[idx_LG] == control_data.timestamp_sec[idx_ctl]):
                      if(gtd_stamping[idx_LG] == ctl_stamping[idx_ctl]):
                         
                          lg_pos_x = inputData.position_x[idx_LG]
                          lg_pos_y = abs(inputData.position_y[idx_LG])
                          ego_linear_velocities = control_data.longitudinal_velocity[idx_ctl]
                          
                          lg_velocity_x = inputData.linear_x[idx_LG]
                          #print("Speed of the Non Ego : ", lg_velocity_x)
                          
                          # ego, nonego velocities,  nonego position, ego brake
                          # distance 
                          #ttc = (ego_linear_velocities - 4) /(ego_linear_velocities - lg_velocity_x)
                          # validation to check lane position
                          if(lg_pos_y <= max_Y_deviation): 
                              count = count+1
                              ttc = abs((lg_pos_x - 4) /(ego_linear_velocities - lg_velocity_x))
                            #   print("lg_pos_x :",lg_pos_x,lg_pos_y,inputData.object_label[idx_LG],inputData.timestamp_sec[idx_LG])
                            #   print("ego_linear_velocities:",ego_linear_velocities)
                            #   print("lg_velocity_x:",lg_velocity_x)
                              vel_change = control_data.longitudinal_velocity[idx_ctl] - control_data.longitudinal_velocity[idx_ctl-1]
                              print(" Time to Collision : ", ttc,lg_pos_y)
                              
                              matched_data = Control_Val_Report(inputData.timestamp_sec[idx_LG], inputData.timestamp_nanosec[idx_LG],
                                                    inputData.object_label[idx_LG], inputData.position_x[idx_LG], 
                                                    inputData.position_y[idx_LG], inputData.position_z[idx_LG],
                                                    inputData.orientation_x[idx_LG], inputData.orientation_y[idx_LG],
                                                    inputData.orientation_z[idx_LG], ttc,1,round(vel_change,2))
                              writer.writerow(matched_data)
                           

    print("Exiting from TTC_GT function")
    return ttc_op

  #fuction to compute time to collision afer perception of software stack
  def TTC_Perception(inputData, control_data, percep_stamping, ctl_stamping, ttc_gt, opfilename):
      print("Entering in TTC_Perception function")
      #opfilename = "control_params_percep.csv"
     
      with open(opfilename,'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        title = Control_Val_Report("timestamp_sec", "timestamp_nanosec", "label", "position_x", "position_y",
                                                      "position_z", "orientation_x","orientation_y","orientation_z", "ttc_val", "brake_state",
                                                      "accel_deaccel_rate")
        writer.writerow(title)                         
      max_Y_deviation = 5.0
      detected_Vehicle_Pos = 50
      count = 0
      with open(opfilename,'a', newline='') as csvfile:
          writer = csv.writer(csvfile)
          for idx_LG in range(inputData["timestamp_sec"].count()-1):  
            if inputData.object_label[idx_LG] != "no_object":
             if(abs(inputData.position_x[idx_LG])<=detected_Vehicle_Pos):
              for idx_ctl in range(1,control_data["timestamp_sec"].count()-1):
                
                  if(inputData.timestamp_sec[idx_LG] == control_data.timestamp_sec[idx_ctl]):                       
                      if(percep_stamping[idx_LG] == ctl_stamping[idx_ctl]):
                         #shoukat
                          #lg_pos_x = inputData.corner_1_x[idx_LG]
                          # lg_pos_y = 5
                          lg_pos_x=inputData.position_x[idx_LG]
                          lg_pos_y = abs(inputData.position_y[idx_LG])
                         
    
                          
                          #shoukat
                        #   for idx_corners in range(0,3):
                        #      if idx_corners ==0:
                        #         temp_y = abs(inputData.corner_1_y[idx_LG])
                        #         if lg_pos_y > temp_y:
                        #           lg_pos_y = temp_y
                        #      elif idx_corners==1:
                        #         temp_y = abs(inputData.corner_2_y[idx_LG])
                        #         if lg_pos_y > temp_y:
                        #           lg_pos_y = temp_y
                        #      elif idx_corners==2:
                        #         temp_y = abs(inputData.corner_3_y[idx_LG])
                        #         if lg_pos_y > temp_y:
                        #           lg_pos_y = temp_y
                        #      else:
                        #         temp_y = abs(inputData.corner_4_y[idx_LG])
                        #         if lg_pos_y > temp_y:
                        #           lg_pos_y = temp_y
    
                          ego_linear_velocities = control_data.longitudinal_velocity[idx_ctl]
                          #print("Lg box x position : ", lg_pos_x)
                          lg_velocity_x = inputData.linear_x[idx_LG]
                          #print("Speed of the Non Ego : ", lg_velocity_x)
                          
                          # ego, nonego velocities,  nonego position, ego brake
                          # distance 
                          #ttc = (ego_linear_velocities - 4) /(ego_linear_velocities - lg_velocity_x)
                          # validation to check lane position
                          if(lg_pos_y <= max_Y_deviation): 
                              ttc_gt_avail = False
                              for idx_ttc_gt in range (ttc_gt["timestamp_sec"].count()-1):
                                 if(inputData.timestamp_sec[idx_LG] == ttc_gt.timestamp_sec[idx_ttc_gt]):
                                    #if(inputData.object_label[idx_LG]==ttc_gt.object_label[idx_ttc_gt]): 
                                         ttc_gt_avail = True
                                        #  print("Sec:",inputData.timestamp_sec[idx_LG],ttc_gt.timestamp_sec[idx_ttc_gt])
                                        #  print("Pos:",inputData.position_x[idx_LG],ttc_gt.position_x[idx_ttc_gt])
                                        #  print("Label:",inputData.object_label[idx_LG],ttc_gt.object_label[idx_ttc_gt])
                                         break
                              if(ttc_gt_avail ==True):
                                  ttc = abs((lg_pos_x - 4) /(ego_linear_velocities - lg_velocity_x))
                                #   print("lg_pos_x :",lg_pos_x - 4)
                                #   print("ego_linear_velocities:",ego_linear_velocities)
                                #   print("lg_velocity_x:",lg_velocity_x)
                                  vel_change = control_data.longitudinal_velocity[idx_ctl] - control_data.longitudinal_velocity[idx_ctl-1]
                                  print(" Time to Collision : ", ttc)
                                 #shoukat 
                                  matched_data = Control_Val_Report(inputData.timestamp_sec[idx_LG], inputData.timestamp_nanosec[idx_LG],
                                                        inputData.object_label[idx_LG], inputData.position_x[idx_LG], 
                                                        inputData.position_y[idx_LG], inputData.position_z[idx_LG],
                                                        inputData.orientation_x[idx_LG], inputData.orientation_y[idx_LG],
                                                        inputData.orientation_z[idx_LG], ttc, 1, round(vel_change,2))
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
           vel_change = control_data.longitudinal_velocity[idx+1]- control_data.longitudinal_velocity[idx]
           accel_deaccel_rate.append(vel_change)
           
      print("Exiting from Accel_DeaccelerationRate function")
      return accel_deaccel_rate
        
  def Brake_Appied(control_data):
      brake_applied_status = False
      for idx in range(control_data["timestamp_sec"].count()-1):
          if(control_data.Braking[idx]==1):
              brake_applied_status = True
      
      return brake_applied_status