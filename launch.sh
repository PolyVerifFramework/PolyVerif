#!/bin/bash

echo $PPID > ppid
echo "launch AWSIM Simulator.." 
sh ./support_files/Awsim.sh &
echo "launch Autoware.."  
source ~/autoware/install/setup.bash
sh ./support_files/Autoware.sh
