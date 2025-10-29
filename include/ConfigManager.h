#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

class ConfigManager {
  public:
    void init();
    void checkReset();
    bool loadOrDefault();
    void save(int valor, int versao);
    int getValor();
  private:
    int valorConfig;
    int versaoConfig = 1;
};

#endif
