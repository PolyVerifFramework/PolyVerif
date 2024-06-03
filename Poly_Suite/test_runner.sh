#!/bin/sh 
set -eu
echo $PPID > Poly_Suite/node_pid
./Poly_Suite/support_files/validate_p.sh &
ls 
mkdir -p PolyReports/Validation_report/03_06_2024_16_54_14/Detection/ && touch PolyReports/Validation_report/03_06_2024_16_54_14/Detection/
echo "PolyReports/Validation_report/03_06_2024_16_54_14/Detection/ " > PolyReports/Validation_report/config.txt; 
./Poly_Suite/support_files/engage.sh
