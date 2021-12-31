#!/bin/bash

echo $BASHPID
echo $$ > pidfile 
#sed -i "4i $$" stop_scenario.sh
source /opt/AutowareAuto/setup.bash

# Autonomous stuff
Autonomusstuff(){
ros2 launch autoware_auto_avp_demo ms3_sim.launch.py
}

# Taltech
Taltech(){
source avp_demo/install/setup.bash
ros2 launch avp_demo ms3_sim.launch.py 
}


#Autonomusstuff			# For Autonomus Stuff
Taltech				# For Taltech Map



