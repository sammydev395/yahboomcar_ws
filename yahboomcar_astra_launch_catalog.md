# yahboomcar_astra/launch Launch File Catalog

---

## yahboomcar_astra/launch/KCFTracker.launch
**Purpose:** Object tracking using the KCF algorithm with Astra camera input.

**Starts:**
- Astra camera node (via orbbec_camera/astraproplus.launch)
- Joystick/remote control (via yahboomcar_ctrl/yahboom_joy.launch)
- Low-level driver node (via yahboomcar_bringup/yahboomcar.launch)
- KCF tracker node (`KCFTracker_node`)

**Use:** For object tracking demos using the Astra camera.

---

## yahboomcar_astra/launch/colorHSV.launch
**Purpose:** Color detection using HSV with Astra camera input.

**Starts:**
- Color detection node (`colorHSV.py`)

**Use:** For color-based detection or tracking using the Astra camera.

---

## yahboomcar_astra/launch/colorTracker.launch
**Purpose:** Color tracking and detection with Astra camera input.

**Starts:**
- Joystick/remote control (via yahboomcar_ctrl/yahboom_joy.launch)
- Astra camera node (via orbbec_camera/astraproplus.launch)
- Low-level driver node (via yahboomcar_bringup/yahboomcar.launch)
- Color tracking node (`colorTracker.py`)
- Color detection node (`colorHSV.py`)

**Use:** For color tracking and detection demos using the Astra camera. 