#!/bin/bash

echo "Starting Autoware_Perception"
#source /opt/AutowareAuto/setup.bash
#source ros2-lgsvl-bridge/install/setup.bash 
ros2 launch autoware_demos lidar_bounding_boxes_lgsvl.launch.py 
echo "Autoware Perception Stack Started"
