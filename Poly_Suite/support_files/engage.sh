#!/bin/bash

source /opt/ros/humble/setup.bash
source /autoware/install/setup.bash
ros2 topic pub /autoware/engage autoware_auto_vehicle_msgs/msg/Engage '{engage: True}' -1