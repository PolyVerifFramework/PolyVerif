#!/bin/bash

echo "Control node Started..."
./support_files/filepath.sh
echo $$ > pid
source ~/autoware/install/setup.bash
source ~/PolyVerif/Node/Node_control_validation_ws/control_validation_ws/install/setup.bash
ros2 run node_control_validation control_subscriber 


