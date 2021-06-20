#!/bin/bash

echo $BASHPID
echo $$ > pidfile 
#sed -i "4i $$" stop_scenario.sh
source /opt/AutowareAuto/setup.bash
source avp_demo/install/setup.bash
ros2 launch avp_demo ms3_sim.launch.py 



