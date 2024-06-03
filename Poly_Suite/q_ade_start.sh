#!/bin/bash

echo "Starting the ADE .."
gnome-terminal --tab --title="AWSIM Start" --command="bash -c 'cd ../;./Poly_Suite/support_files/awsim.sh;exit;$SHELL'"

sh ./support_files/ade_start.sh





