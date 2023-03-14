#include "task.h"


uint8_t create_task(uint8_t (*task)(void *arg), uint8_t priority, uint32_t mem_size, void *arg,\
                    uint8_t rerun, uint8_t (*task_success)(void *arg), uint8_t (*task_fail)(void *arg)){

    extern uint8_t task_table_size;
    extern task_st task_table[URTK_MAX_TASKS];

    if(priority < 1 || priority > 255 || task_table_size >= 256 || task_table[priority].tid){
        return 1;
    }else{/*DO NOTHING*/}

    if(rerun && (task_success || task_fail)){
        task_success = NULL;
        task_fail = NULL;
    }else{/*DO NOTHING*/}

    task_table[priority].tid = priority;
    task_table[priority].state = STARTED;
    /*Kinda like -1 means it hasnt exited yet*/
    task_table[priority].exit_status = 255;
    task_table[priority].task = task;
    task_table[priority].mem_size = mem_size;
    task_table[priority].arg = arg;
    task_table[priority].rerun = rerun;
    task_table[priority].task_success = task_success;
    task_table[priority].task_fail = task_fail;

    schedule_task(priority);

    return 0;
}