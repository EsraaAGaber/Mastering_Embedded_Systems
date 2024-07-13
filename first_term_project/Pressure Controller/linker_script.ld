
MEMORY
{
    
  FLASH(RX): ORIGIN = 0X08000000 , LENGTH = 128K
  SRAM(RWX): ORIGIN = 0X20000000 , LENGTH = 20K

}


SECTIONS
{
    .text : 
    { 
      S_TEXT = . ; 
      *(.vectors*)
      *(.text*)
      *(.rodata)
      E_TEXT = . ;

    }> FLASH
    .data : 
    { 
      S_DATA = . ;
      *(.data)
      . = ALIGN(4) ;
      E_DATA = . ;

    }> SRAM AT> FLASH
    .bss :
    {
      S_BSS = . ;
      *(.bss)
      E_BSS = . ;
      . = ALIGN(4) ; 
      . = . + 0x1000 ; 
      _STACK_TOP = . ;
    }> SRAM
   .comment :
   {

     *(.comment) *(COMMON)

   }> FLASH



}