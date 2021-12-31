#!/bin/bash

date=$(date +"%d-%m-%Y")
time=$(date +"%T")
date=${date//-/_}
time=${time//:/_}
fname=$date"_"$time
tc=$1
tc=${tc//.py/}
cd ../PolyReports/Validation_report

echo "PolyReports/Validation_report/"$fname"/"$tc > config.txt
echo "PolyReports/Validation_report/"$fname"/"$tc > config1.txt

mkdir $fname
cd $fname
echo $tc
mkdir $tc