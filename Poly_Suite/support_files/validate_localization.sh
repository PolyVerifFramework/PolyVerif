#!/bin/bash

echo "Start Localization Validation "
gnome-terminal --tab --title="Localization Validation" --command="bash -c 'cd ../AutowareAuto; ade enter ./Poly_Suite/support_files/validate_local.sh; exit; $SHELL '"


