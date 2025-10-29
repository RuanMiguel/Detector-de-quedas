#include "Logger.h"
#include "esp_log.h"
#include <stdio.h>

static const char* TAG = "Logger";

void Logger::init() {
  ESP_LOGI(TAG, "Logger iniciado");
}

void Logger::registrar(DadosSensor dados) {
  FILE* file = fopen("/spiflash/resultados.csv", "a");
  if (file) {
    fprintf(file, "%.2f,%.2f,%.2f\n", dados.x, dados.y, dados.z);
    fclose(file);
  } else {
    ESP_LOGE(TAG, "Erro ao abrir arquivo para escrita");
  }
}
