#include "urtkernel.h"

/*KERNEL ENTRYPOINT*/
/**
 * \arg : none
 * \return : This function is not supposed to return
 *              if it does return then its considered
 *              as kernel panic.
 * \brief : it does things
*/

void kernel(){

    /*INIT THE KERNEL*/
    
    /*INIT THE SCHEDULER*/
    /**
     * Need to rethink this idea, scheduler can be task0
     * or maybe the kernel can be task0
    */
    if(!create_task(scheduler, 0, 100, NULL, 0, NULL, NULL)){
        /**
         * PANIC THE KERNEL
         * CRASH AND BURN
         * IDK WHAT TO DO
         * */
        return;
    }
    init_scheduler();

    /**
     * PASSING CONTROL TO SCHEDULER
     * SCHEDULER SHOULD NEVER RETURN
     * */
    scheduler();
}