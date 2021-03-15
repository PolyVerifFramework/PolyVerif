#!/bin/bash

echo "Setting the Environment variables..." > Poly_Suite/logfiles/logInfo.txt

source /opt/AutowareAuto/setup.bash
source ros2-lgsvl-bridge/install/setup.bash
source script/Node_lg_groundtruth_data_ws/lg_groundtruth_data_ws/install/setup.bash 

echo "Start running LGSVL Bridge" > Poly_Suite/logfiles/logInfo.txt
sleep 1
sh ./Poly_Suite/support_files/lgsvl_bridge.sh &
echo "LGSVL Bridge Started.." > Poly_Suite/logfiles/logInfo.txt
sleep 5

echo "Start running LG Simulator" > Poly_Suite/logfiles/logInfo.txt
sleep 1
sh ./Poly_Suite/support_files/lgsvl.sh &
echo "LG Simulator Started.." > Poly_Suite/logfiles/logInfo.txt
sleep 5

echo "Start Perception Validation Stack.." > Poly_Suite/logfiles/logInfo.txt
sh ./Poly_Suite/support_files/validate_p.sh &
#ros2 run lg_sub_groundtruth lg_gt3d_subscriber &
echo "Perception Validation Stack Started.." > Poly_Suite/logfiles/logInfo.txt

sleep 3
echo "Start running Rviz2" > Poly_Suite/logfiles/logInfo.txt
sh ./Poly_Suite/support_files/perception.sh 
sleep 5
echo "RViz Started.." > Poly_Suite/logfiles/logInfo.txt


