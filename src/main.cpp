#include "StatusSystem.h"
#include "ConfigManager.h"
#include "SensorManager.h"
#include "Logger.h"

StatusSystem sistema;
ConfigManager config;
SensorManager sensor;
Logger logger;

void setup() {
  Serial.begin(115200);
  config.init();
  config.checkReset();
  config.loadOrDefault();

  sensor.init();
  logger.init();

  sistema.setStatus(BOOT);
}

void loop() {
  sistema.atualizarStatus();

  if (sistema.getStatus() == IDLE) {
    if (sensor.detectaQueda()) {
      sistema.setStatus(RUN);
      logger.registrar(sensor.getDados());
    }
  }

  delay(1000);
}
