MEMORY 
{
	flash(RX) :     ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS 
{
	.text :{
		*(.Vectors*)
		*(.text*)
		*(.rodata*)
		_E_TEXT = . ;
	}> flash
	.data :{
		_S_DATA = . ;
		*(.data*)
		_E_DATA = . ;
	}> sram AT> flash
	.bss :{
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = . ;
. = ALIGN(4);
		. += 0x1000;
		
		_stack_top = . ;
	}>sram

}