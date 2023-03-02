#ifndef _URTK_TASK
#define _URTK_TASK

/** Philosophy
  * There is no thread or process, everything is a task
  * A task is the most basic element, and no family tree of task
  * A task cannot create another task, it can still terminate other tasks
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
  * > 0 : Not-Started
  * > 1 : Running
  * > 2 : Blocked (Waiting): A Task can ofc block itself
  * > 3 : Finished
  *
  * CURRENT LIMITATIONS
  * > Maximum 255+1 tasks +1 is the scheduler
  * > No priority clashes priorities my be unique
  *
*/

struct typedef TASK{
    uint8_t TID;
    uint8_t PRIORITY;
    uint8_t STATE;
    uint8_t (*function)(void);
}TASK_T;

#endif