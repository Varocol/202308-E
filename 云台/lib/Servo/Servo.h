#pragma once
#include <Arduino.h>
#include "Serial.h"

#define SERVO1_FREQUENCY 50                                                           // Hz(默认值)
#define SERVO1_PIN 2                                                                  // 引脚
#define SERVO1_CHANNEL 0                                                              // 通道
#define SERVO1_RESOLUTION 14                                                          // 占空比位数(14为最大)
#define SERVO1_PULSE_MIN 500                                                          // us
#define SERVO1_PULSE_MAX 2500                                                         // us
#define SERVO1_ANGLE_MIN 0                                                            // 度
#define SERVO1_ANGLE_MAX 270                                                          // 度
#define SERVO1_ANGLE_TURN_MIN 40                                                      // 度
#define SERVO1_ANGLE_TURN_MAX 220                                                     // 度
#define SERVO1_ANGLE_INITIALIZE ((SERVO1_ANGLE_TURN_MAX + SERVO1_ANGLE_TURN_MIN) / 2) // 舵机复位角度
#define SERVO1_ANGLE_SPEED (60 / 0.14)                                                // 舵机转速

#define SERVO2_FREQUENCY 50                                                           // Hz(默认值)
#define SERVO2_PIN 3                                                                  // 引脚
#define SERVO2_CHANNEL 2                                                              // 通道
#define SERVO2_RESOLUTION 14                                                          // 占空比位数(14为最大)
#define SERVO2_PULSE_MIN 500                                                          // us
#define SERVO2_PULSE_MAX 2500                                                         // us
#define SERVO2_ANGLE_MIN 0                                                            // 度
#define SERVO2_ANGLE_MAX 270                                                          // 度
#define SERVO2_ANGLE_TURN_MIN 64                                                      // 度
#define SERVO2_ANGLE_TURN_MAX 228                                                     // 度
#define SERVO2_ANGLE_INITIALIZE ((SERVO2_ANGLE_TURN_MAX + SERVO2_ANGLE_TURN_MIN) / 2) // 舵机复位角度
#define SERVO2_ANGLE_SPEED (60 / 0.14)                                                // 舵机转速

/*
    软件PWM在100Hz以内较为稳定
    舵机脉宽:0.5 ~ 2.5ms
    舵机角度:0 ~ 180度
*/

void Servo1_Init();
void Servo1_Turn(double angle);
void Servo1_Start();
void Servo1_Stop();

void Servo2_Init();
void Servo2_Turn(double angle);
void Servo2_Start();
void Servo2_Stop();
