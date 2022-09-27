#!/bin/bash

echo "Start Localization Validation "
gnome-terminal --tab --title="Localization Validation" --command="bash -c 'cd ../AutowareAuto; ade enter ./PolyVerif_Shell/support_files/validate_local.sh; exit; $SHELL '"



echo $$>>pidFile.txt