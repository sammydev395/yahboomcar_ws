# yahboomcar_ctrl/launch Launch File Catalog

---

## yahboomcar_ctrl/launch/yahboom_joy.launch
**Purpose:** Main joystick/remote control for the robot base.

**Starts:**
- Joystick node (`joy_node`)
- Yahboom joystick control node (`yahboom_joy.py`)

**Use:** For controlling the robot base with a joystick or remote.

---

## yahboomcar_ctrl/launch/yahboom_keyboard.launch
**Purpose:** Keyboard control for the robot base.

**Starts:**
- Yahboom keyboard control node (`yahboom_keyboard.py`)

**Use:** For controlling the robot base with a keyboard.

---

## yahboomcar_ctrl/launch/twist_joy.launch
**Purpose:** Joystick control for turtlesim and twist-based robots.

**Starts:**
- Turtlesim node
- Joystick node (`joy_node`)
- Twist joystick control node (`twist_joy.py`)

**Use:** For controlling turtlesim or twist-based robots with a joystick.

---

## yahboomcar_ctrl/launch/turtlebot_joy.launch
**Purpose:** Joystick control for Turtlebot robots.

**Starts:**
- Joystick node (`joy_node`)
- Turtlebot joystick control node (`turtlebot_joy.py`)

**Use:** For controlling Turtlebot robots with a joystick. 