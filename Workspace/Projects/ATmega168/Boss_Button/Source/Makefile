############------------------------------------------------------############
############              Project-specific Details                ############
############    Check these every time you start a new project    ############
############------------------------------------------------------############

## Set used microcontroller and its operational frequency
MCU = atmega168p
F_CPU = 1000000

## File which includes main() function
MAIN = main.c

## Additional local source files
LOCAL_SOURCE_FILES = LED.c Button.c USART.c

## Additional external source files
EXTRA_SOURCE_DIRECTORY = 
EXTRA_SOURCE_FILES = 



############------------------------------------------------------############
############                 Programmer settings                  ############
############    Check these every time you change a programmer    ############
############------------------------------------------------------############

PROGRAMMER_TYPE = usbasp



############------------------------------------------------------############
############              Makefile compilation routine            ############
############    		1. Compile source files into .elf    	  ############
############    		2. Convert .elf file into .hex    	  	  ############
############------------------------------------------------------############

## Defined programs
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude

## Compilation options (type 'man avr-gcc' for additional informations)
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main

all:
        ${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
        ${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
        avrdude -p ${MCU} -B 4 -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb

clean:
        rm -f *.bin *.hex