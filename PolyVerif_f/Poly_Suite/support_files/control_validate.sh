#!/bin/bash

echo "Start AD Control Validation "
gnome-terminal --tab --title="Control Validate" --command="bash -c 'cd ../../AutowareAuto; ade enter ./Poly_Suite/support_files/control_validate_p.sh; exit; $SHELL '"


