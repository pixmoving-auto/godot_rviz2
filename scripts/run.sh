#!/bin/bash

# Set paths
godot_dir="/home/pixbus/pix/robobus/teddy_ws/godot_rviz2/godot"
autoware_path="/home/pixbus/pix/robobus/autoware-robobus"

# Navigate to the Godot directory
cd "$godot_dir"

# Source Autoware setup.bash
source "$autoware_path/install/setup.bash"

# Source .bashrc
source ~/.bashrc

# Run Godot tools
"$godot_dir/bin/godot.x11.tools.64"
