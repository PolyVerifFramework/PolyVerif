#!/bin/bash

echo "Planning node Started..."
./support_files/filepath.sh
echo $PPID > pid
source ~/autoware/install/setup.bash
source ~/PolyVerif/Node/Node_path_planner_validation_ws/path_planner_validation_ws/install/setup.bash
ros2 run path_planner_validation path_planner_node

