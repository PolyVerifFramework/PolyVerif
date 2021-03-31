#!/bin/sh 
set -eu
mkdir -p PolyReports/Validation_report/31_03_2021__12_28_34/TC_7 && touch PolyReports/Validation_report/31_03_2021__12_28_34/TC_7/
echo "PolyReports/Validation_report/31_03_2021__12_28_34/TC_7 " > PolyReports/Validation_report/config.txt; 
echo "Running Scenario :/Test_Cases/Weather_Control/TC_7.py 0.9 0.9 0.9 0.9 0.9 BorregasAve " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/Weather_Control/TC_7.py 0.9 0.9 0.9 0.9 0.9 BorregasAve
