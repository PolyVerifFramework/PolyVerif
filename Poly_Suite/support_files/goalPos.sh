#!/bin/bash

echo "Setting Goal Position of the vehicle"
source /opt/AutowareAuto/setup.bash

AvpDemoTaltech=$(awk -F "=" '/taltech/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoJTA=$(awk -F "=" '/JTA_R1/ {print $2}' ./Poly_Suite/config.ini)
AvpDemoAutonomusstuff=$(awk -F "=" '/autonomoustuff/ {print $2}' ./Poly_Suite/config.ini)


AutonomousStuffGoalPose(){
	#ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: 7.88494873046875, y: 86.73922729492188, z: 0}, orientation:{x: 0, y: 0, z: 0.40195123046527176, w: 0.9156610772155023}}}' --once

	# Use this autonomous stuff old # goal pose from 1st end localize
	ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -62.4631, y: 86.5299, z: 0}, orientation:{x: 0, y: 0, z:  0.945008, w: 0.327047}}}' --once

	#Autonomous new planner	
	#ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -81.38352966308594, y: 58.45685958862305, z: 0}, orientation:{x: 0, y: 0, z:  -0.35609762884684376, w: 0.9344487566098291}}}' --once

	# goal pos from 2nd end
	#ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -93.00395965576172, y: 56.78691101074219, z: 0}, orientation:{x: 0, y: 0, z:  0.0, w: 1.0}}}' --once
}

# Taltech goal pose
TaltechGoalPose(){
	#ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -64.622, y: -249.307, z: 0}, orientation:{x: 0, y: 0, z: -0.999773, w: 0.0213196}}}' --once

	# Taltech goal pose   --original map goal pos
	
    ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -67.4535, y: 55.3939, z: 0}, orientation:{x: 0, y: 0, z: -0.99766, w: 0.0683663}}}' --once

}

JTAGoalPose (){
	
# jta_r1
ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: 22.5, y: 1.03, z: 1.09}, orientation:{x: 0, y: 0, z: -1, w: 0}}}' --once
}

if [ $AvpDemoTaltech == true ]
then
   TaltechGoalPose			# For Taltech Map

elif [ $AvpDemoJTA == true ]
then
    JTAGoalPose            #for JTA Map
else
   AutonomousStuffGoalPose		# For Autonomus Stuff
fi

