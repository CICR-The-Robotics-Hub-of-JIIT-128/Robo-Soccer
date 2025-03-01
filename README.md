# Robo-Soccer Arduino Controller

## Overview
This repository contains the Arduino code for controlling a Robo-Soccer robot. The code reads signals from two channels (e.g., from a remote controller or sensors) and controls the movement of the robot's motors. The robot can move forward, backward, left, and right based on the input signals.

---

## Features
- **Channel Signal Reading:** Reads PWM signals from two input channels.
- **Motor Control:** Controls four motors to move the robot in different directions.
- **Simple Logic:** Implements basic movement logic (forward, backward, left, right, and stop).

---

## Hardware Requirements
- **Microcontroller:** Arduino (e.g., Arduino Nano).
- **Motors:** 4 DC motors for movement.
- **Motor Driver:** L298N or similar motor driver module.
- **Input Signals:** PWM signals from a remote controller or sensors (connected to pins 2 and 3).
- **Power Supply:** Battery or external power source for the motors and Arduino.

---

## Wiring Diagram
1. Connect the PWM signal wires to:
   - Channel 1: Pin 2
   - Channel 2: Pin 3
2. Connect the motor control pins:
   - Motor 1: Pins 4 (IN1) and 5 (IN2)
   - Motor 2: Pins 6 (IN3) and 7 (IN4)
3. Connect the motor driver to the motors and power supply.

---

## Code Explanation
The `.ino` file contains the following logic:

### Variables
- `ch1` and `ch2`: Store the PWM signal values from the input channels.
- `a`, `b`, `c`, `d`: Pins connected to the motor driver.

### `setup()`
- Initializes serial communication.
- Sets pins 2 and 3 as inputs for reading PWM signals.
- Sets pins 4, 5, 6, and 7 as outputs for controlling the motors.

### `loop()`
1. Reads the PWM signals from pins 2 and 3 using `pulseIn()`.
2. Implements movement logic based on the signal values:
   - **Stop:** If both channels are in the neutral range (1400–1500) or if no signal is detected.
   - **Left:** If `ch2` is greater than 1750.
   - **Right:** If `ch2` is less than 1250.
   - **Backward:** If `ch1` is greater than 1750.
   - **Forward:** If `ch1` is less than 1250.
3. Controls the motors by setting the appropriate pins HIGH or LOW.

---

## How to Use
1. Upload the `.ino` file to your Arduino.
2. Connect the hardware as described in the wiring diagram.
3. Power on the Arduino and the motor driver.
4. Send PWM signals to pins 2 and 3 to control the robot's movement.

---

## Example Behavior
| `ch1` Value | `ch2` Value | Robot Action |
|-------------|-------------|--------------|
| 1400–1500   | 1400–1500   | Stop         |
| 0           | 0           | Stop         |
| < 1250      | Any         | Forward      |
| > 1750      | Any         | Backward     |
| Any         | < 1250      | Right        |
| Any         | > 1750      | Left         |

---

## Troubleshooting
- **No Movement:** Check the wiring and ensure the motor driver is powered.
- **Incorrect Movement:** Verify the PWM signal values and adjust the thresholds in the code if necessary.
- **Serial Debugging:** Use `Serial.println()` to print `ch1` and `ch2` values for debugging.

---

## Contributing
Contributions are welcome! If you have suggestions or improvements, feel free to open an issue or submit a pull request.

---

## Contact
For questions or feedback, please contact:
- **Email:** contact@cicr.in


---

Enjoy building and controlling your Robo-Soccer robot! 🤖⚽
