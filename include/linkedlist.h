/**
 * UNDER CONSTRUCTION
*/
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

/**
 * Singly linked list
*/

uint8_t linkedlist_s_insert_at_index(LINKEDLIST_S_ST *linkedlist, void* data, uint32_t index);
uint8_t linkedlist_s_insert_at_beginning(LINKEDLIST_S_ST *linkedlist, void* data);
uint8_t linkedlist_s_insert_at_end(LINKEDLIST_S_ST *linkedlist, void* data);

uint8_t linkedlist_s_delete_at_index(LINKEDLIST_S_ST *linkedlist, uint32_t index);
uint8_t linklist_s_delete_at_beginning(LINKEDLIST_S_ST *linkedlist);
uint8_t linklist_s_delete_at_beginning(LINKEDLIST_S_ST *linkedlist);

/**
 * Doubly linked list
*/

uint8_t linkedlist_d_insert_at_index(LINKEDLIST_D_ST *linkedlist, void* data, uint32_t index);
uint8_t linkedlist_d_insert_at_beginning(LINKEDLIST_D_ST *linkedlist, void* data);
uint8_t linkedlist_d_insert_at_end(LINKEDLIST_D_ST *linkedlist, void* data);

uint8_t linkedlist_d_delete_at_index(LINKEDLIST_D_ST *linkedlist, uint32_t index);
uint8_t linklist_d_delete_at_beginning(LINKEDLIST_D_ST *linkedlist);
uint8_t linklist_d_delete_at_beginning(LINKEDLIST_D_ST *linkedlist);

#endif