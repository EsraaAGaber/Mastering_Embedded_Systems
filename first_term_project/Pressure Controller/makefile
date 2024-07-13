CC= arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIRS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
FILE_NAME=pressure_controller
all: $(FILE_NAME).bin $(FILE_NAME).hex $(FILE_NAME).axf
	@echo "Done "

%.o: %.s
	$(CC)as.exe -c $(CFLAGS)  $(INCS) $< -o $@
%.o: %.c
	 $(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
$(FILE_NAME).elf: $(OBJ) $(ASOBJ)
	 $(CC)ld.exe -T  linker_script.ld -Map=output.map $(OBJ) $(ASOBJ) -o $(FILE_NAME).elf

$(FILE_NAME).hex: $(FILE_NAME).elf
	$(CC)objcopy.exe -O ihex $< $@ 
$(FILE_NAME).bin: $(FILE_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
$(FILE_NAME).axf: $(FILE_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
	cp $< $@
clean:
	rm -rf *.o *.hex *.elf *.bin *.map *axf
	@echo "Everything Clean"      





	
	
              

 
