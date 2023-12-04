#!/bin/bash

echo "Setting the Environment variables..." > Poly_Suite/logfiles/logInfo.txt

source /opt/AutowareAuto/setup.bash
source lgsvl_msgs/install/setup.bash
source ros2-lgsvl-bridge/install/setup.bash

echo "Start running LGSVL Bridge" > Poly_Suite/logfiles/logInfo.txt

sh ./Poly_Suite/support_files/lgsvl_bridge.sh &
echo "LGSVL Bridge Started.." > Poly_Suite/logfiles/logInfo.txt


echo "Start running LG Simulator" > Poly_Suite/logfiles/logInfo.txt

sh ./Poly_Suite/support_files/lgsvl.sh &
echo "LG Simulator Started.." > Poly_Suite/logfiles/logInfo.txt

echo "Start running Rviz2" > Poly_Suite/logfiles/logInfo.txt
sh ./Poly_Suite/support_files/perception.sh
echo "RViz2 Started.." > Poly_Suite/logfiles/logInfo.txt


