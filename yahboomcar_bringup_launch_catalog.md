# yahboomcar_bringup Launch Files Catalog

## Overview
This catalog documents the launch files in the `yahboomcar_bringup` package, which provides the core system bringup functionality for the Yahboom ROSMASTER X3Plus robot, including base system initialization, calibration, and testing capabilities.

## Package Dependencies
### Hardware Dependencies
- Yahboom ROSMASTER X3Plus robot hardware
- IMU sensor
- Motor drivers
- Optional: Camera, Lidar, or other sensors

### Software Dependencies
- ROS Noetic
- robot_state_publisher
- ekf_localization
- imu_filter_madgwick
- yahboomcar_description
- yahboomcar_msgs

## Automatic Dependencies
Each launch file automatically includes and manages its dependencies through included launch files. Here's what gets started automatically:

### Core System Dependencies
- yahboomcar_description
  - Robot model
  - TF transforms
  - URDF configuration
- yahboomcar_msgs
  - Custom message definitions
  - Service definitions
- robot_state_publisher
  - TF tree management
  - Robot state publication

### Sensor Dependencies
- IMU Driver
  - /imu/data_raw
  - /imu/mag
- Motor Driver
  - /cmd_vel
  - /odom

## Launch Files

### 1. bringup.launch
**Purpose:**
- Core system bringup for the Yahboom ROSMASTER X3Plus robot

**Nodes/Includes:**
- `robot_state_publisher`
- `driver_node`
- `odometry_publisher`
- `imu_filter_madgwick`
- `ekf_localization`

**Implementation Details:**
- Initializes the robot's base system
- Starts the motor driver and odometry publisher
- Configures and starts IMU filtering
- Sets up EKF localization
- Publishes robot state and transforms

**Topics:**
- Subscribes to:
  - /cmd_vel (velocity commands)
  - /imu/data_raw (IMU data)
  - /imu/mag (magnetometer data)
- Publishes:
  - /odom (odometry)
  - /tf (transforms)
  - /imu/data (filtered IMU data)
  - /robot_state (robot state)

**Automatic Dependencies:**
- Base System:
  - yahboomcar_description
  - yahboomcar_msgs
- Sensor System:
  - IMU driver
  - Motor driver
- Localization:
  - EKF node
  - IMU filter

**Safe Combinations:**
- Can be run with:
  - yahboomcar_ctrl (joystick control)
  - Navigation stack
  - SLAM nodes
  - Visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other bringup launch files
  - Multiple instances of driver_node
  - Multiple instances of robot_state_publisher

**Usage Example:**
```bash
# Simply run the launch file - all dependencies are handled automatically
roslaunch yahboomcar_bringup bringup.launch
```

**Troubleshooting:**
- If motors don't respond, check driver_node status
- If IMU data is missing, verify IMU connection
- If transforms are incorrect, check URDF configuration
- Verify all required topics are available:
  ```bash
  rostopic list | grep -E "cmd_vel|odom|imu|tf"
  ```

---

### 2. bringup_calib.launch
**Purpose:**
- System bringup with calibration capabilities

**Nodes/Includes:**
- All nodes from bringup.launch
- Additional calibration parameters

**Implementation Details:**
- Starts the base system with calibration settings
- Enables IMU and odometry calibration
- Provides calibration interfaces

**Topics:**
- Same as bringup.launch
- Additional calibration topics

**Automatic Dependencies:**
- Same as bringup.launch
- Calibration tools

**Safe Combinations:**
- Can be run with:
  - Calibration tools
  - Visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other bringup launch files
  - Navigation stack
  - SLAM nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup bringup_calib.launch
```

**Troubleshooting:**
- Follow calibration procedures carefully
- Monitor calibration parameters
- Check calibration results

---

### 3. calibrate_angular.launch
**Purpose:**
- Angular velocity calibration

**Nodes/Includes:**
- Calibration node
- Base system nodes

**Implementation Details:**
- Calibrates angular velocity parameters
- Tests rotation accuracy
- Stores calibration results

**Topics:**
- Subscribes to:
  - /odom
  - /cmd_vel
- Publishes:
  - Calibration results
  - Test data

**Automatic Dependencies:**
- Base System:
  - driver_node
  - odometry_publisher

**Safe Combinations:**
- Can be run with:
  - Visualization tools
  - Test tools

**Unsafe Combinations:**
- Do not run with:
  - Navigation stack
  - SLAM nodes
  - Other calibration nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup calibrate_angular.launch
```

**Troubleshooting:**
- Ensure robot is on flat surface
- Follow calibration procedure
- Monitor angular velocity

---

### 4. calibrate_imu.launch
**Purpose:**
- IMU sensor calibration

**Nodes/Includes:**
- IMU calibration node
- IMU filter

**Implementation Details:**
- Calibrates IMU parameters
- Tests IMU accuracy
- Stores calibration results

**Topics:**
- Subscribes to:
  - /imu/data_raw
  - /imu/mag
- Publishes:
  - Calibration results
  - Test data

**Automatic Dependencies:**
- IMU System:
  - IMU driver
  - IMU filter

**Safe Combinations:**
- Can be run with:
  - Visualization tools
  - Test tools

**Unsafe Combinations:**
- Do not run with:
  - Navigation stack
  - SLAM nodes
  - Other calibration nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup calibrate_imu.launch
