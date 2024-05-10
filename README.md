# Prosthetic Arm

This project aims to create a prosthetic arm using robotic components to assist people with disabilities. The arm is designed to be affordable and reliable, making it accessible to a larger population. The project is divided into two phases.

## Phase 1

### Components Used
- Flex sensors for detecting finger movement
- Resistors for signal conditioning
- ESP32 for transmitting sensor data
- ESP8266 for receiving data
- Servo motors for controlling finger movement
- 3D printed arm for the structural framework

### Project Details
The flex sensors are attached to the fingers of the prosthetic arm. These sensors change resistance based on the degree of finger bending, which is then converted into digital signals using resistors. The ESP32 collects this sensor data and transmits it wirelessly to the ESP8266 on the prosthetic arm.

The ESP8266 receives the sensor data and controls the servo motors accordingly, mimicking the natural movement of fingers. The 3D printed arm provides a lightweight and customizable structure for the prosthetic.

## Phase 2

### Additional Components Used
- Muscle sensors such as EMG sensors
- Enhanced signal processing algorithms

### Improved Design
In the second phase, muscle sensors like EMG sensors are incorporated into the prosthetic arm. These sensors detect muscle contractions in the residual limb, providing a more intuitive control mechanism for the user. 

The project also focuses on enhancing signal processing algorithms to improve the accuracy and responsiveness of the prosthetic arm. This phase aims to make the prosthetic more reliable and user-friendly, ultimately improving the quality of life for people with disabilities.
