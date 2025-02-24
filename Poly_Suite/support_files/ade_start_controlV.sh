#!/bin/bash

gnome-terminal --tab --title="ADE Start" --command="bash -c 'cd ../AutowareAuto; ade start -- --net=host --privileged; echo ADE Started, Now Entering into Docker.. > ../Poly_Suite/logfiles/logInfo.txt; sleep 1; ade enter ./Poly_Suite/support_files/launchC.sh; exit; $SHELL'"

#sleep 1

#gnome-terminal --tab --title="Browser " --command="bash -c 'cd support_files;  python3 ./apimode.py; $SHELL'"



