#!/bin/sh 
set -eu
echo $PPID > Poly_Suite/node_pid
./Poly_Suite/support_files/validate_p.sh &
ls 
mkdir -p PolyReports/Validation_report/24_04_2024_13_16_47/Detection/ && touch PolyReports/Validation_report/24_04_2024_13_16_47/Detection/
echo "PolyReports/Validation_report/24_04_2024_13_16_47/Detection/ " > PolyReports/Validation_report/config.txt; 
./Poly_Suite/support_files/engage.sh
