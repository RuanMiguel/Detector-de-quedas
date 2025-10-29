#include "SensorManager.h"
#include "esp_log.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

static const char* TAG = "SensorManager";

Adafruit_MPU6050 mpu;

void SensorManager::init() {
  if (!mpu.begin()) {
    ESP_LOGE(TAG, "Erro ao iniciar MPU6050");
  } else {
    ESP_LOGI(TAG, "MPU6050 iniciado com sucesso");
  }
}

bool SensorManager::detectaQueda() {
  sensors_event_t event;
  mpu.getAccelerometerSensor()->getEvent(&event);

  dados.x = fabs(event.acceleration.x);
  dados.y = fabs(event.acceleration.y);
  dados.z = fabs(event.acceleration.z);

  return (dados.x > 8.5 || dados.y > 8.5 || dados.z > 8.5);
}

DadosSensor SensorManager::getDados() {
  return dados;
}
