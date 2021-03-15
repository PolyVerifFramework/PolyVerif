#!/bin/bash

# TODO add dynamic path
echo "Running the perception validation csv"

gnome-terminal --tab --title="Perception Result" --command="bash -c 'cd ../Poly_Suite; python3 perceptionCalculation/PerceptionValidation.py; exit; $SHELL'"

