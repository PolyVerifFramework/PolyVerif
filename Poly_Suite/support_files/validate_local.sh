#!/bin/bash

# TODO need to change the path

source /opt/ros/humble/setup.bash
source /autoware/install/setup.bash
source Node/Node_localization_validation_ws/localization_validation_ws/install/setup.bash
ros2 run node_localization_validation localization_node 
