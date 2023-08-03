#include "Hardware.h"

void setup()
{
    Hardware_Init();
}

void loop()
{
    // 测试舵机1
    // 居中
    delay(1000);
    // 最小
    Servo2_Turn(SERVO2_ANGLE_TURN_MIN);
    delay(1000);
    // 最大
    Servo2_Turn(SERVO2_ANGLE_TURN_MAX);
    delay(1000);
    while (1)
        ;
}
