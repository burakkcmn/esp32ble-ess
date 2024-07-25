#ifndef BLESERVER_H
#define BLESERVER_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// BLE server name
#define BLE_SERVER_NAME "ESP32_BME280"

// Default UUID for Environmental Sensing Service
#define SERVICE_UUID (BLEUUID((uint16_t)0x181A))

extern bool deviceConnected;

void initBLE();
void notifyClients(float temperature, float humidity, float pressure);

#endif // BLESERVER_H
