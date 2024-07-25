#include "BME280Sensor.h"

BME280Sensor::BME280Sensor() {}

void BME280Sensor::begin() {
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

float BME280Sensor::readTemperature() {
  return bme.readTemperature();
}

float BME280Sensor::readHumidity() {
  return bme.readHumidity();
}

float BME280Sensor::readPressure() {
  return bme.readPressure() / 100.0F;
}
