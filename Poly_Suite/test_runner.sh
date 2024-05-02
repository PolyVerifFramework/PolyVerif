#!/bin/sh 
set -eu
echo $PPID > Poly_Suite/node_pid
./Poly_Suite/support_files/validate_c.sh & 
mkdir -p PolyReports/Validation_report/02_05_2024__11_03_38/Control/ && touch PolyReports/Validation_report/02_05_2024__11_03_38/Control/
echo "PolyReports/Validation_report/02_05_2024__11_03_38/Control/ " > PolyReports/Validation_report/config.txt; 
