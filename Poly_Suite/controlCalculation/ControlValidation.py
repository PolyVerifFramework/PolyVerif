# -*- coding: utf-8 -*-
"""
Created on Fri Feb 19 17:34:24 2021

@author:
"""
import pandas as pd
import csv  
import os
from GenericParamComputation import GenericParams as gp
from ControlParamsComputation import ControlValidationParams as cv

from utils.acquisition_structures import Control_Val_Report


#function to compute various parameters
def ComputeParams(gt_data, control_data, percep_data,file_path):
    #opfilename = file_path + "control_params.csv"
    # gt_data = indata[["timestamp_sec", "timestamp_nanosec", "label", "position_x", "position_y", "position_z", "linear_velocity_x"]]
    gtd_stamping = gp.TimeStamp_Mapping(gt_data)
    ctl_stamping = gp.TimeStamp_Mapping(control_data)
    percep_stamping = gp.TimeStamp_Mapping(percep_data)
    
    control_params_gt_file = file_path + "/control_params_gt.csv"
    control_params_param_file = file_path + "/control_params_percep.csv"

    cv.TTC_GT(gt_data, control_data, gtd_stamping, ctl_stamping,control_params_gt_file)
    ttc_gt = Read_data(control_params_gt_file)
    
    cv.TTC_Perception(percep_data, control_data, percep_stamping, ctl_stamping, ttc_gt, control_params_param_file) 
    ttc_percep = Read_data(control_params_param_file)
    
    initial_ttc_gtd = cv.Initial_TTC(ttc_gt)
    print("inital_ttc_ gtd :: ",initial_ttc_gtd)
    initial_ttc_percep = cv.Initial_TTC(ttc_percep)
    print("initial_ttc_percep  :: ", initial_ttc_percep)
    
    percep_delay =initial_ttc_gtd - initial_ttc_percep
    print("percep_delay :: ", percep_delay)
    
    brake_applied = cv.Brake_Appied(control_data)
        
    line = [str(round(initial_ttc_gtd,2))+"\n",str(round(initial_ttc_percep,2))+"\n", str(round(percep_delay,2))+"\n",str(brake_applied)+"\n"]
    f = open(file_path + "/control_stats.txt", "w")
    f.writelines(line)
    f.close()
    # accel_deaccel_rate = cv.Accel_Deacceleration_Rate(control_data)

    # accel_deaccel_rate = cv.Accel_Deacceleration_Rate(control_data)
    

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
    print("adepath : ", adePath)
    location = adePath + '/'
    f_path = open(location + 'PolyReports/Validation_report/config1.txt', 'r')
    # PolyReports/Validation_report/01_04_2021__13_50_36/TC_3_CV
    path = f_path.readline()
    file_path = path.strip()
    f_path.close()
    print("Calculating Control params.")
#/home/acclivis/adehome/ PolyReports/Validation_report/01_04_2021__13_50_36/TC_3_CV
    gtd_filename = location + file_path + '/Objects_GTD.csv'
    control_filename = location + file_path + '/Ego_CanData.csv'
    percep_filename = location + file_path + '/Autoware_PerceptionData.csv'
    
    # gtd_filename = 'D:/Projects/PTS_Phase1/SourceCode/PTS_DataProcessing/20210311_set1/Objects_GTD_20210310.csv'
    # control_filename = 'D:/Projects/PTS_Phase1/SourceCode/PTS_DataProcessing/20210311_set1/Ego_CanData_20210310.csv'
    # percep_filename = 'D:/Projects/PTS_Phase1/SourceCode/PTS_DataProcessing/20210311_set1/Autoware_PerceptionData_20210310.csv'
    
    objects_data = Read_data(gtd_filename)
    control_data = Read_data(control_filename)
    percep_data =  Read_data(percep_filename)
    
    ComputeParams(objects_data, control_data, percep_data, location + file_path)
    
if __name__ == '__main__':
    main()
