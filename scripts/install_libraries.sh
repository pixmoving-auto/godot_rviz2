#!/bin/bash

# Install dependencies for building on Debian/Ubuntu-based systems

set -e

# Update package list
sudo apt-get update

# Install essential build tools and libraries
sudo apt-get install -y build-essential scons pkg-config libx11-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev libglu-dev libasound2-dev libpulse-dev libudev-dev libxi-dev libxrandr-dev yasm

# Check if installation was successful
if [ $? -eq 0 ]; then
    echo -e "\e[32mDependencies installed successfully.\e[0m"
else
    echo -e "\e[31mFailed to install dependencies.\e[0m"
    exit 1
fi

# Install Godot 3
sudo apt-get install -y godot3

# Check if installation was successful
if [ $? -eq 0 ]; then
    echo -e "\e[32mGodot 3 installed successfully.\e[0m"
else
    echo -e "\e[31mFailed to install Godot 3.\e[0m"
    exit 1
fi

# Continue with the rest of your script...
