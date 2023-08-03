#include "Tasks.h"

// 任务列表
vector<Task_Control_Block> Task_List{
    {Servo_Task, "Servo_Task", task_running, 1},
    {Transmit_Task, "Transmit_Task", task_running, 1},
};

/**
 * @brief  任务初始化
 * @param  None
 * @retval None
 */
void Task_Init()
{
    // 初始化任务列表中的任务
    for (int i = 0; i < Task_List.size(); i++)
    {
        xTaskCreate(Task_List.at(i).task, Task_List.at(i).name, 4096, (void *)&Task_List.at(i), Task_List.at(i).Priority, NULL);
    }
}

/**
 * @brief  舵机1、2控制任务
 * @param  param    参数
 * @retval None
 */
void Servo_Task(void *param)
{
    Task_Control_Block *TCB = (Task_Control_Block *)param;
    uint32_t delay_t;
    while (TCB->status == task_running)
    {
        if (servo1_new_angle == servo1_old_angle)
        {
            Servo1_Stop();
        }
        else
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
        if (servo2_new_angle == servo2_old_angle)
        {
            Servo2_Stop();
        }
        else
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
    vTaskDelete(NULL);
}

/**
 * @brief  数据接收和角度转换任务
 * @param  param    参数
 * @retval None
 */
void Transmit_Task(void *param)
{
    Task_Control_Block *TCB = (Task_Control_Block *)param;
    String data;
    double servo1_angle_receive, servo2_angle_receive;
    while (TCB->status == task_running)
    {
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
    }
}