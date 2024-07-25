#include <Arduino.h>
#include "BLEServer.h"
#include "BME280Sensor.h"

BME280Sensor bme280;

void setup()
{
  // Start serial communication
  Serial.begin(115200);

  // Start BME sensor
  // bme280.begin();

  // Initialize BLE
  initBLE();
}

void loop()
{
  if (deviceConnected)
  {
    float temperature = bme280.readTemperature();
    float humidity = bme280.readHumidity();
    float pressure = bme280.readPressure();

    notifyClients(temperature, humidity, pressure);

    delay(10000);
  }
}
