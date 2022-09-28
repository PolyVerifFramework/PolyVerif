#!/bin/sh 
set -eu
./Poly_Suite/support_files/validate_pathplannerNode.sh & 
mkdir -p PolyReports/Validation_report/22_09_2022__15_10_58/LocalJTA && touch PolyReports/Validation_report/22_09_2022__15_10_58/LocalJTA/
echo "PolyReports/Validation_report/22_09_2022__15_10_58/LocalJTA " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/JTA_R1/JTA_R1_TESTS/LocalJTA.py 0.0 0.0 0.0 0.0 0.0 JTA_R1 " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/JTA_R1/JTA_R1_TESTS/LocalJTA.py 0.0 0.0 0.0 0.0 0.0 JTA_R1
