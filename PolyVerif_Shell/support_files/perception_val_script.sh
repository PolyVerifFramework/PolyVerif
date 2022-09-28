#!/bin/bash

# TODO add dynamic path
echo "Running the perception validation csv"

gnome-terminal --tab --title="Perception Result" --command="bash -c 'python3 perceptionCalculation/PerceptionValidation.py;$SHELL'"

