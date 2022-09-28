# -*- coding: utf-8 -*-
"""
Created on Tue Feb 23 19:02:11 2021

@author: 
"""
class GenericParams(object):
  def __init__(self, filename=None):
      self.filename = filename

  #function to map timestamp and provide mapping between Ground Truth Data and Perception Data 
  def TimeStamp_Mapping(inputData_LG):
      print("Entering in TimeStampMatching function")
           
      stamping_LG = []
      nano_id = 0;
      for idx in range(inputData_LG["timestamp_sec"].count()-1):     
          #for idx_nano in range(inputData_LG["timestamp_nanosec"].count()-1):
          stamping_LG.append(nano_id)
          # print("timestamp_sec", inputData_LG.timestamp_sec[idx])
          # print("timestemp_nanosec", inputData_LG.timestamp_nanosec[idx])
          # print("nano_id", nano_id)
          if(inputData_LG.timestamp_nanosec[idx]!=inputData_LG.timestamp_nanosec[idx+1]):
              nano_id = nano_id+1;
          if inputData_LG.timestamp_sec[idx] != inputData_LG.timestamp_sec[idx+1]:
              nano_id = 0;
            
      print("Exiting from TimeStampMatching function")
      return stamping_LG

  #function to map objects between Grount Truth Data and Perception Data, use after TimestampMapping        
  def ObjectId_Mapping(inputData):
      print("Entering in IdMatching function")
      
      
      
      print("Exiting from IdMatching function")