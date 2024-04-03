#!/bin/bash

# TODO add dynamic path
echo "Running the detection validation csv"

gnome-terminal --tab --title="Detection Validation Result" --command="bash -c 'cd $HOME/PolyVerif; python3 detectionCalculation/DetectionValidation.py;echo Report Generated;exit;$SHELL'"

