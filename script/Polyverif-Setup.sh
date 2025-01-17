#!/bin/bash
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt install python3.8
sudo apt-get install -y libqt5widgets5
sudo apt-get install apache2
sudo apt update
sudo apt install python3-pip
sudo apt-get install zenity
#pip install gdown
sudo apt-get install wget
sudo apt update

# Check if the PolyVerif directory already exists
if [ -d "$HOME/PolyVerif" ]; then
    # close_progress
    zenity --width=300 --error --text="Directory PolyVerif already exists. Delete the existing PolyVerif directory and try again."
    exit 9999
fi

# Install required packages
sudo apt update
sudo apt install git
sudo apt-get install python3-gi
pip3 install watchdog
pip3 install pandas

# Install ade-cli
cd ${HOME}
sudo wget https://gitlab.com/ApexAI/ade-cli/uploads/85a5af81339fe55555ee412f9a3a734b/ade+x86_64 -P /usr/local/bin
sudo mv /usr/local/bin/ade+x86_64 /usr/local/bin/ade
sudo chmod +x /usr/local/bin/ade
yes | ade update-cli

# Create adehome directory and clone AutowareAuto repository
mkdir -p ~/adehome
touch ~/adehome/.adehome
git clone https://gitlab.com/autowarefoundation/autoware.auto/AutowareAuto.git
mv AutowareAuto/ ~/adehome/
sudo chmod 666 /var/run/docker.sock
sudo chmod 777 ~/adehome/AutowareAuto/*
sudo chmod 777 ~/adehome/AutowareAuto/.*

# Download PolyVerif
# show_progress "Cloning PolyVerif repository..."
git clone --single-branch --branch PolyVerif-OSSDC-SIM https://github.com/MaheshM99/PolyVerif.git
mv PolyVerif/* ~/adehome
cp ~/PolyVerif/.aderc ~/adehome/AutowareAuto

# Set permissions
sudo chmod 777 ~/adehome/*
sudo chmod 777 ~/adehome/.*
sudo chmod 777 ~/adehome/Poly_Suite/*
sudo chmod 777 ~/adehome/Poly_Suite/.*
sudo chmod 777 ~/adehome/Poly_Suite/support_files/*
sudo chmod 777 ~/adehome/Poly_Suite/support_files/.*

cd ~/adehome
sudo cp index.html /var/www/html/index.html

# Download the file from Google Drive to adehome
# Extract the downloaded file in adehome
cd ~/adehome
#gdown https://drive.google.com/uc?id=1sPAOsk_AwnXgeW9QW3aTJPa3TjmjDNWl
wget --content-disposition 'https://drive.usercontent.google.com/download?id=1sPAOsk_AwnXgeW9QW3aTJPa3TjmjDNWl&confirm=t&uuid=a8b3a20c-7bf4-4f3e-9a1d-e1713d611152'
unzip downloadOSSDC-SIM-v1_1-Linux.zip
sudo rm -rf downloadOSSDC-SIM-v1_1-Linux.zip
cd OSSDC-SIM-v1_1-Linux && sudo chmod +x run-OSSDC-SIM-v1.sh OSSDC-SIM

cd ~/adehome/OSSDC-SIM-v1_1-Linux/2021.3-ossdc
sudo chmod +x user_change.py
python3 user_change.py

# # Change the working directory to home directory
cd $HOME

# Start ADE within a new GNOME Terminal tab
gnome-terminal --tab --title="ADE Start" --command="bash -c 'cd adehome/AutowareAuto;  ade start -- --net=host --privileged; echo ADE Started, Now Entering into Docker.. > ../Poly_Suite/logfiles/logInfo.txt; sleep 1; ade enter ./polyverif_package.sh; echo Done; zenity  --width=300  --info --text=\"Polyverif Setup Completed\"; $SHELL'"
