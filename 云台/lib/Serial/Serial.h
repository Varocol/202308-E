#pragma once
#include <Arduino.h>

#define DBG_SERIAL_BAUDRATE 115200
#define TRANS_SERIAL_BAUDRATE 115200

#ifdef DEBUG_MODE
#define DBG(...) Serial.printf(__VA_ARGS__)
#else
#define DBG(...)
#endif

void DBG_Serial_Init();
void TRANS_Serial_Init();
