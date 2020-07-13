############------------------------------------------------------############
############              Project-specific Details                ############
############    Check these every time you start a new project    ############
############------------------------------------------------------############

## Project name
PROJECT_NAME = SegmentDisplay

## Set used microcontroller and its operational frequency
MCU = atmega168p
F_CPU = 1000000

## File which includes main() function
MAIN = main.c

## Additional local source files
LOCAL_SOURCE_FILES = 

## Additional external source files
EXTRA_SOURCE_DIRECTORY = ../../../Source/
EXTRA_SOURCE_FILES = SegmentDisplay.c

## Header files
HEADER_FILES = ../../../Include



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
CFLAGS = -mmcu=${MCU} -DF_CPU=${F_CPU}UL -Os -I. -I${HEADER_FILES}
CFLAGS += -Wall -Wstrict-prototypes
CFLAGS += -std=gnu99

## Merge source files together
EXTRA_SOURCE = ${addprefix ${EXTRA_SOURCE_DIRECTORY}, ${EXTRA_SOURCE_FILES}}
SOURCE = ${MAIN}
SOURCE += ${LOCAL_SOURCE_FILES}
SOURCE += ${EXTRA_SOURCE}

## Generic Makefile routines
all:
	mkdir -p ../Build
	${CC} ${CFLAGS} ${SOURCE} --output ../Build/${PROJECT_NAME}.bin
	${OBJCOPY} -j .text -j .data -O ihex ../Build/${PROJECT_NAME}.bin \
    ../Build/${PROJECT_NAME}.hex

flash:
	${AVRDUDE} -p ${MCU} -B 4 -c ${PROGRAMMER_TYPE} \
    -U flash:w:../Build/${PROJECT_NAME}.hex:i -F -P usb
clean:
	rm -r ../Build
