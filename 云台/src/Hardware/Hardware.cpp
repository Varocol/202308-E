#include "Hardware.h"

/**
 * @brief  硬件初始化
 * @param  None
 * @retval None
 */
void Hardware_Init()
{
    DBG_Serial_Init();
    TRANS_Serial_Init();
    Servo1_Init();
    Servo2_Init();
}