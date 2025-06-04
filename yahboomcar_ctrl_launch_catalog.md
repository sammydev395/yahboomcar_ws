# yahboomcar_ctrl Launch Files Catalog

## Overview
This catalog documents the launch files in the `yahboomcar_ctrl` package, which provides various control interfaces for the Yahboom ROSMASTER X3Plus robot, including joystick control, voice control, and keyboard control capabilities.

## Package Dependencies
### Hardware Dependencies
- Yahboom ROSMASTER X3Plus robot hardware
- Joystick controller (for joystick control)
- Microphone (for voice control)
- Speakers (for voice feedback)

### Software Dependencies
- ROS Noetic
- joy (joystick driver)
- sound_play (for voice feedback)
- yahboomcar_bringup
- yahboomcar_msgs

## Automatic Dependencies
Each launch file automatically includes and manages its dependencies through included launch files. Here's what gets started automatically:

### Core System Dependencies
- yahboomcar_bringup
  - Robot drivers
  - TF transforms
  - Core functionality
- yahboomcar_msgs
  - Custom message definitions
  - Service definitions

### Control Dependencies
- Joystick Driver
  - /joy topic
  - /JoyState topic
- Voice System
  - /recognizer/output
  - /sound_play

## Launch Files

### 1. yahboom_joy.launch
**Purpose:**
- Joystick control interface for the robot

**Nodes/Includes:**
- `joy_node` (joystick driver)
- `yahboom_joy` (joystick control node)

**Implementation Details:**
- Starts the joystick driver
- Initializes the joystick control node
- Maps joystick inputs to robot commands
- Provides visual feedback

**Topics:**
- Subscribes to:
  - /joy (joystick data)
  - /cmd_vel (current velocity)
- Publishes:
  - /JoyState (joystick state)
  - /cmd_vel (velocity commands)

**Automatic Dependencies:**
- Base System:
  - yahboomcar_bringup
  - yahboomcar_msgs
- Control System:
  - joy package
  - joystick driver

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other joystick control nodes
  - Voice control nodes
  - Multiple instances of joy_node

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_ctrl yahboom_joy.launch
```

**Troubleshooting:**
- If joystick doesn't respond, check device connection
- If commands don't work, verify joystick mapping
- If node crashes, check joystick permissions
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "joy|JoyState|cmd_vel"
  ```

---

### 2. voice_ctrl.launch
**Purpose:**
- Voice control interface for the robot

**Nodes/Includes:**
- `voice_ctrl` (voice control node)
- `sound_play` (voice feedback)

**Implementation Details:**
- Starts the voice control system
- Initializes voice recognition
- Maps voice commands to robot actions
- Provides voice feedback

**Topics:**
- Subscribes to:
  - /recognizer/output (voice commands)
  - /cmd_vel (current velocity)
- Publishes:
  - /cmd_vel (velocity commands)
  - /sound_play (voice feedback)

**Automatic Dependencies:**
- Base System:
  - yahboomcar_bringup
  - yahboomcar_msgs
- Voice System:
  - sound_play
  - voice recognition

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Navigation stack
  - SLAM nodes
  - Visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other voice control nodes
  - Joystick control nodes
  - Multiple instances of voice recognition

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_ctrl voice_ctrl.launch
```

**Troubleshooting:**
- If voice recognition fails, check microphone
- If commands don't work, verify command mapping
- If feedback is missing, check speakers
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "recognizer|sound_play|cmd_vel"
  ```

---

### 3. voice_ctrl_arm.launch
**Purpose:**
- Voice control interface for the robot arm

**Nodes/Includes:**
- `voice_ctrl_arm` (arm voice control node)
- `sound_play` (voice feedback)

**Implementation Details:**
- Starts the arm voice control system
- Initializes voice recognition
- Maps voice commands to arm movements
- Provides voice feedback

**Topics:**
- Subscribes to:
  - /recognizer/output (voice commands)
  - /arm_state (current arm state)
- Publishes:
  - /arm_cmd (arm commands)
  - /sound_play (voice feedback)

**Automatic Dependencies:**
- Base System:
  - yahboomcar_bringup
  - yahboomcar_msgs
- Voice System:
  - sound_play
  - voice recognition
- Arm System:
  - Arm driver
  - Arm state publisher

**Safe Combinations:**
- Can be run with:
  - yahboomcar_bringup (base system)
  - Arm visualization
  - Other visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other arm control nodes
  - Other voice control nodes
  - Multiple instances of voice recognition

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_ctrl voice_ctrl_arm.launch
```

**Troubleshooting:**
- If voice recognition fails, check microphone
- If arm doesn't move, verify arm connection
- If feedback is missing, check speakers
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "recognizer|sound_play|arm"
  ```

---

## General Tips
- Always start with yahboomcar_bringup before control nodes
- Use appropriate control interface for your needs
- Monitor system resources when running multiple nodes
- Use `rostopic list` to verify all required topics
- Use `rosnode info` to check node status
- All launch files automatically handle their dependencies
- Use `roslaunch --screen` to see detailed output
- Check package.xml for all required dependencies
- Keep control interfaces separate
- Follow control procedures carefully
- Monitor system logs for errors
- Use appropriate launch file for specific needs
- Test control interfaces in safe environment
- Verify all hardware connections
- Check control mappings
- Monitor feedback systems 