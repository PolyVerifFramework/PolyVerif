#!/bin/bash

# TODO add dynamic path
echo "Running the Control Validation CSV"

gnome-terminal --tab --title="Control Validation" --command="bash -c 'cd $HOME/PolyVerif; python3 controlCalculation/ControlValidation.py; echo Report Generated;$SHELL'"

