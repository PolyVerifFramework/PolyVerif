#!/bin/bash
echo "Setting the Environment variables..."
echo "Setting the Environment variables..." > Poly_Suite/logfiles/logInfo.txt
#echo $$ > ../Poly_Suite/adePID

#sh ./Poly_Suite/support_files/lgsvl.sh &
#echo " Simulator Started.." > Poly_Suite/logfiles/logInfo.txt

#source ~/autoware/install/setup.bash
echo "Start running Rviz2" > Poly_Suite/logfiles/logInfo.txt
sh ./Poly_Suite/support_files/perception.sh
echo "RViz2 Started.." > Poly_Suite/logfiles/logInfo.txt
