# Detector de quedas

🚨 Detecção de Quedas com ESP32 usando MQTT, FreeRTOS, NVS e LittleFS  
Este projeto implementa um sistema embarcado inteligente para detecção de quedas utilizando o microcontrolador ESP32, com suporte a comunicação MQTT, persistência de dados e multitarefa via FreeRTOS.

🧠 Funcionalidades:  
  &nbsp;&nbsp;&nbsp;&nbsp;📡 MQTT (HiveMQ): envio de alertas em tempo real  
  &nbsp;&nbsp;&nbsp;&nbsp;🎯 MPU6050: sensor de aceleração para detectar quedas  
  &nbsp;&nbsp;&nbsp;&nbsp;⚙️ FreeRTOS: gerenciamento de tarefas paralelas  
  &nbsp;&nbsp;&nbsp;&nbsp;💾 NVS (Non-Volatile Storage): armazenamento persistente de configurações com controle de versão  
  &nbsp;&nbsp;&nbsp;&nbsp;🔁 Botão de Reset: restaura configurações de fábrica  
  &nbsp;&nbsp;&nbsp;&nbsp;📁 LittleFS: registro de eventos em arquivo CSV  
  &nbsp;&nbsp;&nbsp;&nbsp;⏱️ GPTimer: amostragem precisa dos dados do sensor  
  &nbsp;&nbsp;&nbsp;&nbsp;💡 LEDC (PWM): simulação de pulsos para feedback visual ou sonoro  

🧩 Arquitetura do Sistema  
  O projeto é modular e organizado em módulos:  
    StatusSystem: Gerencia os estados do sistema: BOOT → IDLE → RUN → ERROR  
    ConfigManager: Lê, salva e restaura configurações via NVS  
    SensorManager: Inicializa o MPU6050 e detecta quedas com base na aceleração  
    Logger: Registra os dados capturados em formato CSV usando LittleFS  

🧪 Testes de Bancada  
  Durante os testes, foram simuladas quedas para validar:  
    ⏱️ Tempo de resposta  
    ✅ Precisão na detecção  
    📊 Consumo de memória  
  Os resultados são armazenados em data/resultados.csv para análise posterior.  

🧰 Ambiente de Desenvolvimento  
  💻 PlatformIO: gerenciamento de build, upload e monitor serial  
  🧪 Wokwi: simulação online do ESP32 com sensores e periféricos  

🚀 Como começar  
  Clone o repositório  
  Abra com PlatformIO no VS Code  
  Compile e faça o upload para o ESP32  
  Monitore os dados via serial ou MQTT  
