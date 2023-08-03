#include "Hardware.h"
#include "Tasks.h"

void setup()
{
    Hardware_Init();
    // Task_Init();
}

void loop()
{
    String data;
    double servo1_angle_receive, servo2_angle_receive;
    uint32_t delay_t;
    while (Serial1.available())
    {
        data += char(Serial1.read());
    }
    // 处理数据
    if (data.length())
    {
        servo1_angle_receive = data.substring(0, data.indexOf("|")).toDouble();
        servo2_angle_receive = data.substring(data.indexOf("|") + 1).toDouble();
        DBG("angle:%lf|%lf\n", servo1_angle_receive, servo2_angle_receive);
        servo1_old_angle = servo1_new_angle;
        servo1_new_angle = (servo1_angle_receive - 0) * 1.0 / (270 - 0) * (SERVO1_ANGLE_TURN_MAX - SERVO1_ANGLE_TURN_MIN) + SERVO1_ANGLE_TURN_MIN;
        servo2_old_angle = servo2_new_angle;
        servo2_new_angle = (servo2_angle_receive - 0) * 1.0 / (270 - 0) * (SERVO2_ANGLE_TURN_MAX - SERVO2_ANGLE_TURN_MIN) + SERVO2_ANGLE_TURN_MIN;
        DBG("new_angle:%lf|%lf\n", servo1_new_angle, servo2_new_angle);
        data = "";
    }
    if (servo1_new_angle != servo1_old_angle)
    {
        Servo1_Turn(servo1_new_angle);
        if (servo1_new_angle < SERVO1_ANGLE_INITIALIZE)
        {
            delay_t = (servo1_new_angle - SERVO1_ANGLE_TURN_MIN) * 1000 / SERVO1_ANGLE_SPEED;
        }
        else
        {
            delay_t = (SERVO1_ANGLE_TURN_MAX - servo1_new_angle) * 1000 / SERVO1_ANGLE_SPEED;
        }
        delay(delay_t);
    }
    if (servo2_new_angle != servo2_old_angle)
    {
        Servo2_Turn(servo2_new_angle);
        if (servo2_new_angle < SERVO2_ANGLE_INITIALIZE)
        {
            delay_t = (servo2_new_angle - SERVO2_ANGLE_TURN_MIN) * 1000 / SERVO2_ANGLE_SPEED;
        }
        else
        {
            delay_t = (SERVO2_ANGLE_TURN_MAX - servo2_new_angle) * 1000 / SERVO2_ANGLE_SPEED;
        }
        delay(delay_t);
    }
}
