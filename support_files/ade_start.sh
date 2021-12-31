#!/bin/bash

gnome-terminal --tab --title="ADE Start" --command="bash -c 'cd ../AutowareAuto; ade start -- --net=host --privileged; echo ADE Started, Now Entering into Docker.. > ../PolyVerif_Shell/logfiles/logInfo.txt; sleep 1; ade enter ./PolyVerif_Shell/support_files/launch.sh;  $SHELL'"


echo $$>>pidFile.txt