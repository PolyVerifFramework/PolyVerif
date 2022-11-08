#!/bin/sh 
set -eu
./Poly_Suite/support_files/validate_pathplannerNode.sh & 
mkdir -p PolyReports/Validation_report/08_11_2022__14_47_47/Blind_Spot6 && touch PolyReports/Validation_report/08_11_2022__14_47_47/Blind_Spot6/
echo "PolyReports/Validation_report/08_11_2022__14_47_47/Blind_Spot6 " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/JTA_R1/JTA_R1_TESTS/Blind_Spot6.py 0.0 0.0 0.0 0.0 0.0 JTA_R1 " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/JTA_R1/JTA_R1_TESTS/Blind_Spot6.py 0.0 0.0 0.0 0.0 0.0 JTA_R1
