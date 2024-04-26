#!/bin/bash

# TODO
source $HOME/autoware/install/setup.bash
source $HOME/adehome/Node/Node_localization_validation_ws/localization_validation_ws/install/setup.bash
ros2 run node_localization_validation localization_node 
