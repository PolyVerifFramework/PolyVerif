#!/bin/bash

# open scenario .sh in sec line add the string parame close

#gnome-terminal --tab --title="Scenario Run" --command="bash -c 'cd ../../AutowareAuto; sed -i '3s/.*/Scenario=${Scenario}/' ../script/scenario.sh; sed -i '4s/.*/rain=${rain}/' ../script/scenario.sh; sed -i '5s/.*/fog=${fog}/' ../script/scenario.sh; sed -i '6s/.*/wetness=${wetness}/' ../script/scenario.sh; sed -i '7s/.*/cloudiness=${cloudiness}/' ../script/scenario.sh; sed -i '8s/.*/damage=${damage}/' ../script/scenario.sh; sed -i '9s/.*/scene=${scene}/' ../script/scenario.sh; ade enter ./script/scenario.sh; exit; $SHELL '"
echo "scenario_setup Running"

#path = $1
#echo $path

gnome-terminal --tab --title="Scenario Run" --command="bash -c 'cd ../AutowareAuto; echo Trying to setup the Simulation for running.. > ../Poly_Suite/logfiles/logInfo.txt; ade enter ./Poly_Suite/test_runner.sh; echo Simulation of selected Test cases completed, Click on Stop Scenario to check Report.. > ../Poly_Suite/logfiles/logInfo.txt; exit; $SHELL '"


