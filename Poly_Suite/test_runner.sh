#!/bin/sh 
./Poly_Suite/support_files/validate_c.sh &
mkdir -p PolyReports/Validation_report/19_05_2021__04_05_08/AvoidingCollision_iteration_1 && touch PolyReports/Validation_report/19_05_2021__04_05_08/AvoidingCollision_iteration_1/
echo "PolyReports/Validation_report/19_05_2021__04_05_08/AvoidingCollision_iteration_1 " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/Scenic_CollisionAvoidence/AvoidingCollision.scenic " > ./Poly_Suite/logfiles/logInfo.txt; 
echo "Running Scenic" 
scenic Test_Cases/Scenic_CollisionAvoidence/AvoidingCollision.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/Scenic_CollisionAvoidence/maps/TalTech.xodr   --param lgsvl_map TalTech