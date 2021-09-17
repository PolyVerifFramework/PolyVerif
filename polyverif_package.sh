#!/bin/bash
echo "Building and installing the require components for PolyVerif Framework."
#cd adehome
#cd AutowareAuto
#ade start
#ade enter

echo "Setting the environment variables.."
source /opt/AutowareAuto/setup.bash

echo "Start Installing PythonAPI.."
cd PythonAPI/
pip3 install --user -e .
echo -e "PythonAPI Installed.\n\n"
sleep 2
cd ..

echo "Start Installing Scenic (SDL) .."
cd Scenic/
pip3 install --user -e .
echo -e "Scenic Installed.\n\n"
sleep 2
cd ..

echo "Start Building Perception/Detection Validation Node.."
cd Node/Node_perception_validation_ws
colcon build
source install/setup.bash
echo -e "Detection Validation Node Build.\n\n"
sleep 2
cd ../..

echo "Start Building Control Validation Node.."
cd Node/Node_control_validation_ws
colcon build
source install/setup.bash
echo -e "Control Validation Node Build.\n\n"
sleep 2
cd ../..

echo "Start Building Localization Validation Node.."
cd Node/Node_localization_validation_ws
colcon build
source install/setup.bash
echo -e "Localization Validation Node Build.\n\n"
sleep 2
cd ../..

echo "Start Building Mission/Path Planning Validation Node.."
cd Node/Node_path_planner_validation_ws
colcon build
source install/setup.bash
echo -e "Path Planning Validation Node Build.\n\n"
sleep 2
cd ../..

echo "Start Building Avp_Demo"
cd avp_demo/
colcon build
echo -e "Avp Demo Package Build.\n\n"
sleep 2
cd ..

echo "All the package build Successfully"

