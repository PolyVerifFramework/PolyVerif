#!/bin/sh 
set -eu
echo $PPID > Poly_Suite/node_pid
./Poly_Suite/support_files/validate_pathplannerNode.sh & 
mkdir -p PolyReports/Validation_report/06_06_2024__11_28_34/Planner/ && touch PolyReports/Validation_report/06_06_2024__11_28_34/Planner/
echo "PolyReports/Validation_report/06_06_2024__11_28_34/Planner/ " > PolyReports/Validation_report/config.txt; 
mkdir -p PolyReports/Validation_report/06_06_2024__11_28_34/Planner/ && touch PolyReports/Validation_report/06_06_2024__11_28_34/Planner/
echo "PolyReports/Validation_report/06_06_2024__11_28_34/Planner/ " > PolyReports/Validation_report/config.txt; 
