#!/bin/bash

echo "Start AD Perception Validation "
gnome-terminal --tab --title="AD P_Validation" --command="bash -c 'cd ../AutowareAuto; ade enter ./Poly_Suite/support_files/validate_p.sh; exit; $SHELL '"


