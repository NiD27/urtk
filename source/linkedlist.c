/**
 * UNDER CONSTRUCTION
*/

#include "linkedlist.h"

/**
 * Singly linked list
*/

uint8_t linkedlist_s_insert_at_index(LINKEDLIST_S_ST *linkedlist, void* data, uint32_t index){
    uint32_t current_index = 0; //I hope to god your LL's arent larger than u32
    
    linkedlist->CURRENT = linkedlist->HEAD;
    while(linkedlist->CURRENT != 0x0 && linkedlist->CURRENT != linkedlist->TAIL){
        if(current_index == index){
            break;
        }else{
            current_index = current_index + 1;
            linkedlist->CURRENT = linkedlist->CURRENT->next;
        }
    }

    if(current_index == index){

    }

}

uint8_t linkedlist_s_insert_at_beginning(LINKEDLIST_S_ST *linkedlist, void* data){

}

uint8_t linkedlist_s_insert_at_end(LINKEDLIST_S_ST *linkedlist, void* data){

}

uint8_t linkedlist_s_delete_at_index(LINKEDLIST_S_ST *linkedlist, uint32_t index){}
uint8_t linklist_s_delete_at_beginning(LINKEDLIST_S_ST *linkedlist){}
uint8_t linklist_s_delete_at_beginning(LINKEDLIST_S_ST *linkedlist){}

/**
 * Doubly linked list
*/

uint8_t linkedlist_d_insert_at_index(LINKEDLIST_D_ST *linkedlist, void* data, uint32_t index){}
uint8_t linkedlist_d_insert_at_beginning(LINKEDLIST_D_ST *linkedlist, void* data){}
uint8_t linkedlist_d_insert_at_end(LINKEDLIST_D_ST *linkedlist, void* data){}

uint8_t linkedlist_d_delete_at_index(LINKEDLIST_D_ST *linkedlist, uint32_t index){}
uint8_t linklist_d_delete_at_beginning(LINKEDLIST_D_ST *linkedlist){}
uint8_t linklist_d_delete_at_beginning(LINKEDLIST_D_ST *linkedlist){}