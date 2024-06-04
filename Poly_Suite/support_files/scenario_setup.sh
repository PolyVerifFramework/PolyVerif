#!/bin/bash

echo "Python API Simulation Running"

#gnome-terminal --tab --title="Scenario Run" --command="bash -c 'cd ../AutowareAuto; echo Trying to setup the Simulation.. > ../Poly_Suite/logfiles/logInfo.txt; ade enter ./Poly_Suite/test_runner.sh; echo Simulation of selected Test case completed, Click on Stop Scenario to Generate Report.. > ../Poly_Suite/logfiles/logInfo.txt; exit; $SHELL '"

#cmd="cd adehome &&  ./Poly_Suite/support_files/launch.sh && exec /bin/bash"

cmd="cd adehome && ./Poly_Suite/test_runner.sh && exec /bin/bash"

# Open a new terminal tab to enter the ADE container and run the command
#gnome-terminal --tab --title="Scenario Run" -- bash -c "pwd; ade enter \"${cmd}\"; exec $SHELL"

gnome-terminal --tab --title="Scenario Run" -- bash -c "pwd; ade enter \"${cmd}\"; exec $SHELL"




