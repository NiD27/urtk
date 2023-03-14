#ifndef _URKT_MEMORY_MANAGER
#define _URTK_MEMORY_MANAGER

/**
 * DEPENDENCY!
 * Need to specify the maximum memory available
 * for your controller in the portable code in Kilo-bytes
 * URTK_SETTINGS_MAX_AVAILABLE_MEMORY
 * and all those port files need to be included into port.h
 * and just include port.h here
 * But if you wanna read this code and add just the necessary
 * headers you are free to do so
*/

#include "port.h"

/*n Byte(s)*/
#define URTK_WORD_SIZE 1
/**
 * > 0 : 1/8th mode
 *      - Consumes more memory
 *      - Less work for processor
 * > 1 : Matrix mode
 *      - Consumes less memory
 *      - More work for processor
 * Default 1/8th mode
*/
#define URTK_BITMAP_MODE 0

void alloc_kernel();
void* urtk_malloc();
void urtk_free();

#endif