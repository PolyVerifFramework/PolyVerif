#!/bin/bash

echo "Starting Autoware_Perception"
#source /opt/AutowareAuto/setup.bash
#source ros2-lgsvl-bridge/install/setup.bash 
#ros2 launch autoware_demos lidar_bounding_boxes_lgsvl.launch.py 

ros2 launch autoware_launch e2e_simulator.launch.xml vehicle_model:=sample_vehicle sensor_model:=awsim_sensor_kit map_path:=$HOME/autoware_map/nishishinjuku_autoware_map/