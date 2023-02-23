#!/bin/bash
echo "Building and installing the require components for PolyVerif Suite."

echo "Setting the environment variables.."
source /opt/AutowareAuto/setup.bash

sudo apt update
sudo apt-get install python3-gi
pip install watchdog
pip install pandas



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
echo "Start Installing PythonAPI.."
cd PythonAPI/
python3 -m pip install -r requirements.txt --user -e .
echo -e "PythonAPI Installed.\n\n"
sleep 2
cd ..

echo "Start Installing Scenic (SDL) .."
cd Scenic/
sudo pip3 install --upgrade pip
pip3 install scenic
export PATH=$PATH:${home}/.local/bin

curl -sSL https://install.python-poetry.org | python3 -
source $HOME/.poetry/env
poetry env list
poetry install
poetry self update 1.0.0
pip3 install --user -e .
echo -e "Scenic Installed.\n\n"
sleep 2
cd ..

git clone https://github.com/lgsvl/lgsvl_msgs.git
cd lgsvl_msgs
source /opt/AutowareAuto/setup.bash
colcon build
cd ..

sudo apt update
sudo apt install python3-colcon-common-extensions
sudo apt install libboost-all-dev

git clone https://github.com/lgsvl/ros2-lgsvl-bridge.git
cd ros2-lgsvl-bridge
source /opt/AutowareAuto/setup.bash
git checkout ${ROS_DISTRO}-devel
colcon build --cmake-args '-DCMAKE_BUILD_TYPE=Release'
source install/setup.bash
cd ..



echo "All the packages build Successfully."

