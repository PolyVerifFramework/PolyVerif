#!/bin/bash

STR=$2

SUB='.scenic'
if [[ "$STR" == *"$SUB"* ]]
then
  echo ".."
  echo "$1/$2" > path1.txt
  gnome-terminal --tab --title="ADE Enter" --command="bash -c 'cd ../AutowareAuto; ade enter ./PolyVerif_Shell/scenicRun.sh ;$SHELL'"

# gnome-terminal --tab --title="ADE Enter" --command="bash -c 'cd ../AutowareAuto;ade enter -- --net=host --privileged; cd ../PolyVerif_Shell/scenicRun.sh ;$SHELL'"
# gnome-terminal --tab --title="ADE Enter" --command="bash -c 'cd ../AutowareAuto; ade enter; scenic TCases/$1/$2;$SHELL'"
  
else
  echo "."
  #pwd
  #gnome-terminal --tab --title=" Validation" --command="bash -c './TCases/$1/$2; $SHELL'" 
  gnome-terminal --tab --title=" Validation" --command="bash -c 'cd ..;./TCases/$1/$2; $SHELL'" 
fi

echo $$>>pidFile.txt
