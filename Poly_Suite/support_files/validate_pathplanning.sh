#!/bin/bash

echo "Start Path Planning Validation "
#gnome-terminal --tab --title="Path Planning Validation" --command="bash -c 'cd ../AutowareAuto; ade enter ./Poly_Suite/support_files/validate_pathplannerNode.sh;  $SHELL '"

# called inside the ade and not gnome not worked so need to called directly

./Poly_Suite/support_files/validate_pathplannerNode.sh


