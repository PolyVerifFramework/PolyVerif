#!/bin/bash

echo "Scenic Simulation"

gnome-terminal --tab --title="Scenic" --command="bash -c 'echo Trying to setup the Simulation for running.. > ../Poly_Suite/logfiles/logInfo.txt;cd ../AutowareAuto; ade enter ./Poly_Suite/test_runner.sh; echo Simulation of selected Test cases completed, Click on Stop Scenario to check Report.. > ../Poly_Suite/logfiles/logInfo.txt; $SHELL'"



#gnome-terminal --tab --title="Scenario Run" --command="bash -c 'cd ../AutowareAuto; echo Trying to setup the Simulation for running.. > ../Poly_Suite/logfiles/logInfo.txt; ade enter ./Poly_Suite/test_runner.sh; echo Simulation of selected Test cases completed, Click on Stop Scenario to check Report.. > ../Poly_Suite/logfiles/logInfo.txt; exit; $SHELL '"


