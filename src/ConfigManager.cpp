#include "ConfigManager.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <nvs_flash.h>
#include <nvs.h>

#define RESET_PIN GPIO_NUM_0
static const char* TAG = "ConfigManager";

void ConfigManager::init() {
  esp_err_t err = nvs_flash_init();
  if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    nvs_flash_erase();
    nvs_flash_init();
  }
}

void ConfigManager::checkReset() {
  gpio_set_direction(RESET_PIN, GPIO_MODE_INPUT);
  gpio_set_pull_mode(RESET_PIN, GPIO_PULLUP_ONLY);

  if (gpio_get_level(RESET_PIN) == 0) {
    ESP_LOGW(TAG, "Factory reset acionado!");
    nvs_flash_erase();
    esp_restart();
  }
}

bool ConfigManager::loadOrDefault() {
  nvs_handle_t handle;
  esp_err_t err = nvs_open("config", NVS_READONLY, &handle);
  int versaoSalva = 0;

  if (err != ESP_OK || nvs_get_i32(handle, "versao", &versaoSalva) != ESP_OK || versaoSalva != versaoConfig) {
    nvs_close(handle);
    valorConfig = 42;
    save(valorConfig, versaoConfig);
    return false;
  }

  nvs_get_i32(handle, "valor", &valorConfig);
  nvs_close(handle);
  return true;
}

void ConfigManager::save(int valor, int versao) {
  nvs_handle_t handle;
  nvs_open("config", NVS_READWRITE, &handle);
  nvs_set_i32(handle, "valor", valor);
  nvs_set_i32(handle, "versao", versao);
  nvs_commit(handle);
  nvs_close(handle);
}

int ConfigManager::getValor() {
  return valorConfig;
}
