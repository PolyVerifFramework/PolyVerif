#!/bin/bash

echo "Python API Simulation Running"
#gnome-terminal --tab --title="Scenario Run" --command="bash -c ' cd ..; echo Trying to setup the Simulation.. > Poly_Suite/logfiles/logInfo.txt; ./Poly_Suite/test_runner.sh; echo Simulation of selected Test case completed, Click on Stop Scenario to Generate Report.. > Poly_Suite/logfiles/logInfo.txt;  $SHELL '"
gnome-terminal --tab --title="Scenario Run" --command="bash -c ' cd ..; echo Trying to setup the Simulation.. > Poly_Suite/logfiles/logInfo.txt; ./Poly_Suite/test_runner.sh; echo Simulation of selected Test case completed, Click on Stop Scenario to Generate Report.. > Poly_Suite/logfiles/logInfo.txt;$SHELL '"