#!/bin/bash

value=$(<../../pid)

echo "PId from the button event : $value "

gnome-terminal --tab --title="Stop Scenario" --command="bash -c 'cd ../../AutowareAuto; sed -i '3s/.*/pid=${value}/' ../script/stop_scenario.sh; ade enter ./script/stop_scenario.sh; exit $SHELL '"
