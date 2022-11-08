#!/bin/bash


if [ -d "$HOME/PolyVerif" ] 
then
    echo "Directory PolyVerif already exists."
    echo "Delete existed PolyVerif Directory and try again." 
    exit 9999
fi

sudo apt install git
sudo apt update
sudo apt-get install python3-gi
pip install watchdog
sudo apt update
pip install pandas



cd ${HOME}
sudo wget https://gitlab.com/ApexAI/ade-cli/uploads/85a5af81339fe55555ee412f9a3a734b/ade+x86_64  -P /usr/local/bin
sudo mv /usr/local/bin/ade+x86_64 /usr/local/bin/ade
sudo chmod +x /usr/local/bin/ade
yes | ade update-cli


mkdir -p ~/adehome
touch ~/adehome/.adehome
git clone  https://gitlab.com/autowarefoundation/autoware.auto/AutowareAuto.git
mv AutowareAuto/  ~/adehome/
sudo chmod 666 /var/run/docker.sock
sudo chmod 777 ~/adehome/AutowareAuto/*
sudo chmod 777 ~/adehome/AutowareAuto/.*



git clone https://github.com/MaheshM99/PolyVerif.git

echo "cloning in progress ... "
 
mv  PolyVerif/* ~/adehome 
cp ~/PolyVerif/.aderc ~/adehome/AutowareAuto

sudo chmod 777 ~/adehome/*
sudo chmod 777 ~/adehome/.*
sudo chmod 777 ~/adehome/Poly_Suite/*
sudo chmod 777 ~/adehome/Poly_Suite/.*
sudo chmod 777 ~/adehome/Poly_Suite/support_files/*
sudo chmod 777 ~/adehome/Poly_Suite/support_files/.*
sudo chmod 777 ~/adehome/lg_sim_06/lgsvlsimulator-linux64-2020.06/*
sudo chmod 777 ~/adehome/lg_sim_06/lgsvlsimulator-linux64-2020.06/.*
 
echo "done."
cd ~/adehome/Scenic && sudo pip3 install --upgrade pip && pip3 install scenic && export PATH=$PATH:${home}/.local/bin && curl -sSL https://install.python-poetry.org | python3 - && poetry env list && poetry install && poetry self update 1.0.0
pip3 install --user -e .