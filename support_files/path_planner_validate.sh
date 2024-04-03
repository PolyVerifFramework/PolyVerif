#!/bin/bash

echo "Start AD Path Planner Validation "
gnome-terminal --tab --title="Path Planner Validation" --command="bash -c 'cd $HOME/PolyVerif; python3 pathPlannerCalculation/pathPlannerValidation.py; echo Report Generated;$SHELL'"



