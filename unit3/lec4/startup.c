#include <stdint.h>
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

static uint64_t  stack_top [256];
void (*const g_p_fn_vectors[])()__attribute__((section(".vectors")))={
	(void (*)()) (stack_top + sizeof(stack_top)),
	&Rest_Handler,
	&NMI_Handler,
	&H_Fault_Handler
};

