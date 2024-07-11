EE_BIN = GameIdResetter.elf
EE_BIN_STRIPPED = GameIdResetterStripped.elf
EE_BIN_PACKED = BOOT/BOOT.ELF
EE_OBJS = main.o
EE_LIBS = -L$(PS2SDK)/ports/lib -L$(PS2DEV)/gsKit/lib/ -ldmakit -lgskit

EE_INCS += -I$(PS2DEV)/gsKit/include

# EE_CFLAGS is passed to GCC when compiling
EE_CFLAGS = -I$(PS2DEV)/gsKit/include
# EE_LDFLAGS is passed to GCC/ld when linking
EE_LDFLAGS = -L$(PS2DEV)/gsKit/lib

all: $(EE_BIN_PACKED)

$(EE_BIN_STRIPPED): $(EE_BIN)
	echo "Stripping..."
	$(EE_STRIP) -o $@ $<

$(EE_BIN_PACKED): $(EE_BIN_STRIPPED)
	echo "Compressing..."
	ps2-packer $< $@ > /dev/null

clean:
	rm -f $(EE_BIN) $(EE_BIN_STRIPPED) $(EE_BIN_PACKED) $(EE_OBJS)

run: $(EE_BIN_PACKED)
	ps2client execee host:$(EE_BIN_PACKED)

reset:
	ps2client reset

.PHONY: all clean run reset

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal