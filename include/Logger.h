#ifndef LOGGER_H
#define LOGGER_H

#include "SensorManager.h"

class Logger {
  public:
    void init();
    void registrar(DadosSensor dados);
};

#endif
