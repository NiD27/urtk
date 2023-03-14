#ifndef _URTK_TASK
#define _URTK_TASK

#include "urtkint.h"
#include "urtk_settings.h"

/** Philosophy
  * There is no thread or process, everything is a task
  * A task is the most basic element, and no family tree of task
  * A task cannot create another task, it can still terminate other tasks
  *   > Cannot create another task
  *   > Can terminate other task
  *   > Can block another task
  *   > Can Self-Block
  *   > Can Self-Terminate
  * All tasks must be created by user, but can be enabled and disabled by
  * other tasks.
  * 
  * Priority:
  * > Lower is better(1-255)
  * > 0 is reserved for scheduler  
  * 
  * Task:
  * > A task is nothing but a function
  * > Each Task(function) should return either a
  *   0(success) or 1(failure) to the kernel(scheduler)
  *
  * State:
  * > 0 : Started
  * > 1 : Runnable
  * > 2 : Running
  * > 3 : Blocked (Waiting)
  * > 4 : Terminated
  *
  * CURRENT LIMITATIONS
  * > Maximum 255+1 tasks +1 is the scheduler
  * > No priority clashes priorities must be unique
  *
*/

typedef enum task_state {
  STARTED = 0,
  RUNNABLE = 1,
  RUNNING = 2,
  BLOCKED = 3,
  TERMINATED = 4
};

typedef struct task{
    uint8_t tid;
    uint8_t state;
    uint8_t exit_status;

    uint8_t (*task)(void);
    uint8_t priority;
    uint32_t mem_size;
    void *arg;
    uint8_t rerun;
    uint8_t (*task_success)(void *arg);
    uint8_t (*task_fail)(void *arg);
}task_st;

/**
 * More stuff
 * (I realize using uint_t as return might be a shit idea)
 * > Every task returns(uint8_t) 0(success exit) or not 0(failure exit)
 *    to the kernel
 * > A task doesnt have to be infinite, it can in fact exit
 * > A task can be configured to re-run, re-run on success or re-run on failure
 * --------------------------------------------------
 * NEW IDEA!
 * Task chaining we'll call it
 * A task once exited can create and run another task
 * Example:
 *    TaskA runs and fails and therefore needs to do some cleanup
 *    Thus, calls TaskAcleanup
 *    Alternatively, TaskA runs successfully
 *    Therefore, calls TaskB to continue the procedure
 * Better Example:
 *    You press the windshield clean button (water spray + wipers)
 *    The water sump is empty therefore dont start the wipers
 *    The water spray is success thus start the wipers
 * Therefore with this feature the code can be better divided into
 * more atomic and re-usable tasks
 * --------------------------------------------------
 * Afterthought : 
 *    Probably can be implemented using SIGNALS or something
 *    but I think I see a edge case where SIGNALS cant be used
 *    so I'm keeping this
 * Also, I really wish C had function overloading...
 * --------------------------------------------------
 * Task re-runs and Task chaining are currently mutually exclusive 
 * features, pick one. If both are picked then Task rerun will be 
 * considered and Task chaining will be ignored
 * --------------------------------------------------
 * I do realize what a feature creep induced bloated mess my task is
 * but if you are taking this kernel seriously you're the one thats mental
 * --------------------------------------------------
 * Un-implemented ideas
 * -Pass by value option for task void *arg
*/

/**
 * Optional : Pass NULL(0x00) if not needed
 * \arg : 
 *    > function pointer of type uint8_t (*function_name)(void *arg)
 *    > uint8_t Priority(1-255) lower is better
 *    > uint32_t amount of memory allocated for task
 *    > (Optional) : arg pointer
 *    > (Optional) uint8_t : 0(NULL) - no re-run, 1 - re-run, 2 - re-run on success, 3 - re-run on fail
 *    > (Optional) uint8_t (*function_name)(void *arg) task to run on success
 *    > (Optional) uint8_t (*function_name)(void *arg) task to run on failure
 * \brief :
 * 
 * \return :
 *    > 0 - success
 *    > 1 - failure
 *    *Below idea needs more thinking
 *    > 2 - modified (ie due to in-compactible settings, task was modified by kernel)
 *    > maybe in the future I'll add more failure values
*/

uint8_t create_task(uint8_t (*task)(void *arg), uint8_t priority, uint32_t mem_size, void *arg,\
                    uint8_t rerun, uint8_t (*task_success)(void *arg), uint8_t (*task_fail)(void *arg));

#endif