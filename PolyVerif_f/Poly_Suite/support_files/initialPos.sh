#!/bin/bash

echo "Setting Initial Position of the vehicle"
source /opt/AutowareAuto/setup.bash

AvpDemoTaltech=$(awk -F "=" '/taltech/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoJTA=$(awk -F "=" '/JTA_R1/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoAutonomusstuff=$(awk -F "=" '/autonomoustuff/ {print $2}' ./Poly_Suite/config.ini)

# autonomous stuff
AutonomusStuffInitialPose(){
	# use autonomous stuff old ###### initial pose from 1st end #### localize
	ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -100.6637191772461, y: 48.752685546875, z: 0}, orientation:{x: 0, y: 0, z: 0.34801759365444823, w: 0.9374880023269457}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once


	#ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -24.6692, y:  -402.736, z: 0}, orientation:{x: 0, y: 0, z: 0.772252, w: 0.635316}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

	#Autonomous new planner #### initial pose from 1st end # planner
	#ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -25.087032318115234, y: 110.34013366699219, z: 0}, orientation:{x: 0, y: 0, z:  -0.9388700091252679, w: 0.3442718489291847}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

}

# Taltech map
TaltechInitialPose(){
	ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -22.482, y: -107.022, z: 0}, orientation:{x: 0, y: 0, z: 0.8061, w: 0.591779}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

#kunal_JTA_R1
#ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: 102, y: -14.3, z: 1.29}, orientation:{x: 0, y: 0, z: -1, w: 0}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

}

# JTA map
JTAInitialPose(){

#JTA_R1
ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: 102, y: -14.3, z: 1.29}, orientation:{x: 0, y: 0, z: -1, w: 0}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

}


if [ $AvpDemoTaltech == true ]
then
   TaltechInitialPose			# For Taltech Map

elif [ $AvpDemoJTA == true ]
then
    JTAInitialPose           #for JTA Map
else
   AutonomusStuffInitialPose		# For Autonomus Stuff
fi



