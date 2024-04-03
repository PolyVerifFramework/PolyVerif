#!/bin/bash

echo "Localization node Started..."
./support_files/filepath.sh
echo $$ > pid
source ~/autoware/install/setup.bash
source ~/PolyVerif/Node/Node_localization_validation_ws/localization_validation_ws/install/setup.bash
ros2 run node_localization_validation localization_node 
