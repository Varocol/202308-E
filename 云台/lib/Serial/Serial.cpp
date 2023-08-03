#include "Serial.h"

/**
 * @brief  调试串口初始化
 * @param  None
 * @retval None
 */
void DBG_Serial_Init()
{
    Serial.begin(DBG_SERIAL_BAUDRATE);
    Serial.println("[DBG_Serial] 调试串口初始化成功.");
}

/**
 * @brief  数据传输串口初始化
 * @param  None
 * @retval None
 */
void TRANS_Serial_Init()
{
    Serial1.begin(TRANS_SERIAL_BAUDRATE);
    Serial.println("[TRANS_Serial] 数据传输串口初始化成功.");
}