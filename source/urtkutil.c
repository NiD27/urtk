#include "urtkutil.h"


void clear_buffer(uint8_t* buffer_start, uint32_t buffer_size){
    uint32_t i = 0;
    for(i = 0; i < buffer_size; i++){
        buffer_start[i] = NULL;
    }
}

void fill_buffer(uint8_t* buffer_start, uint32_t buffer_size, uint8_t filler){
    uint32_t i = 0;
    for(i = 0; i < buffer_size; i++){
        buffer_start[i] = filler;
    }
}
