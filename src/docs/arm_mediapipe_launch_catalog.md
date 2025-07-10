# arm_mediapipe Launch Files Catalog

## Overview
This catalog documents the launch files in the `arm_mediapipe` package, which provides hand and pose-based control for the robot arm using MediaPipe and a USB camera.

## Package Dependencies
### Hardware Dependencies
- USB Camera (connected to arm)
- Robot Arm Hardware
- Joystick (optional, for manual control)

### Software Dependencies
- ROS Noetic
- MediaPipe
- OpenCV
- web_video_server
- yahboomcar_bringup
- yahboomcar_ctrl

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

### 1. mediaArm.launch
**Purpose:**
- Integrates joystick control, base robot bringup, web video streaming, and custom image message conversion for the arm camera.

**Nodes/Includes:**
- Includes `yahboomcar_ctrl/launch/yahboom_joy.launch` (joystick control)
- Includes `yahboomcar_bringup/launch/yahboomcar.launch` (base robot bringup)
- `web_video_server` (web video streaming)
- `msgToimg` (converts custom Image_Msg to standard ROS Image)

**Implementation Details:**
- Starts joystick and base robot nodes for full system control
- `web_video_server` streams camera images over HTTP for remote viewing
- `msgToimg` subscribes to `/image_msg` (custom message from arm camera), decodes and republishes as `/image` (standard sensor_msgs/Image)
- Enables integration of arm camera with standard ROS tools and visualization

**Topics:**
- Subscribes to: 
  - `/image_msg` (custom image message)
  - /JoyState (for control)
- Publishes: 
  - `/image` (standard image)
  - web video stream
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
- Web Server:
  - Starts web_video_server
  - Provides HTTP streaming

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - yahboomcar_ctrl (joystick control)
  - web_video_server (visualization)
- Safe to run alongside:
  - Navigation stack
  - SLAM nodes
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other arm control nodes (01_HandCtrlArm, 02_PoseCtrlArm)
  - Other camera processing nodes that use the same camera
  - Multiple instances of web_video_server

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch arm_mediapipe mediaArm.launch
```

**Troubleshooting:**
- If no image appears, check that the arm camera is connected and `/image_msg` is being published
- If web video server is not accessible, check network/firewall settings
- If joystick control doesn't work, verify yahboomcar_ctrl is properly installed
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "image|JoyState|cmd_vel"
  ```

---

### 2. 01_HandCtrlArm.launch
**Purpose:**
- Hand gesture-based control of the robot arm using MediaPipe hand tracking

**Node:**
- `HandCtrlArm_node` (runs `01_HandCtrlArm.py`)

**Implementation Details:**
- Captures video from the arm's USB camera
- Uses MediaPipe to detect hand landmarks and recognize gestures
- Maps specific hand gestures (e.g., number of fingers up) to arm movement commands
- Publishes velocity or arm joint commands based on recognized gestures
- Provides visual feedback (e.g., FPS, gesture overlay)

**Topics:**
- Subscribes to:
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes:
  - Arm control commands
  - Processed images
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
  - mediaArm.launch (for camera and base system)
  - Navigation stack
  - SLAM nodes
  - Visualization tools

**Unsafe Combinations:**
- Do not run with:
  - 02_PoseCtrlArm.launch (conflicts for arm control)
  - Other hand tracking nodes
  - Other nodes that control the arm
  - Multiple instances of MediaPipe hand tracking

**Usage Example:**
```bash
# First start the base system
roslaunch arm_mediapipe mediaArm.launch
# Then start hand control
roslaunch arm_mediapipe 01_HandCtrlArm.launch
```

**Troubleshooting:**
- Ensure good lighting and clear hand visibility for reliable gesture recognition
- If arm does not move, check that the control topics are being published and received
- If MediaPipe detection fails, verify camera feed and lighting conditions
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

### 3. 02_PoseCtrlArm.launch
**Purpose:**
- Full-body pose-based control of the robot arm using MediaPipe holistic pose estimation

**Node:**
- `PoseCtrlArm` (runs `02_PoseCtrlArm.py`)

**Implementation Details:**
- Captures video from the arm's USB camera
- Uses MediaPipe Holistic to detect body and hand landmarks
- Calculates joint angles from detected keypoints
- Maps body/arm pose to robot arm joint commands
- Publishes joint commands to move the arm in sync with the user's pose
- Provides visual feedback (e.g., FPS, pose overlay)

**Topics:**
- Subscribes to:
  - Camera input (/camera/rgb/image_raw)
  - /JoyState (for control)
- Publishes:
  - Arm joint commands
  - Processed images
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
  - mediaArm.launch (for camera and base system)
  - Navigation stack
  - SLAM nodes
  - Visualization tools

**Unsafe Combinations:**
- Do not run with:
  - 01_HandCtrlArm.launch (conflicts for arm control)
  - Other pose tracking nodes
  - Other nodes that control the arm
  - Multiple instances of MediaPipe holistic tracking

**Usage Example:**
```bash
# First start the base system
roslaunch arm_mediapipe mediaArm.launch
# Then start pose control
roslaunch arm_mediapipe 02_PoseCtrlArm.launch
```

**Troubleshooting:**
- Ensure the camera captures the full body/arm for accurate pose estimation
- If arm does not follow, check joint command topics and MediaPipe detection
- If pose detection is unstable, ensure good lighting and clear background
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "camera|JoyState|cmd_vel"
  ```

---

## General Tips
- For best results, use in well-lit environments with minimal background clutter
- Make sure the correct camera device is selected in the scripts
- Use `rqt_image_view` or the web video server to verify camera input
- Check ROS logs for errors if nodes do not start or crash
- Always start mediaArm.launch before other control nodes
- Monitor CPU usage when running multiple MediaPipe nodes
- Use `rostopic list` to verify all required topics are available
- Use `rosnode info` to check node status and connections
- All launch files automatically handle their dependencies - no need to manually start other packages
- Use `roslaunch --screen` to see detailed output during startup
- Check package.xml for all required dependencies 