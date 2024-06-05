#!/bin/bash

value=$(<pid)

echo "PId from the button event : $value "
echo "Simulation Stopped!!" > logfiles/logInfo.txt

#gnome-terminal --tab --title="Stop Scenario" --command="bash -c 'cd ../Poly_Suite;ls; sed -i '3s/.*/pid=${value}/' support_files/stop_scenario.sh;./support_files/stop_scenario.sh;$SHELL '"

#gnome-terminal --tab --title="Stop Scenario" --command="bash -c 'cd ../AutowareAuto;ls; sed -i '3s/.*/pid=${value}/' ../Poly_Suite/support_files/stop_scenario.sh; ade enter ./Poly_Suite/support_files/stop_scenario.sh;  exit; $SHELL '"


#gnome-terminal --tab --title="Stop Scenario" --command="bash -c 'ls; sed -i \"3s/.*/pid=\${value}/\" support_files/stop_scenario.sh; ./support_files/stop_scenario.sh;$SHELL '"
gnome-terminal --tab --title="Stop Scenario" --command="bash -c 'ls; sed -i '3s/.*/pid=${value}/' ./support_files/stop_scenario.sh;exit;$SHELL '"

