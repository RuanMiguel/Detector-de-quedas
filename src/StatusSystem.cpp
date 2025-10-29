#include "StatusSystem.h"
#include "esp_log.h"

static const char* TAG = "StatusSystem";

StatusSystem::StatusSystem() {
  statusAtual = BOOT;
}

void StatusSystem::atualizarStatus() {
  switch (statusAtual) {
    case BOOT:
      ESP_LOGI(TAG, "Inicializando sistema...");
      statusAtual = IDLE;
      break;
    case IDLE:
      ESP_LOGI(TAG, "Sistema em espera...");
      break;
    case RUN:
      ESP_LOGI(TAG, "Executando ação...");
      statusAtual = IDLE;
      break;
    case ERROR:
      ESP_LOGE(TAG, "Erro detectado!");
      statusAtual = BOOT;
      break;
  }
}

void StatusSystem::setStatus(Status novo) {
  statusAtual = novo;
}

Status StatusSystem::getStatus() {
  return statusAtual;
}
