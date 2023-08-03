#pragma once
#include "header.h"
#include "Variables.h"

// 用于控制任务的进行和结束
typedef enum
{
    task_running,
    task_stop
} Task_Status;

typedef struct
{
    TaskFunction_t task;
    const char *name;
    volatile Task_Status status;
    int Priority;
} Task_Control_Block;

void Servo_Task(void *);
void Transmit_Task(void *);

void Task_Init();