#!/bin/sh 
set -eu
./Poly_Suite/support_files/validate_p.sh &
ls 
mkdir -p PolyReports/Validation_report/17_07_2021__00_35_56/Taltech && touch PolyReports/Validation_report/17_07_2021__00_35_56/Taltech/
echo "PolyReports/Validation_report/17_07_2021__00_35_56/Taltech " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/TalTech/Taltech/Taltech.py 0.0 0.0 0.0 0.0 0.0 TalTech " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/TalTech/Taltech/Taltech.py 0.0 0.0 0.0 0.0 0.0 TalTech
