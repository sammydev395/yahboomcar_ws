# yahboomcar_mediapipe Launch Files Catalog

## Overview
This catalog documents the launch files in the `yahboomcar_mediapipe` package, which provides various MediaPipe-based computer vision capabilities including hand detection, pose estimation, face mesh, and holistic tracking.

## Package Dependencies
### Hardware Dependencies
- USB Camera (connected to robot)
- Sufficient CPU/GPU for MediaPipe processing
- Optional: Display for visualization

### Software Dependencies
- ROS Noetic
- MediaPipe
- OpenCV
- NumPy
- yahboomcar_bringup (for base system)

## Automatic Dependencies
Each launch file automatically includes and manages its dependencies through included launch files. Here's what gets started automatically:

### Base System Dependencies
- yahboomcar_bringup
  - Robot drivers
  - TF transforms
  - Core functionality
- yahboomcar_ctrl
  - Joystick control
  - /JoyState topic
  - /cmd_vel topic
- Camera Driver
  - /camera/rgb/image_raw
  - /camera/depth/image_raw (if available)

### MediaPipe Processing Dependencies
- MediaPipe Python package
- OpenCV
- NumPy
- ROS image processing tools

## Launch Files

### 1. 01_HandDetector.launch
**Purpose:**
- Hand detection and tracking using MediaPipe

**Node:**
- `handDetector` (runs `01_HandDetector.py`)

**Implementation Details:**
- Captures video from the robot's camera
- Uses MediaPipe for hand landmark detection
- Processes and visualizes hand landmarks
- Provides real-time hand tracking visualization

**Topics:**
- Subscribes to: 
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes: 
  - Processed images with hand landmarks
  - /cmd_vel (if control enabled)

**Automatic Dependencies:**
- Camera Driver:
  - Automatically starts the camera driver
  - Provides RGB image stream
- Base System:
  - Includes yahboomcar_bringup
  - Provides TF and core functionality
- Control System:
  - Includes yahboomcar_ctrl
  - Provides joystick control

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other hand detection nodes
  - Other nodes using the same camera
  - Multiple instances of MediaPipe hand tracking

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_mediapipe 01_HandDetector.launch
```

**Troubleshooting:**
- Ensure good lighting for reliable hand detection
- Check camera feed quality and frame rate
- Monitor CPU usage during processing
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

### 2. 02_PoseDetector.launch
**Purpose:**
- Full-body pose detection and tracking using MediaPipe

**Node:**
- `PoseDetector` (runs `02_PoseDetector.py`)

**Implementation Details:**
- Captures video from the robot's camera
- Uses MediaPipe Pose for body landmark detection
- Processes and visualizes body landmarks
- Provides real-time pose tracking visualization

**Topics:**
- Subscribes to:
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes:
  - Processed images with pose landmarks
  - /cmd_vel (if control enabled)

**Automatic Dependencies:**
- Camera Driver:
  - Automatically starts the camera driver
  - Provides RGB image stream
- Base System:
  - Includes yahboomcar_bringup
  - Provides TF and core functionality
- Control System:
  - Includes yahboomcar_ctrl
  - Provides joystick control

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other pose detection nodes
  - Other nodes using the same camera
  - Multiple instances of MediaPipe pose tracking

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_mediapipe 02_PoseDetector.launch
```

**Troubleshooting:**
- Ensure full body is visible in camera frame
- Check for adequate lighting
- Monitor system resources during processing
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

### 3. 03_Holistic.launch
**Purpose:**
- Combined face, hand, and pose detection using MediaPipe Holistic

**Node:**
- `Holistic` (runs `03_Holistic.py`)

**Implementation Details:**
- Captures video from the robot's camera
- Uses MediaPipe Holistic for comprehensive tracking
- Processes face, hands, and body landmarks
- Provides real-time visualization of all detected features

**Topics:**
- Subscribes to:
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes:
  - Processed images with holistic landmarks
  - /cmd_vel (if control enabled)

**Automatic Dependencies:**
- Camera Driver:
  - Automatically starts the camera driver
  - Provides RGB image stream
- Base System:
  - Includes yahboomcar_bringup
  - Provides TF and core functionality
