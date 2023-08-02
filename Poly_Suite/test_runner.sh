#!/bin/sh 
set -eu
./Poly_Suite/support_files/validate_pathplannerNode.sh & 
mkdir -p PolyReports/Validation_report/02_08_2023__10_42_20/PlannerJTA && touch PolyReports/Validation_report/02_08_2023__10_42_20/PlannerJTA/
echo "PolyReports/Validation_report/02_08_2023__10_42_20/PlannerJTA " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/JTA_R2/PythonScript/PlannerJTA.py 0.0 0.0 0.0 0.0 0.0 JTA_R2 " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/JTA_R2/PythonScript/PlannerJTA.py 0.0 0.0 0.0 0.0 0.0 JTA_R2
