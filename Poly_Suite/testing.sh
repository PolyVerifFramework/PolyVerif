#!/bin/bash

# Set variables
IMAGE_NAME="ghcr.io/autowarefoundation/autoware-universe:humble-latest-prebuilt-cuda"
CONTAINER_NAME="ade_container"
VOLUME_PATH="$HOME/adehome"
SCRIPT_PATH="/adehome/Poly_Suite/support_files/launch.sh"  # Updated path to launch.sh script

# Function to check if container is running
is_container_running() {
    docker ps -q -f "name=$CONTAINER_NAME"
}

# Start the container with ade
start_container() {
    if [ -n "$(is_container_running)" ]; then
        echo "Container $CONTAINER_NAME is already running. Entering into the container..."
        docker exec -it $CONTAINER_NAME /bin/bash
    else
        echo "Starting a new container..."
        rocker --nvidia --x11 --user --volume $VOLUME_PATH:/adehome --name $CONTAINER_NAME -- $IMAGE_NAME /bin/bash -c "cd /adehome/Poly_Suite && ./support_files/launch.sh"
    fi
}

# Check if rocker and docker are installed
if ! command -v rocker &> /dev/null; then
    echo "rocker could not be found. Please install rocker."
    exit 1
fi

if ! command -v docker &> /dev/null; then
    echo "docker could not be found. Please install docker."
    exit 1
fi

# Start the container and run the script
start_container
