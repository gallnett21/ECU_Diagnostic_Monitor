#include <assert.h>
#include "ecu_state.h"

void Test_EcuInitialization(void)
{
    Ecu_Init();
    assert(Ecu_GetState() == ECU_OFF);
}

void Test_EcuValidTransition(void)
{
    Ecu_Init();
    bool result = Ecu_SetState(ECU_INIT);

    assert(result == true);
    assert(Ecu_GetState() == ECU_INIT);
}

void Test_EcuInValidTransition(void)
{
    Ecu_Init();

    bool result = Ecu_SetState(ECU_RUN);
    
    assert(result == false);
    assert(Ecu_GetState() == ECU_OFF);
}

void Test_EcuInitToRun(void)
{
    Ecu_Init();
    bool result = Ecu_SetState(ECU_INIT);

    assert(result == true);
    assert(Ecu_GetState() == ECU_INIT);

    result = Ecu_SetState(ECU_RUN);

    assert(result == true);
    assert(Ecu_GetState() == ECU_RUN);
    
}

int main(void)
{
    Test_EcuInitialization();
    Test_EcuValidTransition();
    Test_EcuInValidTransition();
    Test_EcuInitToRun();

    return 0;
}