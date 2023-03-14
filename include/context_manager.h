#ifndef _URTK_CONTEXT_MANAGER
#define _URTK_CONTEXT_MANAGER

#include "urtkint.h"
#include "port.h"
/**
 * So each task gets its own space to hold
 * its register values in the memory table?
 * Since context swap is an hardware interrupt
 * our registers are already stored for us somewhere
 * SOMEWHERE
*/
uint8_t context_swap();

#endif