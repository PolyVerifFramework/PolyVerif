#!/bin/bash

#set -eu

date=$(date +"%d-%m-%Y")
time=$(date +"%T")
date=${date//-/_}
time=${time//:/_}
date_time=$date"_"$time

#curr_dir=${PWD}

path=$HOME"/PolyVerif/PolyReports/"$date_time
echo $path
mkdir $path
echo $path > $HOME/PolyVerif/PolyReports/config.txt


