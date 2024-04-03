#!/bin/bash

echo "Detection node Started..."
./support_files/filepath.sh
echo $PPID > pid
source ~/autoware/install/setup.bash
source ~/PolyVerif/Node/Node_perception_validation_ws/node_perception_validation_ws/install/setup.bash
ros2 run node_perception_validation detection_node

