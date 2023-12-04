#!/bin/sh 
set -eu
./Poly_Suite/support_files/validate_local.sh & 
mkdir -p PolyReports/Validation_report/04_12_2023__12_09_06/AutonomousStuff_EP_local && touch PolyReports/Validation_report/04_12_2023__12_09_06/AutonomousStuff_EP_local/
echo "PolyReports/Validation_report/04_12_2023__12_09_06/AutonomousStuff_EP_local " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/AutonomouStuff/Localization_Validation/AutonomousStuff_EP_local.py 0.0 0.0 0.0 0.0 0.0 AutonomouStuff " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/AutonomouStuff/Localization_Validation/AutonomousStuff_EP_local.py 0.0 0.0 0.0 0.0 0.0 AutonomouStuff
