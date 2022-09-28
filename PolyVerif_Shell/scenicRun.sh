#!/bin/bash

# read -r "PolyVerif_Shell/path1.txt" s
# echo $s
#pwd
#var=`cat path1.txt`
var=`cat PolyVerif_Shell/path1.txt`
#echo ":::$var"
v1=${var%/*}
v2=${var#*/}

echo "$v1 $v2"
scenic TCases/$v1/$v2    --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count 1  --param map TCases/$v1/maps/$v1.xodr   --param lgsvl_map $v1
