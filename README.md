# Arduino Line Following Bot

Author: Uday Sankar Mukherjee

![Line Following Bot](https://i.imgur.com/bXWijzU.png)

## Description
This Arduino project implements a line-following robot using infrared sensors. The robot is programmed to follow a line on the ground by detecting it with three infrared sensors placed underneath. Based on the readings from these sensors, the robot adjusts its movement to stay on the line.

## Components
- Arduino Nano
- Infrared sensors (3)
- Motor driver module
- DC motors (2)
- Chassis and wheels
- Power source (battery or USB)

## Installation
1. Connect the infrared sensors and motors to the Arduino Nano according to the specified pin configurations.
2. Upload the provided Arduino sketch (`line_following_bot.ino`) to the Arduino Nano using the Arduino IDE or any compatible software.
3. Make sure all connections are secure and the power source is connected.
4. Place the robot on a surface with a contrasting line to follow.

## Usage
1. Power on the robot and place it on the line.
2. The robot should start moving forward and adjust its direction to stay on the line.
3. Monitor the behavior of the robot and adjust parameters such as speed and sensor thresholds if necessary.
4. To stop the robot, turn off the power source or modify the code to include additional control features.

## Video Demo
Watch the line following bot in action on [YouTube](https://youtu.be/FbBQNVRTlso).

## Contributing
Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
