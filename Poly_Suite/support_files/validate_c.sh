#!/bin/bash

# TODO need to change the path

#source Node/Node_perception_validation_ws/install/setup.bash 
source Node/Node_control_validation_ws/install/setup.bash
source lgsvl_msgs/install/setup.bash
ros2 run control_validation control_subscriber


