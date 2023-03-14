#ifndef _URTK_PORTABLE_ARMM4_REGISTERS
#define _URTK_PORTABLE_ARMM4_REGISTERS

#include "urtkint.h"

typedef struct GP_REGISTERS{
    uint32_t R[13];
    uint32_t SP, PSP, MSP;
    uint32_t LR;
    uint32_t PC;
    uint32_t PSR;
    uint32_t PRIMASK;
    uint32_t FAULTMASK;
    uint32_t BASEPRI;
    uint32_t CONTROL;
}GP_REGISTERS_ST;

#endif