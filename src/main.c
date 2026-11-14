#include <stdio.h>
#include "ecu_state.h"

int main(void){

    Ecu_Init();

    bool transition_result = Ecu_SetState(ECU_INIT);

    printf("Transition Result: %d\n", transition_result);
    printf("ECU current state %d\n", Ecu_GetState());

    transition_result = Ecu_SetState(ECU_INIT);
    printf("Transition Result: %d\n", transition_result);
    printf("ECU current state %d\n", Ecu_GetState());

    transition_result = Ecu_SetState(ECU_RUN);
    printf("Transition Result: %d\n", transition_result);
    printf("ECU current state %d\n", Ecu_GetState());

    /*Invalid transition*/
    transition_result = Ecu_SetState(ECU_INIT);
    printf("Transition Result: %d\n", transition_result);
    printf("ECU current state %d\n", Ecu_GetState());

    transition_result = Ecu_SetState(ECU_ERROR);
    printf("Transition Result: %d\n", transition_result);
    printf("ECU current state %d\n", Ecu_GetState());

    return 0;
}
