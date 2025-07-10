#!/bin/bash

# Source ORB_SLAM2 setup
source ~/software/ORB_SLAM2/Examples/ROS/ORB_SLAM2/build/devel/setup.bash

# Source workspace setup
source /root/yahboomcar_ws/devel/setup.bash

# Launch the camera ORB SLAM
roslaunch yahboomcar_slam camera_orb_slam.launch "$@" 