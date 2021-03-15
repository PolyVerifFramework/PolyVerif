# -*- coding: utf-8 -*-
"""
Created on Fri Feb 19 17:34:24 2021

@author: Acclivis Technologies Pvt Ltd.
"""
import pandas as pd
from GenericParamComputation import GenericParams as gp
from ControlParamsComputation import ControlValidationParams as cv

#function to compute various parameters
def ComputeParams(data, control_data):
    gt_data = data[["timestamp_sec","timestamp_nanosec", "label","position_x","position_y", "linear_velocity_x"]]
    gtd_stamping = gp.TimeStamp_Mapping(gt_data)
    ttc_op = cv.TTC_GT(gt_data, control_data, gtd_stamping)
    initial_ttc = cv.Initial_TTC(ttc_op)
    accel_deaccel_rate = cv.Accel_DeaccelerationRate(control_data)
    

#function to read GT data using given filename
def Read_GTdata(filename):
    data = pd.read_csv(filename)
    #print(data.to_string()) 
    return data

#main function for calling various functions available in various classes
def main(args=None):
    print("Calculating Control params.")
    gtd_filename = 'D:/Projects/PTS_Phase1/SourceCode/PTS_DataProcessing/20210301_Set2/Objects_GTD.csv'
    control_filename = 'D:/Projects/PTS_Phase1/SourceCode/PTS_DataProcessing/20210301_Set2/Ego_CanData.csv'
    
    # percep_filename = ''
    objects_data = Read_GTdata(gtd_filename)
    control_data = Read_GTdata(control_filename)
    
    ComputeParams(objects_data, control_data)
    
if __name__ == '__main__':
    main()