- Control System:
  - Includes yahboomcar_ctrl
  - Provides joystick control

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other MediaPipe tracking nodes
  - Other nodes using the same camera
  - Multiple instances of MediaPipe holistic tracking

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_mediapipe 03_Holistic.launch
```

**Troubleshooting:**
- Requires more system resources than individual tracking
- Ensure good lighting and clear view of subject
- Monitor CPU usage during processing
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

### 4. 04_FaceMesh.launch
**Purpose:**
- Detailed face mesh detection and tracking using MediaPipe

**Node:**
- `FaceMesh` (runs `04_FaceMesh.py`)

**Implementation Details:**
- Captures video from the robot's camera
- Uses MediaPipe Face Mesh for detailed facial landmarks
- Processes and visualizes face mesh
- Provides real-time face tracking visualization

**Topics:**
- Subscribes to:
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes:
  - Processed images with face mesh
  - /cmd_vel (if control enabled)

**Automatic Dependencies:**
- Camera Driver:
  - Automatically starts the camera driver
  - Provides RGB image stream
- Base System:
  - Includes yahboomcar_bringup
  - Provides TF and core functionality
- Control System:
  - Includes yahboomcar_ctrl
  - Provides joystick control

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other face detection nodes
  - Other nodes using the same camera
  - Multiple instances of MediaPipe face mesh

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_mediapipe 04_FaceMesh.launch
```

**Troubleshooting:**
- Ensure good lighting on face
- Check camera focus and resolution
- Monitor processing performance
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

### 5. 05_FaceEyeDetection.launch
**Purpose:**
- Face and eye detection with detailed tracking using MediaPipe

**Node:**
- `FaceEyeDetection` (runs `05_FaceEyeDetection.py`)

**Implementation Details:**
- Captures video from the robot's camera
- Uses MediaPipe for face and eye landmark detection
- Processes and visualizes face and eye features
- Provides real-time tracking visualization

**Topics:**
- Subscribes to:
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes:
  - Processed images with face and eye landmarks
  - /cmd_vel (if control enabled)

**Automatic Dependencies:**
- Camera Driver:
  - Automatically starts the camera driver
  - Provides RGB image stream
- Base System:
  - Includes yahboomcar_bringup
  - Provides TF and core functionality
- Control System:
  - Includes yahboomcar_ctrl
  - Provides joystick control

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other face/eye detection nodes
  - Other nodes using the same camera
  - Multiple instances of MediaPipe face detection

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_mediapipe 05_FaceEyeDetection.launch
```

**Troubleshooting:**
- Ensure good lighting on face
- Check camera focus and resolution
- Monitor processing performance
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

### 6. cloud_Viewer.launch
**Purpose:**
- Visualization of MediaPipe point cloud data

**Node:**
- `mediapipe_Viewer` (runs `mediapipe_point`)

**Implementation Details:**
- Subscribes to MediaPipe point cloud data
- Provides 3D visualization of detected landmarks
- Enables interactive viewing of tracking data

**Topics:**
- Subscribes to:
  - MediaPipe point cloud data
  - Camera input (if needed)
- Publishes:
  - Visualization data

**Automatic Dependencies:**
- Base System:
  - Includes yahboomcar_bringup
  - Provides TF and core functionality
- Visualization Tools:
  - RViz
  - Point cloud visualization tools

**Safe Combinations:**
- Can be run with:
  - Any MediaPipe detection node
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Multiple instances of the viewer
  - Other point cloud visualization nodes

**Usage Example:**
```bash
# First start a detection node
roslaunch yahboomcar_mediapipe 01_HandDetector.launch
# Then start the viewer
roslaunch yahboomcar_mediapipe cloud_Viewer.launch
```

**Troubleshooting:**
- Ensure detection node is running
- Check point cloud data topics
- Monitor system resources
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|pointcloud"
  ```

---

## General Tips
- For best results, use in well-lit environments with minimal background clutter
- Make sure the correct camera device is selected in the scripts
- Use `rqt_image_view` to verify camera input
- Check ROS logs for errors if nodes do not start or crash
- Monitor CPU usage when running multiple MediaPipe nodes
- Use `rostopic list` to verify all required topics are available
- Use `rosnode info` to check node status and connections
- Consider system resources when running multiple detection nodes
- Use appropriate launch file based on specific tracking needs
- All launch files automatically handle their dependencies - no need to manually start other packages
- Use `roslaunch --screen` to see detailed output during startup
- Check package.xml for all required dependencies 