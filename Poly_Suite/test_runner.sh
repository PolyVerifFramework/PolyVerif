#!/bin/sh 
set -eu
mkdir -p PolyReports/Validation_report/17_03_2021__20_54_32/WithPedNPC && touch PolyReports/Validation_report/17_03_2021__20_54_32/WithPedNPC/
echo "PolyReports/Validation_report/17_03_2021__20_54_32/WithPedNPC " > PolyReports/Validation_report/config.txt; 
sleep 1 
echo "Running Scenario :/Test_Cases/Weather_Control/WithPedNPC.py 0.9 0.9 0.9 0.9 0.9 BorregasAve " > ./Poly_Suite/logfiles/logInfo.txt; 
python3 ./Test_Cases/Weather_Control/WithPedNPC.py 0.9 0.9 0.9 0.9 0.9 BorregasAve
