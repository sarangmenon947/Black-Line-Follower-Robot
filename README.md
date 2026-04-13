# Black Line Follower Robot

An Arduino-based autonomous robot that follows a **black line on a white surface** using two IR sensors. The robot continuously reads sensor input and adjusts its motors in real time to stay on track.

---

## How It Works

The robot uses two IR sensors mounted on the underside of the chassis, pointing at the ground. A black surface **absorbs** IR light (sensor reads `LOW`) while a white surface **reflects** it (sensor reads `HIGH`). By comparing both sensor readings, the robot decides whether to go forward, turn left, turn right, or stop.

---

## Pin Configuration

| Pin | Constant  | Role                        |
|-----|-----------|-----------------------------|
| 2   | `LS`      | Left IR sensor (INPUT)      |
| 3   | `RS`      | Right IR sensor (INPUT)     |
| 9   | `LM1`     | Left motor — forward        |
| 8   | `LM2`     | Left motor — reverse        |
| 5   | `RM1`     | Right motor — forward       |
| 4   | `RM2`     | Right motor — reverse       |
| 7   | `IR_LED`  | IR LED power (always HIGH)  |
| 13  | `LEDPIN`  | Onboard status LED          |

---

## Movement Logic

| Left Sensor | Right Sensor | Condition               | Action           |
|-------------|--------------|-------------------------|------------------|
| HIGH        | HIGH         | Both on white           | Move Forward   |
| HIGH        | LOW          | Right drifted off line  | Turn Right     |
| LOW         | HIGH         | Left drifted off line   | Turn Left      |
| LOW         | LOW          | Both on black / lost    | Stop           |

> The sensors return `HIGH` on a **white** surface and `LOW` on a **black** surface.

---

## Components Required

| Component                  | Quantity |
|----------------------------|----------|
| Arduino Uno (or compatible)| 1        |
| IR Sensor Module           | 2        |
| DC Gear Motor              | 2        |
| Motor Driver (L298N/L293D) | 1        |
| Robot Chassis              | 1        |
| Wheels                     | 2        |
| Caster Wheel               | 1        |
| Li-ion / 9V Battery        | 1        |
| Jumper Wires               | As needed|

---

## Circuit Overview

```
  Arduino
  ┌─────────────────┐
  │ D2  ──── Left IR Sensor (OUT)
  │ D3  ──── Right IR Sensor (OUT)
  │ D7  ──── IR LED (VCC)
  │ D9  ──── Motor Driver IN1 (Left Motor)
  │ D8  ──── Motor Driver IN2 (Left Motor)
  │ D5  ──── Motor Driver IN3 (Right Motor)
  │ D4  ──── Motor Driver IN4 (Right Motor)
  │ D13 ──── Status LED
  │ 5V  ──── IR Sensor VCC
  │ GND ──── Common Ground
  └─────────────────┘
```

---

## Project Structure

```
line-following-robot/
├── black_line_follower.ino
└── README.md
```

---

## How to Upload

1. Open `line_follower.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
2. Select your board: **Tools → Board → Arduino Uno**.
3. Select the correct port: **Tools → Port → COMx** (Windows) or `/dev/ttyUSBx` (Linux/macOS).
4. Click **Upload** (→).
5. Place the robot on a track with a black line on a white surface and power it on.

---

## Setup Tips

- **Sensor height:** Mount IR sensors **5–10 mm** above the surface for reliable detection.
- **Sensor spacing:** Space the two sensors slightly wider than the line width so one sits on each side of the line.
- **Track:** Use **black electrical tape** on a white sheet/floor, or print a track on paper.
- **Power:** Power the Arduino and motor driver separately if motors cause voltage drops.
- **Calibration:** If the robot behaves erratically, adjust sensor sensitivity using the onboard potentiometer on the IR module.
