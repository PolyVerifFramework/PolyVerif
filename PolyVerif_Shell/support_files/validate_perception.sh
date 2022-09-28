#!/bin/bash

echo "Start AD Perception Validation "
gnome-terminal --tab --title="AD P_Validation" --command="bash -c 'cd ../AutowareAuto; ade enter ./PolyVerif_Shell/support_files/validate_p.sh; exit; $SHELL '"


echo $$>>pidFile.txt