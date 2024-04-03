#!/bin/bash

echo "Starting Autoware.."

ros2 launch autoware_launch e2e_simulator.launch.xml vehicle_model:=sample_vehicle sensor_model:=awsim_sensor_kit map_path:=$HOME/autoware_map/nishishinjuku_autoware_map/

#ros2 launch autoware_launch planning_simulator.launch.xml map_path:=$HOME/autoware_map/sample-map-planning vehicle_model:=sample_vehicle sensor_model:=awsim_sensor_kit 
