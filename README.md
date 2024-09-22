# Line-Following-Robot-with-Sensor-Based-Navigation
Overview:


This project implements a basic robot that autonomously navigates using sensor data. The robot follows a line by analyzing inputs from three sensors (left, middle, right), which help it determine whether to move forward, turn left, or turn right. It also includes simple logic for handling specific situations (like repeated loops or missing lines).

Key Features:
Motor Control: The robot has basic movement functions (forward, left, right, backward, stop).

Line Following: Based on sensor input, the robot follows a line.

Speed Control: Motor speed is controlled via PWM (Pulse Width Modulation) for smooth movement.

Modular Functions: Code includes modular functions to handle different movements.

Hardware Requirements
3 line detection sensors (e.g., infrared sensors for detecting black/white contrast)
2 DC motors
Motor driver (with PWM support)
Arduino or compatible microcontroller
Ultrasonic sensor (optional for obstacle detection)

Sensors:
Left Sensor (LSP) on digital pin A5
Middle Sensor (MSP) on digital pin A4
Right Sensor (RSP) on digital pin A3

Motors:
Left Motor connected to digital pins 7 and 6
Right Motor connected to digital pins 5 and 4
Speed control via pins ENA (pin 3) and ENB (pin 11)
Circuit Diagram
Include a circuit diagram here if possible (image or drawing) to show how the sensors, motors, and motor drivers are connected to the microcontroller.
