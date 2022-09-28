#!/bin/bash

# TODO add dynamic path
echo "Running the Control Validation CSV"

#gnome-terminal --tab --title="Control Validation" --command="bash -c 'cd ../Poly_Suite; python3 controlCalculation/ControlValidation.py; echo Report Generated > ../Poly_Suite/logfiles/logInfo.txt; exit; $SHELL'"

gnome-terminal --tab --title="Control Result" --command="bash -c 'python3 controlCalculation/ControlValidation.py;$SHELL'"
