#!/bin/bash

# TODO need to change the path

source $HOME/autoware/install/setup.bash
source $HOME/adehome/Node/Node_control_validation_ws/control_validation_ws/install/setup.bash
ros2 run node_control_validation control_subscriber 


