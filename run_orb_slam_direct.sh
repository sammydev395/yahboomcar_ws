#!/bin/bash

# Set ORB_SLAM2 environment
export ORB_SLAM2_PATH=~/software/ORB_SLAM2/Examples/ROS/ORB_SLAM2
export LD_LIBRARY_PATH=$ORB_SLAM2_PATH/../../../lib:$LD_LIBRARY_PATH

# Source ROS workspace
source /root/yahboomcar_ws/devel/setup.bash

# Get the orb_slam_type argument (default to mono)
ORB_SLAM_TYPE=${1:-mono}

echo "Starting ORB_SLAM2 with type: $ORB_SLAM_TYPE using Astra camera"

# Launch the camera and other nodes first
roslaunch yahboomcar_slam camera_orb_slam.launch orb_slam_type:=$ORB_SLAM_TYPE &
CAMERA_PID=$!

# Wait a moment for camera to start
sleep 3

# Launch ORB_SLAM2 directly based on type
case $ORB_SLAM_TYPE in
    "mono")
        echo "Starting ORB_SLAM2 Mono..."
        $ORB_SLAM2_PATH/Mono ~/software/ORB_SLAM2/Vocabulary/ORBvoc.txt /root/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    "monoAR")
        echo "Starting ORB_SLAM2 MonoAR..."
        $ORB_SLAM2_PATH/MonoAR ~/software/ORB_SLAM2/Vocabulary/ORBvoc.txt /root/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    "rgbd")
        echo "Starting ORB_SLAM2 RGBD..."
        $ORB_SLAM2_PATH/RGBD ~/software/ORB_SLAM2/Vocabulary/ORBvoc.txt /root/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    *)
        echo "Unknown ORB_SLAM type: $ORB_SLAM_TYPE"
        echo "Available types: mono, monoAR, rgbd"
        kill $CAMERA_PID
        exit 1
        ;;
esac

# Cleanup
kill $CAMERA_PID 