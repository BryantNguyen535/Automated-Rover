# ZotGPT: Gerbil Portable Transportation

An autonomous line-tracking and object-retrieval rover designed for the ENGR 7B course at the University of California, Irvine (Winter 2023)[cite: 1].

## Team Members
* **Bryant Nguyen** – Team Captain, CAD, Fabrication[cite: 1]
* **Maddox Reyes** – CAD, Electronics[cite: 1]
* **Cole Tateyama** – Electronics, Coding[cite: 1]
* **Rafael Cortes** – Electronics, Coding[cite: 1]
* **Ben Vu** – CAD, Fabrication[cite: 1]

## Overview
ZotGPT is a single-layer, beetle-inspired autonomous rover engineered for speed, stability, and fast line navigation[cite: 1]. The system uses three line-tracking IR sensors to navigate a course and transitions to a Pixy2 camera vision system to center, approach, and retrieve a target colored can using a custom 3D-printed claw[cite: 1].

## Technical Specifications
| Parameter | Value / Specification |
| :--- | :--- |
| **Dimensions** | 15.25 in × 11.27 in[cite: 1] |
| **Chassis Material** | 1/4" Baltic Birch Plywood[cite: 1] |
| **Total Weight** | 1,068.9 g (Stall Limit: 1,650 g)[cite: 1] |
| **Center of Mass** | 5.01 in (width offset), 6.36 in (from back)[cite: 1] |
| **Total Cost** | $263.41 (Budget: <$300)[cite: 1] |
| **Drive Motors** | Dual Pololu 34:1 Gearmotors[cite: 1] |
| **Wheels** | 80mm × 10mm Drive Wheels + 3/4" Caster Wheel[cite: 1] |
| **Microcontroller** | Arduino Uno + Motor Driver Shield[cite: 1] |
| **Sensors & Vision** | Pixy2 Camera, 3× IR Line Sensors[cite: 1] |
| **Actuation** | SG90 Micro Servo (Gear-Driven Claw Mechanism)[cite: 1] |

## Key Features & Design Highlights
* **Optimized Speed & Torque:** Utilizes 34:1 gearmotors paired with 80mm wheels to maximize distance covered per motor rotation while staying below stall weight constraints[cite: 1].
* **Single-Layer Wooden Chassis:** Built with Baltic birch plywood for a lightweight frame and straightforward access to electronics[cite: 1].
* **Adjustable Sensor Placement:** Front-mounted IR sensors positioned close to the ground provide immediate surface readouts, preventing motor signal lag[cite: 1].
* **Elevated Camera Mount:** Custom 3D-printed bracket raises the Pixy2 camera for a high vantage point to detect colored targets reliably[cite: 1].
* **Regulated Power Delivery:** Features an inline buck converter to regulate voltage to the micro servo and eliminate power draw issues[cite: 1].

## System Architecture & Algorithm Design

### State Control Logic
1. **Line Following Mode:**
   * Continuously polls 3 front-mounted IR sensors[cite: 1].
   * If left IR sensor detects line: Steering corrects right[cite: 1].
   * If right IR sensor detects line: Steering corrects left[cite: 1].
   * If middle sensor detects line: Rover drives straight[cite: 1].
   * If all 3 sensors trigger HIGH: Controller switches state to PixyCam tracking[cite: 1].

2. **PixyCam Object Tracking & Grab Mode:**
   * Pixy2 camera processes the pre-programmed color signature of the target[cite: 1].
   * Adjusts left/right motor speeds until target is centered horizontally[cite: 1].
   * Drives forward until object area reaches a predefined threshold distance[cite: 1].
   * Activates SG90 servo to actuate gears and close claw onto the target[cite: 1].

## Bill of Materials (BOM)
| Component | Qty | Extended Price |
| :--- | :---: | :---: |
| Arduino Uno | 1 | $27.60[cite: 1] |
| Motor Driver Shield | 1 | $22.55[cite: 1] |
| Pixy Cam2 | 1 | $69.96[cite: 1] |
| Pololu 34:1 Gearmotors | 1 | $29.95[cite: 1] |
| 80mm x 10mm Wheels | 1 | $9.95[cite: 1] |
| 3D Printing Components | 1 | $32.00[cite: 1] |
| 1/4" Baltic Birch Plywood (16"x10") | 1 | $2.78[cite: 1] |
| Zeee Battery Pack | 1 | $17.50[cite: 1] |
| D-Planet Buck Converter | 1 | $3.75[cite: 1] |
| IR Line Sensors | 3 | $1.65[cite: 1] |
| SG90 Micro Servo | 1 | $1.75[cite: 1] |
| Miscellaneous (Wiring, Switch, Breadboard, Caster) | – | $26.97[cite: 1] |
| **Grand Total (with 7.75% Tax)** | – | **$263.41**[cite: 1] |
