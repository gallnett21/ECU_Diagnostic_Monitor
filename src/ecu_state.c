#include <ecu_state.h>

/*Private definitions*/
static EcuState ecustate = ECU_OFF;

/*Public Functions*/
void Ecu_Init(void)
{
    ecustate = ECU_OFF;
}

EcuState Ecu_GetState(void) {
    return ecustate;
}

bool Ecu_SetState(EcuState requested_state){

    bool valid_transition = false;

    switch (ecustate)
    {
    case ECU_OFF:
        if (requested_state == ECU_INIT)
        {
            ecustate = requested_state;
            valid_transition = true;
        }
        break;
    case ECU_INIT:
        if (requested_state == ECU_RUN || requested_state == ECU_ERROR)
        {
            ecustate = requested_state;
            valid_transition = true;
        }
        break;
    case ECU_RUN:
        if (requested_state == ECU_OFF || requested_state == ECU_ERROR)
        {
            ecustate = requested_state;
            valid_transition = true;
        }
        break;
    case ECU_ERROR:
        if (requested_state == ECU_OFF)
        {
            ecustate = requested_state;
            valid_transition = true;
        }
        break;
    default: 
        break;
    }
    return valid_transition;
    
}