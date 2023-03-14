#ifndef _URTK_SCHEDULER
#define _URTK_SCHEDULER

#include "urtk_settings.h"
#include "task.h"

task_st task_table[URTK_MAX_TASKS];
uint8_t task_table_size = 0;

static uint8_t scheduler_task_table[URTK_MAX_TASKS];

void init_scheduler();
void scheduler();
void schedule_task(uint8_t priority);
void unschedule_task(uint8_t priority);
void reschedule_task(uint8_t current_priority, uint8_t new_priority);

#endif