```

**Troubleshooting:**
- Keep robot stationary during calibration
- Follow calibration procedure
- Monitor IMU data

---

### 5. calibrate_linear.launch
**Purpose:**
- Linear velocity calibration

**Nodes/Includes:**
- Calibration node
- Base system nodes

**Implementation Details:**
- Calibrates linear velocity parameters
- Tests movement accuracy
- Stores calibration results

**Topics:**
- Subscribes to:
  - /odom
  - /cmd_vel
- Publishes:
  - Calibration results
  - Test data

**Automatic Dependencies:**
- Base System:
  - driver_node
  - odometry_publisher

**Safe Combinations:**
- Can be run with:
  - Visualization tools
  - Test tools

**Unsafe Combinations:**
- Do not run with:
  - Navigation stack
  - SLAM nodes
  - Other calibration nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup calibrate_linear.launch
```

**Troubleshooting:**
- Ensure robot is on flat surface
- Follow calibration procedure
- Monitor linear velocity

---

### 6. patrol.launch
**Purpose:**
- Autonomous patrol functionality

**Nodes/Includes:**
- Base system nodes
- Patrol control node

**Implementation Details:**
- Starts base system
- Initializes patrol behavior
- Manages patrol routes

**Topics:**
- Subscribes to:
  - /odom
  - /cmd_vel
- Publishes:
  - Patrol commands
  - Status information

**Automatic Dependencies:**
- Base System:
  - All bringup.launch nodes
- Navigation:
  - Basic navigation tools

**Safe Combinations:**
- Can be run with:
  - Visualization tools
  - Monitoring tools

**Unsafe Combinations:**
- Do not run with:
  - Other navigation nodes
  - SLAM nodes
  - Other control nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup patrol.launch
```

**Troubleshooting:**
- Check patrol parameters
- Monitor robot movement
- Verify sensor data

---

### 7. test_imu.launch
**Purpose:**
- IMU testing and verification

**Nodes/Includes:**
- IMU test node
- IMU filter

**Implementation Details:**
- Tests IMU functionality
- Verifies IMU data
- Provides test results

**Topics:**
- Subscribes to:
  - /imu/data_raw
  - /imu/mag
- Publishes:
  - Test results
  - IMU data

**Automatic Dependencies:**
- IMU System:
  - IMU driver
  - IMU filter

**Safe Combinations:**
- Can be run with:
  - Visualization tools
  - Test tools

**Unsafe Combinations:**
- Do not run with:
  - Navigation stack
  - SLAM nodes
  - Other test nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup test_imu.launch
```

**Troubleshooting:**
- Keep robot stationary
- Monitor IMU data
- Check test results

---

### 8. view_odom.launch
**Purpose:**
- Odometry visualization and testing

**Nodes/Includes:**
- Base system nodes
- Visualization node

**Implementation Details:**
- Starts base system
- Visualizes odometry data
- Tests odometry accuracy

**Topics:**
- Subscribes to:
  - /odom
  - /tf
- Publishes:
  - Visualization data

**Automatic Dependencies:**
- Base System:
  - All bringup.launch nodes
- Visualization:
  - RViz
  - Plot tools

**Safe Combinations:**
- Can be run with:
  - Visualization tools
  - Test tools

**Unsafe Combinations:**
- Do not run with:
  - Navigation stack
  - SLAM nodes
  - Other visualization nodes

**Usage Example:**
```bash
roslaunch yahboomcar_bringup view_odom.launch
```

**Troubleshooting:**
- Check odometry data
- Monitor visualization
- Verify transforms

---

### 9. yahboomcar.launch
**Purpose:**
- Complete robot system bringup

**Nodes/Includes:**
- All core system nodes
- Additional configuration

**Implementation Details:**
- Starts complete robot system
- Configures all subsystems
- Initializes all sensors

**Topics:**
- All core system topics
- Additional sensor topics

**Automatic Dependencies:**
- All core dependencies
- All sensor dependencies

**Safe Combinations:**
- Can be run with:
  - All compatible nodes
  - All visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other system bringup
  - Multiple instances

**Usage Example:**
```bash
roslaunch yahboomcar_bringup yahboomcar.launch
```

**Troubleshooting:**
- Check all subsystems
- Monitor all sensors
- Verify all topics

---

### 10. yahboomcar_model.launch
**Purpose:**
- Robot model visualization

**Nodes/Includes:**
- robot_state_publisher
- Visualization nodes

**Implementation Details:**
- Loads robot model
- Publishes transforms
- Visualizes model

**Topics:**
- Subscribes to:
  - Joint states
- Publishes:
  - /tf
  - Visualization data

**Automatic Dependencies:**
- yahboomcar_description
- robot_state_publisher
- Visualization tools

**Safe Combinations:**
- Can be run with:
  - All compatible nodes
  - All visualization tools

**Unsafe Combinations:**
- Do not run with:
  - Other model viewers
  - Multiple instances

**Usage Example:**
```bash
roslaunch yahboomcar_bringup yahboomcar_model.launch
```

**Troubleshooting:**
- Check model loading
- Monitor transforms
- Verify visualization

---

## General Tips
- Always start with bringup.launch for basic functionality
- Use calibration launch files before running navigation
- Monitor system resources when running multiple nodes
- Use `rostopic list` to verify all required topics
- Use `rosnode info` to check node status
- All launch files automatically handle their dependencies
- Use `roslaunch --screen` to see detailed output
- Check package.xml for all required dependencies
- Keep robot on flat surface during calibration
- Follow calibration procedures carefully
- Monitor system logs for errors
- Use appropriate launch file for specific needs 