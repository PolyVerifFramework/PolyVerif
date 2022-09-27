#!/bin/sh 
set -eu
./Poly_Suite/support_files/validate_pathplannerNode.sh & 
mkdir -p PolyReports/Validation_report/16_12_2021__20_25_03/PlannerTaltech && touch PolyReports/Validation_report/16_12_2021__20_25_03/PlannerTaltech/
echo "PolyReports/Validation_report/16_12_2021__20_25_03/PlannerTaltech " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/TalTech/NPC_Actions/PlannerTaltech.py 0.0 0.0 0.0 0.0 0.0 TalTech " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/TalTech/NPC_Actions/PlannerTaltech.py 0.0 0.0 0.0 0.0 0.0 TalTech
