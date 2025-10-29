#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

struct DadosSensor {
  float x;
  float y;
  float z;
};

class SensorManager {
  public:
    void init();
    bool detectaQueda();
    DadosSensor getDados();
  private:
    DadosSensor dados;
};

#endif
