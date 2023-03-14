#include "scheduler.h"

void init_scheduler(){
    scheduler_task_table[0] = 0;/*REDUNDANT*/
}

void scheduler(){}

/**
 * I am not going to write a sorting algo
 * for the schedule_task, it assumes that
 * all this are kept in order from init
 * I would like to make this a O(1)
 * */
void schedule_task(uint8_t priority){
    uint8_t i = 0;
    
    /**
     * Since i is unsigned it is always > 0
     * and 0 is always the scheduler so no need
     * to re-position the scheduler
    */
    for(i = task_table_size; i > 0; i--){
        if(priority < scheduler_task_table[i]){
            scheduler_task_table[i+1] = scheduler_task_table[i];
        }
    }
    scheduler_task_table[i] = priority;
    task_table_size = task_table_size + 1;
}

void unschedule_task(uint8_t priority){}
void reschedule_task(uint8_t current_priority, uint8_t new_priority){}
