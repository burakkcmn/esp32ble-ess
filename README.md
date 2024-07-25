# ESP32 BME280 BLE Server

This project demonstrates how to use an ESP32 to read data from a BME280 sensor (temperature, humidity, and pressure) and transmit it via BLE (Bluetooth Low Energy) to connected clients. The project uses the Arduino framework.

## Table of Contents
- [Introduction](#introduction)
- [Hardware Required](#hardware-required)
- [Software Required](#software-required)
- [Installation](#installation)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [License](#license)

## Introduction

This project is designed to:
- Initialize and read data from a BME280 sensor.
- Set up a BLE server on the ESP32.
- Notify connected BLE clients with the sensor data.

## Hardware Required

- ESP32 development board
- BME280 sensor module
- Breadboard and connecting wires

## Software Required

- VS Code with Platformio
- [Adafruit BME280 Library](https://github.com/adafruit/Adafruit_BME280_Library)
- [Adafruit Unified Sensor Driver](https://github.com/adafruit/Adafruit_Sensor)
- [ArduinoBLE Library](https://github.com/espressif/arduino-esp32/tree/master/libraries/BLE)

## Installation

1. **Install PlatformIO:**
   - Follow the instructions [here](https://platformio.org/install) to install PlatformIO IDE.

2. **Clone the project repository:**
   ```bash
   git clone https://github.com/burakkcmn/esp32ble-ess.git

3. **Open the project in PlatformIO:**

    - Open PlatformIO IDE.
    - Click on Open Project and select the ESP32_BME280_BLE directory.

4. **Connect your ESP32 to the computer and upload the code:**

    - Select your ESP32 board and the correct COM port.
    - Click on the Upload button (arrow icon) to upload the code to your ESP32.

After completing these steps, your ESP32 should start running the code and you can connect to it using a BLE client application to receive sensor data.

## Usage
1. **Power up the ESP32:**

    - Connect the BME280 sensor to the ESP32 as follows:
        - VCC to 3.3V
        - GND to GND
        - SCL to GPIO 22 (or your preferred I2C SCL pin)
        - SDA to GPIO 21 (or your preferred I2C SDA pin)
2. **Open a BLE client application on your smartphone:**

    - Use an app like nRF Connect to scan for BLE devices.
    - Connect to the device named ESP32_BME280.

3. **Receive notifications:**

    - Once connected, you should start receiving notifications for temperature, humidity, and pressure readings every 10 seconds.

## Code Structure
- ESP32_BME280_BLE.ino: Main file containing the setup and loop functions.
- BME280Sensor.h and BME280Sensor.cpp: Wrapper for initializing and reading data from the BME280 sensor.
- BLEServer.h and BLEServer.cpp: Handles BLE server initialization, characteristic creation, and notifications.

## BME280Sensor
- begin(): Initializes the BME280 sensor.
- readTemperature(): Returns the current temperature.
- readHumidity(): Returns the current humidity.
- readPressure(): Returns the current pressure.

## BLEServer
- initBLE(): Initializes the BLE server and starts advertising.
- notifyClients(): Notifies connected BLE clients with the sensor data.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

This README provides a comprehensive overview of your project, including setup instructions, usage details, and code structure. Adjust the content as needed to better fit your specific project requirements.

## Acknowledgments

- This project is based on tutorials by [Random Nerd Tutorials](https://RandomNerdTutorials.com/)
