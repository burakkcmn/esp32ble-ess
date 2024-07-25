#include "BLEServer.h"
#include <Arduino.h>

// Temperature Characteristic and Descriptor (default UUID)
BLECharacteristic temperatureCharacteristic(BLEUUID((uint16_t)0x2A6E), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor temperatureDescriptor(BLEUUID((uint16_t)0x2902));

// Humidity Characteristic and Descriptor (default UUID)
BLECharacteristic humidityCharacteristic(BLEUUID((uint16_t)0x2A6F), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor humidityDescriptor(BLEUUID((uint16_t)0x2902));

// Pressure Characteristic and Descriptor (default UUID)
BLECharacteristic pressureCharacteristic(BLEUUID((uint16_t)0x2A6D), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor pressureDescriptor(BLEUUID((uint16_t)0x2902));

bool deviceConnected = false;

// Setup callbacks onConnect and onDisconnect
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Device Connected");
  };
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Device Disconnected");
  }
};

void initBLE() {
  // Create the BLE Device
  BLEDevice::init(BLE_SERVER_NAME);

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *bmeService = pServer->createService(SERVICE_UUID);

  // Create BLE Characteristics and corresponding Descriptors
  bmeService->addCharacteristic(&temperatureCharacteristic);
  temperatureCharacteristic.addDescriptor(&temperatureDescriptor);
  
  bmeService->addCharacteristic(&humidityCharacteristic);
  humidityCharacteristic.addDescriptor(&humidityDescriptor);

  bmeService->addCharacteristic(&pressureCharacteristic);
  pressureCharacteristic.addDescriptor(&pressureDescriptor);
  
  // Start the service
  bmeService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}

void notifyClients(float temperature, float humidity, float pressure) {
  if (deviceConnected) {
    // Notify temperature reading
    uint16_t tempValue = (uint16_t)temperature;
    temperatureCharacteristic.setValue(tempValue);
    temperatureCharacteristic.notify();
    Serial.print("Temperature Celsius: ");
    Serial.print(temperature);
    Serial.println(" ºC");
   
    // Notify humidity reading
    uint16_t humidityValue = (uint16_t)humidity;
    humidityCharacteristic.setValue(humidityValue);
    humidityCharacteristic.notify();   
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Notify pressure reading
    uint16_t pressureValue = (uint16_t)pressure;
    pressureCharacteristic.setValue(pressureValue);
    pressureCharacteristic.notify();   
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");
  }
}
