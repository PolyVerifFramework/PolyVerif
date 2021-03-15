# -*- coding: utf-8 -*-
"""
Created on Tue Feb 23 14:48:13 2021

@author: Acclivis Technologies Pvt Ltd.
"""

class ControlValidationParams(object):
        
  def __init__(self, filename=None):
      self.filename = filename
      
  def TTC(inputData):
      print("ENtering TTC function")
      
      
      
      print("Exiting from TTC funvtion")
      
  #function to compute Time to Collision using GT data   
  def TTC_GT(inputData, control_data, gtd_stamping):
    print("Entering in TTC_GT function")
    ttc_op = []
    max_Y_deviation = 2.0
    for idx in range(inputData["timestamp_sec"].count()):  
      if inputData.label[idx] != "no_object":
          
          # if lgstamp == lg_gt_stamp or lgstamp == lg_gt_stamp -1:
          #    report_file.write("Time Stamp : "+ str(lgstamp) +"\n") 
          lg_pos_x = inputData.position_x[idx]
          lg_pos_y = inputData.position_y[idx]
          ego_linear_velocities = control_data.speed[idx]
          #print("Lg box x position : ", lg_pos_x)
          lg_velocity_x = inputData.linear_velocity_x[idx]
          print("Speed of the Non Ego : ", lg_velocity_x)
          
          # ego, nonego velocities,  nonego position, ego brake
          # distance 
          #ttc = (ego_linear_velocities - 4) /(ego_linear_velocities - lg_velocity_x)
          # validation to check lane position
          if(inputData.position_y <= max_Y_deviation): 
              ttc = abs((lg_pos_x - 4) /(ego_linear_velocities - lg_velocity_x))
              ttc_op.append(ttc)
                  
          ttc_op.append(0.0)
      else:
          ttc_op.append(0.0)

          print(" Time to Collision : ", ttc)
      
    print("Exiting from TTC_GT function")
    return ttc_op

  #fuction to compute time to collision afer perception of software stack
  def TTC_Perception(inputData):
      print("Entering in TTC_Perception function")
      
      
      
      print("Exiting from TTC_Perception function")
     
  def Initial_TTC(ttc_op):
      print("Entering in Initial_TTC function")
      initial_ttc = ttc_op[0]
      
      print("Exiting from Initial_TTC function")
      return initial_ttc

  #function to compute acceleration rate and deacceleration rate of ego vehicle
  def Accel_Deacceleration_Rate(control_data):
      print("Entering in Accel_DeaccelerationRate function")
      max_Y_deviation = 2.0
      accel_deaccel_rate = []
      accel_deaccel_rate.append(0.0)
      for idx in range(control_data["timestamp_sec"].count()-1):  
           vel_change = control_data.speed(idx+1) - control_data.speed(idx)
           accel_deaccel_rate.append(vel_change)
           
      print("Exiting from Accel_DeaccelerationRate function")
      return accel_deaccel_rate
      
      
