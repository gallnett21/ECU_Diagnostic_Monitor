#ifndef ECU_STATE_H
#define ECU_STATE_H

/*Required includes*/
#include <stdbool.h>

/*Type definitions*/
typedef enum {
    ECU_OFF,
    ECU_INIT,
    ECU_RUN,
    ECU_ERROR
} EcuState;

/*Function prototypes*/
void Ecu_Init(void);
EcuState Ecu_GetState(void);
bool Ecu_SetState(EcuState requested_state);

#endif