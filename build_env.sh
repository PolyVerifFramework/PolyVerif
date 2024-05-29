#!/bin/bash

# Set permissions
sudo apt-get install -y libqt5widgets5
sudo apt-get install apache2 -y
sudo apt-get install zenity
sudo apt install python3
sudo apt install python3-pip
pip install pandas
sudo apt install wget
sudo wget https://gitlab.com/ApexAI/ade-cli/uploads/85a5af81339fe55555ee412f9a3a734b/ade+x86_64 -P /usr/local/bin
sudo mv /usr/local/bin/ade+x86_64 /usr/local/bin/ade
sudo chmod +x /usr/local/bin/ade

# Start ADE within a new GNOME Terminal tab
gnome-terminal --tab --title="ADE Start" --command="bash -c 'cd adehome/AutowareAuto;  ade start -- --net=host --privileged; echo ADE Started, Now Entering into Docker.. > ../Poly_Suite/logfiles/logInfo.txt; sleep 1; ade enter ./polyverif_package.sh; echo Done; zenity  --width=300  --info --text=\"Polyverif Setup Completed\"; $SHELL'"

echo "ADE started on the host machine."

