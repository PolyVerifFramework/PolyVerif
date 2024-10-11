# -*- coding: utf-8 -*-
"""
Created on Wed Feb 24 13:05:09 2021

@author:
"""
# from scipy.spatial import distance
import math
import pandas as pd
from utils.acquisition_structures import DetectionRangeReport_Multi


class DetectionParams(object):
    def __init__(self, filename=None):
        self.filename = filename

    # function to check detection range of different objects
    def ObjectDetection_Range(matched_report):
        print("Entering in ObjectDetectionRange function")
        maxrange = [0.0, 0.0, 0.0, 0.0]
        for idx_match in range(matched_report["timestamp_sec"].count()):
            if (matched_report.match_found[idx_match] == True):
                if (maxrange[0] > matched_report.position_x[idx_match]):
                    maxrange[0] = matched_report.position_x[idx_match]

                elif (maxrange[1] < matched_report.position_x[idx_match]):
                    maxrange[1] = matched_report.position_x[idx_match]


        print("Exiting from ObjectDetectionRange function")
        return maxrange

    # function to compute detection rate of objects using lidar sensor
    # comparison between GT and detetcion using lidar sensor
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


    # New function to calculate additional metrics
    def Calculate_Additional_Metrics(matched_report):
        no_object = 0
        for idx_match in range(matched_report["timestamp_sec"].count()):
            if (matched_report.label[idx_match] =="no_object"):
                no_object = no_object + 1

        true_positive = sum((matched_report.match_found == True) )
        if "Pedestrian" in matched_report.label.values:
            false_positive = sum((matched_report.match_found == True) & (matched_report.label == "Pedestrian"))
        else:
            false_positive = 0

        false_negative = sum((matched_report.match_found == False) ) - no_object
        total_positives = true_positive + false_negative
        
        
        precision = (true_positive / (true_positive + false_positive))*100 if (true_positive + false_positive) > 0 else 0
        missclassification = (false_positive / (true_positive + false_positive))*100 if (true_positive + false_positive) > 0 else 0
        false_negative_rate = (false_negative / (matched_report["timestamp_sec"].count() - no_object))*100
        

        return precision, missclassification ,false_negative_rate

    #function to compare LG and Autoware data for object detection
    def ObjectDetection_RuleBased(inputData_GT, inputData_Per, gtd_stamping, percep_stamping):
        max_Y_deviation = 3.0 # denotes about lane width 
        max_distance = 4.0 # change of position possible
        
        gtd_data = inputData_GT
        auto_percep_data = inputData_Per
        matching_report = []
        print("Entering in ObjectDetectionRate function")
        for idx_LG in range(gtd_data["timestamp_sec"].count()-1): 
            match_found = False
            if(gtd_data.label[idx_LG]!="no_object"):
                
                for idx_Auto in range(auto_percep_data["timestamp_sec"].count()-1):
                     
                    if (gtd_data.timestamp_sec[idx_LG] != auto_percep_data.timestamp_sec[idx_Auto]):
                        match_found = None
                        continue
                        
                    elif(gtd_data.timestamp_sec[idx_LG] == auto_percep_data.timestamp_sec[idx_Auto]):
                        # if(gtd_stamping[idx_LG] == percep_stamping[idx_Auto]):
                            lg_pos = [gtd_data.position_x[idx_LG], gtd_data.position_y[idx_LG],0]
                            auto_pos = [auto_percep_data.corner_1_x[idx_Auto], auto_percep_data.centroid_y[idx_Auto],0]
                            dist = math.sqrt((lg_pos[0]-auto_pos[0])**2 + (lg_pos[1]-auto_pos[1])**2 + (lg_pos[2]-auto_pos[2])**2)
                            diff_of_y = abs(auto_pos[1] - lg_pos[1])
                            if(dist < max_distance and diff_of_y < max_Y_deviation):
                                match_found = True
                                break
                            elif ((dist < 13.0 and diff_of_y < max_Y_deviation) and (gtd_data.label[idx_LG] in ["BoxTruck","SchoolBus"])):
                                match_found = True
                                break
                            else:
                                match_found = False

                if match_found == True:
                    matching_report.append("match_found")
                   
        
                elif match_found == None:
                    continue
                    
                else:
                    matching_report.append("no_match_found")
            else:
                matching_report.append("no_object")
                print("no_object")

        print("Exiting from ObjectDetectionRate function")
        return matching_report



    def ObjectDetection_Rate_MultiRange(matched_report, maxrange):
        # Define the min and max ranges
        minrangeVal = -90
        maxrangeVal = 90
        interval = 30
        numRows = 6  # Number of intervals required

        # Create a DataFrame to store the results
        multirange_detection_rate = pd.DataFrame(index=range(numRows), columns=[
            'Heading', 'MinRange', 'MaxRange', 'SuccessRate', 'FailureRate', 'Conclusion'])

        count = 0
        print("Entering ObjectDetection_Rate_MultiRange function")

        # Iterate over the range intervals
        for idx_minrange in range(minrangeVal, maxrangeVal, interval):
            count_det_success = 0
            count_det_failure = 0
            idx_maxrange = idx_minrange + interval

            # Process the matched report
            for idx_match in range(matched_report["timestamp_sec"].count()-1):
                if matched_report.label[idx_match] != "no_object":
                    if idx_minrange == minrangeVal:
                        if matched_report.position_x[idx_match] <= idx_maxrange:
                            if matched_report.match_found[idx_match]:
                                count_det_success += 1
                            else:
                                count_det_failure += 1

                    elif idx_maxrange == maxrangeVal:
                        if matched_report.position_x[idx_match] > idx_minrange:
                            if matched_report.match_found[idx_match]:
                                count_det_success += 1
                            else:
                                count_det_failure += 1

                    else:
                        if idx_minrange < matched_report.position_x[idx_match] <= idx_maxrange:
                            if matched_report.match_found[idx_match]:
                                count_det_success += 1
                            else:
                                count_det_failure += 1

            # Store the results in the DataFrame
            multirange_detection_rate.MinRange[count] = idx_minrange
            multirange_detection_rate.MaxRange[count] = idx_maxrange

            if count_det_success != 0 or count_det_failure != 0:
                success_rate = count_det_success * 100 / (count_det_success + count_det_failure)
                failure_rate = count_det_failure * 100 / (count_det_success + count_det_failure)
                multirange_detection_rate.SuccessRate[count] = round(success_rate, 2)
                multirange_detection_rate.FailureRate[count] = round(failure_rate, 2)
            else:
                success_rate = failure_rate = -9999
                multirange_detection_rate.SuccessRate[count] = success_rate
                multirange_detection_rate.FailureRate[count] = failure_rate

            # Determine the conclusion based on detection rates
            if success_rate > 50:
                multirange_detection_rate.Conclusion[count] = "Object present"
            else:
                multirange_detection_rate.Conclusion[count] = "Object not reliably detected"

            # Assign heading based on the position (front or rear)
            if idx_minrange >= 0:
                multirange_detection_rate.Heading[count] = "Front"
            else:
                multirange_detection_rate.Heading[count] = "Rear"

            count += 1

        # Prepare the output for CSV
        front_ranges = multirange_detection_rate[multirange_detection_rate['Heading'] == 'Front']
        rear_ranges = multirange_detection_rate[multirange_detection_rate['Heading'] == 'Rear']

        print("Exiting from ObjectDetection_Rate_MultiRange function")
        return multirange_detection_rate






    