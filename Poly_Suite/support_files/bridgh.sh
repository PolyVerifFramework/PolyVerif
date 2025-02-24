#!/bin/bash
source /opt/AutowareAuto/setup.bash
source ros2-lgsvl-bridge/install/setup.bash 
node ./ros2-web-bridge/bin/rosbridge.js 
