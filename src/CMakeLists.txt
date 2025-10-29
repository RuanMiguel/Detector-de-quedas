 idf_component_register(SRCS "main.cpp"
                        "SensorManager.cpp"
                        "Logger.cpp"
                        "StatusSystem.cpp"
                        "ConfigManager.cpp"
                        INCLUDE_DIRS "."
                        REQUIRES esp_log)