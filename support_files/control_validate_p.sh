#!/bin/bash

# TODO need to chnage path
#source script/control_validation_ws/install/setup.bash 
source Node/Node_control_validation_ws/install/setup.bash 
source lgsvl_msgs/install/setup.bash
sleep 1
ros2 run control_validation control_subscriber

