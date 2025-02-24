#!/bin/bash

echo $BASHPID
echo $$ > pidfile 
#sed -i "4i $$" stop_scenario.sh
source /opt/AutowareAuto/setup.bash

AvpDemoTaltech=$(awk -F "=" '/taltech/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoJTA_R1=$(awk -F "=" '/JTA_R1/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoJTA_R2=$(awk -F "=" '/JTA_R2/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoAutonomusstuff=$(awk -F "=" '/autonomoustuff/ {print $2}' ./Poly_Suite/config.ini)


# Autonomous stuff
Autonomusstuff(){

	source avp_demo/install/setup.bash
	ros2 launch autoware_auto_avp_demo ms3_sim.launch.py
        
}

# Taltech
Taltech(){
	source avp_demo/install/setup.bash
	ros2 launch avp_demo ms3_sim.launch.py 
	
}


# JTA_R1
JTA_R1(){
	source avp_demo/install/setup.bash
	ros2 launch avp_demo ms3_sim.launch.py 
	
}

# JTA_R2
JTA_R2(){
	source avp_demo/install/setup.bash
	ros2 launch avp_demo ms3_sim.launch.py 
	
}


if [ $AvpDemoTaltech == true ]
then
   Taltech			# For Taltech Map

elif [ $AvpDemoJTA_R1 == true ]
then
    
    JTA_R1           #for JTA_R1 Map
elif [ $AvpDemoJTA_R2 == true ]
then
    
    JTA_R2           #for JTA_R2 Map
else
   Autonomusstuff		# For Autonomus Stuff
fi




