#!/bin/sh 
set -eu
echo $PPID > Poly_Suite/node_pid
./Poly_Suite/support_files/validate_c.sh & 
mkdir -p PolyReports/Validation_report/06_06_2024__14_58_15/Control/ && touch PolyReports/Validation_report/06_06_2024__14_58_15/Control/
echo "PolyReports/Validation_report/06_06_2024__14_58_15/Control/ " > PolyReports/Validation_report/config.txt; 
