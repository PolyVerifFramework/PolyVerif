#!/bin/bash

echo "Setting Initial Position of the vehicle"
source /opt/AutowareAuto/setup.bash

AvpDemoTaltech=$(awk -F "=" '/taltech/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoJTA_R1=$(awk -F "=" '/JTA_R1/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoJTA_R2=$(awk -F "=" '/JTA_R2/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoAutonomusstuff=$(awk -F "=" '/autonomoustuff/ {print $2}' ./Poly_Suite/config.ini)

# autonomous stuff
AutonomusStuffInitialPose(){
	# use autonomous stuff old ###### initial pose from 1st end #### localize
	ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -58.06, y: -41.7314, z: -6.8757}, orientation:{x: 0, y: 0, z: 180, w: 0.9374880023269457}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once


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
JTA_R1_InitialPose(){

#JTA_R1
ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: 102, y: -14.3, z: 1.29}, orientation:{x: 0, y: 0, z: -1, w: 0}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

}


# JTA_R2
JTA_R2_InitialPose(){
ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -242, y: -1.09, z: 9.9}, orientation:{x: 0, y: 0, z: 0, w: 0}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once

}


if [ $AvpDemoTaltech == true ]
then
   TaltechInitialPose			# For Taltech Map

elif [ $AvpDemoJTA_R1 == true ]
then
    JTA_R1_InitialPose           #for JTA_R1 Map
elif [ $AvpDemoJTA_R2 == true ]
then
    JTA_R2_InitialPose           #for JTA_R2 Map
else
   AutonomusStuffInitialPose		# For Autonomus Stuff
fi



