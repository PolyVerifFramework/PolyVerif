exit
source /opt/AutowareAuto/setup.bash
source lgsvl_msgs/install/setup.bash
source ros2-lgsvl-bridge/install/setup.bash 
lgsvl_bridge
netstat -tulpn
pkill -9 python3
lgsvl_bridge
killall -9 node
netstat -tlpn
sudo lsof -i tcp:9090
sudo lsof -i tcp:8080
sudo lsof -i tcp:9090
sudo apt-get install lsof
exit
cd ..
ls
cd acclivis/
ls
source /opt/AutowareAuto/setup.bash
source lgsvl_msgs/install/setup.bash
source ros2-lgsvl-bridge/install/setup.bash
ros2 launch autoware_demos lidar_bounding_boxes_lgsvl.launch.py 
exit
source /opt/AutowareAuto/setup.bash
ls
cd Test_Cases/
ls
cd Test/
python3 EgoCrashing.py 
python3 FollowingMultipleVehicle.py 
ls
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/CubeTown.xodr   --param lgsvl_map CubeTown
ls
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/CubeTown.xodr   --param lgsvl_map CubeTown
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/06773677-1ce3-492f-9fe2-b3147e126e27   --param lgsvl_map CubeTown
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/CubeTown.xodr   --param lgsvl_map CubeTown
cd ..
ls
cd CubeTown/
ls
cd Scenic_CollisionAvoidence/
ls
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/06773677-1ce3-492f-9fe2-b3147e126e27   --param lgsvl_map CubeTown
ls
scenic EgoFollowingNPC.scenic
cd ..
ls
cd ../Test/
ls
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/06773677-1ce3-492f-9fe2-b3147e126e27   --param lgsvl_map CubeTown
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/b06773677-1ce3-492f-9fe2-b3147e126e27   --param lgsvl_map CubeTown
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/606ca6e-8fc4-460c-820b-c28ea77ca2d5   --param lgsvl_map 606ca6e-8fc4-460c-820b-c28ea77ca2d5
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map maps/CubeTown.xodr   --param lgsvl_map CubeTown
cd ..
ls
cd ..
ls
cd Scenic/
ls
python -m pip install -e .
python3 -m pip install -e .
source /opt/AutowareAuto/setup.bash
pip3 install --user -e .
ls
scenic carla_challenge_4.scenic    --simulate
cd ..
ls
cd Test_Cases/Test/
ls
scenic carla_challenge_4.scenic    --simulate
python3 EgoCrashing.py 
cd ../..
ls
cd PythonAPI/
ls
pip3 install --user .
cd ../Test_Cases/Test/
ls
python3 EgoCrashing.py 
ros2 topic list
ros2 topic echo /lidars/lidar_bounding_boxes
python3 EgoCrashing.py 
exit
sudo apt-get install lsof
source lgsvl_msgs/install/setup.bash
source ros2-lgsvl-bridge/install/setup.bash 
lgsvl_bridge
exit
source /opt/AutowareAuto/setup.bash && source lgsvl_msgs/install/setup.bash && source ros2-lgsvl-bridge/install/setup.bash 
ros2 topic pub /planning/goal_pose geometry_msgs/msg/PoseStamped  '{header:{frame_id: "map"}, pose: {position: {x: -62.4631, y: 86.5299, z: 0}, orientation:{x: 0, y: 0, z:  0.945008, w: 0.327047}}}' --once
exit
source /opt/AutowareAuto/setup.bash && source lgsvl_msgs/install/setup.bash && source ros2-lgsvl-bridge/install/setup.bash
lgsvl_bridge
ade stop
exit
scenic Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map BorregasAve
scenic Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
scenic EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map BorregasAve
scenic Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map BorregasAve
scenic Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
exit
ls
scenic Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
source /opt/AutowareAuto/setup.bash 
scenic Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
exit
source /opt/AutowareAuto/setup.bash && source lgsvl_msgs/install/setup.bash && source ros2-lgsvl-bridge/install/setup.bash
scenic Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
exit
scenic Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/EgoFollowingNPC.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_LaneFollowingAndManeuver/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
scenic EgoFollowingNPC.scenic --simulate  --model scenic.simulators.lgsvl.model  --time 200 --count 1 --param map maps/CubeTown.xodr --param lgsvl_map CubeTown
cd Test_Cases/
ls
cd CubeTown/
ls
cd Scenic_CollisionAvoidence/
ls
scenic EgoFollowingNPC.scenic --simulate  --model scenic.simulators.lgsvl.model  --time 200 --count 1 --param map maps/CubeTown.xodr --param lgsvl_map CubeTown
scenic EgoFollowingNPC.scenic --simulate  --model scenic.simulators.lgsvl.model  --time 200 --count 1 --param map maps/CubeTown.xodr --param lgsvl_map 06773677-1ce3-492f-9fe2-b3147e126e27
exit
cd OSSDC-SIM-v1_1-Linux && ./run-OSSDC-SIM-v1.sh
exit
source /opt/AutowareAuto/setup.bash 
cd avp_demo/
ls
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
ade enter
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd aav
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
source /opt/AutowareAuto/setup.bash 
cd PythonAPI/
pip3 install --user -e .
python3 -m pip install -r requirements.txt --user .
exit
source /opt/AutowareAuto/setup.bash 
ls
python3 -m pip install -r requirements.txt --user .
cd PythonAPI/
ls
python3 -m pip install -r requirements.txt --user .
exit
scenic Test_Cases/BorregasAve/Scenic_CollisionAvoidence/AvoidingCollision.scenic    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map Test_Cases/BorregasAve/Scenic_CollisionAvoidence/maps/BorregasAve.xodr   --param lgsvl_map aae03d2a-b7ca-4a88-9e41-9035287a12cc
exit
python --version
python3 --version
ade stop
exit
python3 --version
python --version
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build/
colcon build
source install/setup.bash 
ade stop
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colconn build
colcon build
source install/setup.bash 
exit
cd Poly_Suite/
cd support_files/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
cd Poly_Suite/
cd support_files/
colcon build
source install/setup.bash 
exit
cd avp_demo/
colcon build
source install/setup.bash 
exit
