#!/bin/bash

echo "Starting Autoware_Perception"

ros2 launch autoware_launch e2e_simulator.launch.xml vehicle_model:=sample_vehicle sensor_model:=awsim_sensor_kit map_path:=autoware_map/nishishinjuku_autoware_map/

echo "Autoware Perception Stack Started"
