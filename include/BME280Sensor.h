#ifndef BME280SENSOR_H
#define BME280SENSOR_H

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Sensor {
public:
  BME280Sensor();
  void begin();
  float readTemperature();
  float readHumidity();
  float readPressure();

private:
  Adafruit_BME280 bme;
};

#endif // BME280SENSOR_H
