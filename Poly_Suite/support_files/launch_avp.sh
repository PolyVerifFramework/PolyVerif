#!/bin/bash

echo $BASHPID
echo $$ > pidfile 
#sed -i "4i $$" stop_scenario.sh
source /opt/AutowareAuto/setup.bash

AvpDemoTaltech=$(awk -F "=" '/taltech/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoAutonomusstuff=$(awk -F "=" '/autonomoustuff/ {print $2}' ./Poly_Suite/config.ini)


# Autonomous stuff
Autonomusstuff(){
	ros2 launch autoware_auto_avp_demo ms3_sim.launch.py
}

# Taltech
Taltech(){
	source avp_demo/install/setup.bash
	ros2 launch avp_demo ms3_sim.launch.py 
}


if [ $AvpDemoTaltech == true ]
then
   Taltech			# For Taltech Map
else
   Autonomusstuff		# For Autonomus Stuff
fi




