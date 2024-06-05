#!/bin/sh 
set -eu
echo $PPID > Poly_Suite/node_pid
./Poly_Suite/support_files/validate_local.sh & 
mkdir -p PolyReports/Validation_report/05_06_2024__17_07_56/Local/ && touch PolyReports/Validation_report/05_06_2024__17_07_56/Local/
echo "PolyReports/Validation_report/05_06_2024__17_07_56/Local/ " > PolyReports/Validation_report/config.txt; 
./Poly_Suite/support_files/engage.sh
