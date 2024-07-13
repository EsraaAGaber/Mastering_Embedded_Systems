
#include <stdint.h>
extern int main(void);


extern uint32_t S_TEXT      ;
extern uint32_t E_TEXT      ;
extern uint32_t S_DATA      ;
extern uint32_t E_DATA      ;
extern uint32_t S_BSS       ;
extern uint32_t E_BSS       ;
extern uint32_t _STACK_TOP  ;

void Default_Handler(void)
{

    uint32_t DATA_SIZE = (uint8_t *) &E_DATA - (uint8_t *) &S_DATA ;
    uint8_t* ptr_SOURCE = (uint8_t *) &E_TEXT ;
    uint8_t* ptr_DISTINATION = (uint8_t *) &S_DATA ; 
    for(uint32_t i = 0 ; i < DATA_SIZE ; i++ )
    {
        *((uint8_t *)(ptr_DISTINATION++)) = *((uint8_t *)(ptr_SOURCE++)) ;
    }
    uint32_t BSS_SIZE = (uint8_t *) &E_BSS - (uint8_t *) &S_BSS ;
      for(uint32_t i = 0 ; i < BSS_SIZE ; i++ )
    {
        *((uint8_t *)(ptr_DISTINATION++)) = ((uint8_t)(0)) ;
    }
   

    main();
}


void Reset_Handler(void)         __attribute__((weak,alias("Default_Handler")));

void NMI_Handler(void)           __attribute__((weak,alias("Default_Handler")));

void H_Fault_Handler(void)       __attribute__((weak,alias("Default_Handler")));

void MM_Fault_Handler(void)     __attribute__((weak,alias("Default_Handler")));

void Bus_Fault(void)            __attribute__((weak,alias("Default_Handler")));

void Usage_Fault_Handler(void)  __attribute__((weak,alias("Default_Handler"))); 

uint32_t vectors[] __attribute__((section(".vectors")))=
{
    (uint32_t ) &_STACK_TOP           ,
    (uint32_t ) &Reset_Handler       ,
    (uint32_t ) &NMI_Handler         ,
    (uint32_t ) &H_Fault_Handler     ,
    (uint32_t ) &MM_Fault_Handler    ,
    (uint32_t ) &Bus_Fault           ,
    (uint32_t ) &Usage_Fault_Handler


};
