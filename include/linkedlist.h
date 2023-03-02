#ifndef _URTK_LINKEDLIST
#define _URTK_LINKEDLIST

#include <stdint.h>

/**
* NODE_S_ST : Singly linked list
* NODE_D_ST : Double linked list 
*/

typedef struct NODE_S{
    void* data;
    struct NODE_S* next;
}NODE_S_ST;

typedef struct NODE_D{
    struct NODE_D* prev;
    void* data;
    struct NODE_S* next;
}NODE_D_ST;

typedef struct LINKEDLIST_S{
    NODE_S_ST *HEAD, *CURRENT, *TAIL;
    uint32_t length;
}LINKEDLIST_S_ST;

typedef struct LINKEDLIST_D{
    NODE_D_ST *HEAD, *CURRENT, *TAIL;
    uint32_t length;
}LINKEDLIST_D_ST;

uint8_t linkedlist_insert_at_index(void* data, uint32_t index);
uint8_t linkedlist_insert_at_beginning(void* data);
uint8_t linkedlist_insert_at_end(void* data);

uint8_t linkedlist_delete_at_index(uint32_t index);
uint8_t linklist_delete_at_beginning();
uint8_t linklist_delete_at_beginning();

#endif