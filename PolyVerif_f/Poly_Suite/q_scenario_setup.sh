#!/bin/bash
echo $0
echo "File"
echo $(dirname $(realpath $0)) >> val
echo "Running Scenario with parameter $val"
read path < "val"
echo $path
rm val


data=${path/$(dirname $(realpath $0))/}
echo $path

sh  ./support_files/scenario_setup.sh $path
