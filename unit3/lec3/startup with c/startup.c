#include <stdint.h>
extern uint32_t _stack_top;
extern int main(void);
extern uint32_t _S_DATA ,_E_DATA ,_S_BSS,_E_BSS,_E_TEXT;
void Rest_Handler(void)
{
	uint32_t DATA_SIZE = (uint8_t)&_E_DATA - (uint8_t)&_S_DATA;
	uint8_t* p_src =(uint8_t*)&_E_TEXT;
	uint8_t* p_dst =(uint8_t*)&_S_DATA;
	int i;
	for (i=0;i<DATA_SIZE;i++){
		*((uint8_t*)p_dst++) = *((uint8_t*)p_src++);
	}


	uint32_t BSS_SIZE = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	p_dst =(uint8_t*)&_S_BSS;
	for (i=0;i<BSS_SIZE;i++){
		*((uint8_t*)p_dst++) = (uint8_t)0;
	}
	main();
}
void NMI_Handler(void)__attribute__((weak,alias("Rest_Handler")));

void H_Fault_Handler(void)__attribute__((weak,alias("Rest_Handler")));

void MM_Fault_Handler(void)__attribute__((weak,alias("Rest_Handler")));

void Bus_Handler(void)__attribute__((weak,alias("Rest_Handler")));

void Usage_Fault_Handler(void)__attribute__((weak,alias("Rest_Handler")));

uint32_t vectors[] __attribute__((section(".vector")))={
	(uint32_t)&_stack_top,
	(uint32_t)&Rest_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&H_Fault_Handler,
	(uint32_t)&MM_Fault_Handler,
	(uint32_t)&Bus_Handler,
	(uint32_t)&Usage_Fault_Handler
};
