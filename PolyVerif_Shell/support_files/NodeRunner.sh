#!/bin/bash
 echo "In NR:$1"

gnome-terminal --tab --title="ADE Start" --command="bash -c 'cd ../AutowareAuto; ade enter ./PolyVerif_Shell/support_files/$1;  $SHELL'"
