#!/bin/bash

echo "Setting Goal Position of the vehicle"
source /opt/AutowareAuto/setup.bash
#ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: 7.88494873046875, y: 86.73922729492188, z: 0}, orientation:{x: 0, y: 0, z: 0.40195123046527176, w: 0.9156610772155023}}}' --once


ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -64.622, y: -249.307, z: 0}, orientation:{x: 0, y: 0, z: -0.999773, w: 0.0213196}}}' --once


