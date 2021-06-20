#!/bin/sh 
./Poly_Suite/support_files/validate_pathplanning.sh &
mkdir -p PolyReports/Validation_report/20_06_2021__05_21_46/LaneFollowing_iteration_1 && touch PolyReports/Validation_report/20_06_2021__05_21_46/LaneFollowing_iteration_1/
echo "PolyReports/Validation_report/20_06_2021__05_21_46/LaneFollowing_iteration_1 " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/Scenic_LaneFollowingAndManeuver/LaneFollowing.scenic " > ./Poly_Suite/logfiles/logInfo.txt; 
echo "Running Scenic" 
scenic Test_Cases/Scenic_LaneFollowingAndManeuver/LaneFollowing.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/Scenic_LaneFollowingAndManeuver/maps/TalTech.xodr   --param lgsvl_map TalTech