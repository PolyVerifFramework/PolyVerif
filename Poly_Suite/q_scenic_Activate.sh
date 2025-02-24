#!/bin/bash

echo "scenic"
./support_files/scenic_run.sh

#gnome-terminal --tab -- "bash -c 'cd ../Scenic;poetry install export PATH=$PATH:/home/acclivis_linux2/.local/bin
#;scenic examples/driving/badlyParkedCarPullingIn.scenic; $SHELL'"
