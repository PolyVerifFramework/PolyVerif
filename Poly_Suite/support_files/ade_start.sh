#!/bin/bash

# Open a new terminal tab to start ADE
gnome-terminal --tab --title="ADE Start" -- bash -c 'pwd; ade start; exec $SHELL'

# Wait for 5 seconds to ensure ADE starts properly
sleep 5

# Define the command to be executed inside the ADE container
cmd="cd adehome && source /opt/ros/humble/setup.bash && source /autoware/install/setup.bash && ./Poly_Suite/support_files/launch.sh && exec /bin/bash"

# Print the command for verification
#echo $cmd

# Open a new terminal tab to enter the ADE container and run the command
gnome-terminal --tab --title="ADE Entering" -- bash -c "pwd; ade enter \"${cmd}\"; exec $SHELL"
