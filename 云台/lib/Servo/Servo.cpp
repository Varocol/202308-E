#include "Servo.h"
/**
 * @brief  角度转PWM脉宽
 * @param  angle    转向角
 * @retval PWM脉宽
 */
double Servo1_Angle2Pulse(double angle)
{
    return angle * 1.0 * (SERVO1_PULSE_MAX - SERVO1_PULSE_MIN) / (SERVO1_ANGLE_MAX - SERVO1_ANGLE_MIN) + SERVO1_PULSE_MIN;
}

/**
 * @brief  PWM脉宽转占空比
 * @param  pulse    PWM脉宽
 * @retval PWM占空比
 */
double Servo1_Pulse2Duty(double pulse)
{
    return pulse * 1.0 * (1 << SERVO1_RESOLUTION) * SERVO1_FREQUENCY / 1000000;
}

/**
 * @brief  舵机1初始化
 * @param  None
 * @retval None
 */
void Servo1_Init()
{
    if (ledcSetup(SERVO1_CHANNEL, SERVO1_FREQUENCY, SERVO1_RESOLUTION) == 0)
    {
        Serial.println("[Servo1] 舵机初始化失败.");
    }
    else
    {
        Serial.println("[Servo1] 舵机初始化成功.");
    }
    // 校正舵机
    Servo1_Turn(SERVO1_ANGLE_INITIALIZE);
}

/**
 * @brief  舵机1转向
 * @param  angle    转向角
 * @retval None
 */
void Servo1_Turn(double angle)
{
    angle = angle > SERVO1_ANGLE_TURN_MAX ? SERVO1_ANGLE_TURN_MAX : angle < SERVO1_ANGLE_TURN_MIN ? SERVO1_ANGLE_TURN_MIN
                                                                                   : angle;
    Servo1_Start();
    ledcWrite(SERVO1_CHANNEL, Servo1_Pulse2Duty(Servo1_Angle2Pulse(angle)));
    DBG("[Servo1] Servo turn %lf°.\n", angle);
}

/**
 * @brief  舵机1开启
 * @param  None
 * @retval None
 */
void Servo1_Start()
{
    ledcAttachPin(SERVO1_PIN, SERVO1_CHANNEL);
}

/**
 * @brief  舵机1停止
 * @param  None
 * @retval None
 */
void Servo1_Stop()
{
    ledcWrite(SERVO1_CHANNEL, 0);
    ledcDetachPin(SERVO1_PIN);
    DBG("[Servo1] Servo Stoped.\n");
}

/**
 * @brief  角度转PWM脉宽
 * @param  angle    转向角
 * @retval PWM脉宽
 */
double Servo2_Angle2Pulse(double angle)
{
    return angle * 1.0 * (SERVO2_PULSE_MAX - SERVO2_PULSE_MIN) / (SERVO2_ANGLE_MAX - SERVO2_ANGLE_MIN) + SERVO2_PULSE_MIN;
}

/**
 * @brief  PWM脉宽转占空比
 * @param  pulse    PWM脉宽
 * @retval PWM占空比
 */
double Servo2_Pulse2Duty(double pulse)
{
    return pulse * 1.0 * (1 << SERVO2_RESOLUTION) * SERVO2_FREQUENCY / 1000000;
}

/**
 * @brief  舵机2初始化
 * @param  None
 * @retval None
 */
void Servo2_Init()
{
    if (ledcSetup(SERVO2_CHANNEL, SERVO2_FREQUENCY, SERVO2_RESOLUTION) == 0)
    {
        Serial.println("[Servo2] 舵机初始化失败.");
    }
    else
    {
        Serial.println("[Servo2] 舵机初始化成功.");
    }
    // 校正舵机
    Servo2_Turn(SERVO2_ANGLE_INITIALIZE);
}

/**
 * @brief  舵机1转向
 * @param  angle    转向角
 * @retval None
 */
void Servo2_Turn(double angle)
{
    angle = angle > SERVO2_ANGLE_TURN_MAX ? SERVO2_ANGLE_TURN_MAX : angle < SERVO2_ANGLE_TURN_MIN ? SERVO2_ANGLE_TURN_MIN
                                                                                   : angle;
    Servo2_Start();
    ledcWrite(SERVO2_CHANNEL, Servo2_Pulse2Duty(Servo2_Angle2Pulse(angle)));
    DBG("[Servo2] Servo turn %lf°.\n", angle);
}

/**
 * @brief  舵机1开启
 * @param  None
 * @retval None
 */
void Servo2_Start()
{
    ledcAttachPin(SERVO2_PIN, SERVO2_CHANNEL);
}

/**
 * @brief  舵机1停止
 * @param  None
 * @retval None
 */
void Servo2_Stop()
{
    ledcWrite(SERVO2_CHANNEL, 0);
    ledcDetachPin(SERVO2_PIN);
    DBG("[Servo2] Servo Stoped.");
}