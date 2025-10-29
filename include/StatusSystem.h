#ifndef STATUS_SYSTEM_H
#define STATUS_SYSTEM_H

enum Status {
  BOOT,
  IDLE,
  RUN,
  ERROR
};

class StatusSystem {
  private:
    Status statusAtual;

  public:
    StatusSystem();
    void atualizarStatus();
    void setStatus(Status novo);
    Status getStatus();
};

#endif
