################################################################################
# These are variables for the GBA toolchain build
# You can add others if you wish to
################################################################################

# The name of your desired GBA image
# This should be a just a name i.e MyFirstGBAGame
PROGNAME = HW9

# The object files you want to compile into your program
# This should be a space (SPACE!) separated list of .o files
OFILES   = HW9.o mylib.o text.o Lose.o

# The flags to run the vba program with
# for a list of options run /usr/local/cs2110-tools/bin/vbam
# Most notable ones are -f0 -f1 -f13 -f15
# -f0 : Stretch 1x -f1 : Stretch 2x -f13 : Stretch 3x -f15 : Stretch 4x
VBAOPT	 = -f1

# The cflags you want to compile with DO NOT EDIT THIS We will change it back when we grade your submission.
CFLAGS   = -Wall -Werror -ansi -pedantic -O2

################################################################################
# These are various settings used to make the GBA toolchain work
# Change these at your own risk
################################################################################

TOOLDIR  = /usr/local/cs2110-tools
CFLAGS  += -mthumb-interwork -mlong-calls -nostartfiles
LDFLAGS = -L $(TOOLDIR)/lib \
		  -L $(TOOLDIR)/lib/gcc/arm-thumb-eabi/4.4.1/thumb \
		  -L $(TOOLDIR)/arm-thumb-eabi/lib \
		  --script $(TOOLDIR)/arm-thumb-eabi/lib/arm-gba.ld
CC      = $(TOOLDIR)/bin/arm-thumb-eabi-gcc
AS      = $(TOOLDIR)/bin/arm-thumb-eabi-as
LD      = $(TOOLDIR)/bin/arm-thumb-eabi-ld
OBJCOPY = $(TOOLDIR)/bin/arm-thumb-eabi-objcopy
GDB     = $(TOOLDIR)/bin/arm-thumb-eabi-gdb

################################################################################
# These are the targets for the GBA build system
################################################################################

all: $(PROGNAME).gba

$(PROGNAME).gba: $(PROGNAME).elf
	$(OBJCOPY) -O binary $(PROGNAME).elf $(PROGNAME).gba

$(PROGNAME).elf: crt0.o $(OFILES)
	$(LD) $(LDFLAGS) -o $(PROGNAME).elf $^ -lgcc -lc -lgcc

crt0.o: $(TOOLDIR)/arm-thumb-eabi/lib/crt0.s
	$(AS) -mthumb-interwork $^ -o crt0.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.elf *.gba

vba: $(PROGNAME).gba
	$(TOOLDIR)/bin/vbam $(VBAOPT) $(PROGNAME).gba
