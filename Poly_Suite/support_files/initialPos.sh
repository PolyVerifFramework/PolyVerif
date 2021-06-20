#!/bin/bash

echo "Setting Initial Position of the vehicle"
source /opt/AutowareAuto/setup.bash
#ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -100.6637191772461, y: 48.752685546875, z: 0}, orientation:{x: 0, y: 0, z: 0.34801759365444823, w: 0.9374880023269457}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once



#ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -24.6692, y:  -402.736, z: 0}, orientation:{x: 0, y: 0, z: 0.772252, w: 0.635316}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once



ros2 topic pub /localization/initialpose geometry_msgs/msg/PoseWithCovarianceStamped  '{header:{frame_id: "map"}, pose: { pose: {position: {x: -22.482, y: -107.022, z: 0}, orientation:{x: 0, y: 0, z: 0.8061, w: 0.591779}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}' --once
