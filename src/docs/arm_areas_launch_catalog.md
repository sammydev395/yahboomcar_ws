# Arm-Related Areas Launch File Catalog

---

## arm_autopilot/launch/arm_autopilot.launch
**Purpose:** Arm autopilot demo with camera, remote control, and web video streaming.

**Starts:**
- Joystick/remote control (via yahboomcar_ctrl/yahboom_joy.launch)
- Low-level driver node (via yahboomcar_bringup/yahboomcar.launch)
- Web video server
- Arm autopilot node (`autopilot_main.py`)

**Use:** For autonomous arm control demos with camera and remote control.

---

## arm_color_transport/launch/transport_base.launch
**Purpose:** Arm color transport demo with navigation, mapping, and web video streaming.

**Starts:**
- Map server
- Lidar and robot base bringup (via yahboomcar_nav/laser_bringup.launch)
- AMCL localization
- Move base for navigation
- Web video server
- Marker drawing node (`DrawMarker.py`)
- Color transport node (`transport_main.py`)

**Use:** For color-based object transport demos with navigation and visualization.

---

## arm_color_transport/launch/transport_rviz.launch
**Purpose:** RViz visualization for arm color transport.

**Starts:**
- RViz with arm color transport config

**Use:** For visualizing arm color transport in RViz.

---

## arm_mediapipe/launch/01_HandCtrlArm.launch
**Purpose:** Hand gesture control for the arm using MediaPipe.

**Starts:**
- Hand control node (`01_HandCtrlArm.py`)

**Use:** For controlling the arm with hand gestures.

---

## arm_mediapipe/launch/02_PoseCtrlArm.launch
**Purpose:** Pose-based control for the arm using MediaPipe.

**Starts:**
- Pose control node (`02_PoseCtrlArm.py`)

**Use:** For controlling the arm with body pose estimation.

---

## arm_mediapipe/launch/mediaArm.launch
**Purpose:** MediaPipe-based arm demo with remote control and web video streaming.

**Starts:**
- Joystick/remote control (via yahboomcar_ctrl/yahboom_joy.launch)
- Low-level driver node (via yahboomcar_bringup/yahboomcar.launch)
- Web video server
- Message-to-image node (`msgToimg.py`)

**Use:** For MediaPipe-based arm demos with visualization and remote control. 