DIR = $(wildcard */)
SYM = $(DIR:/=.sym)
C_SRC = $(wildcard */*.c)
C_PRE = $(C_SRC:.c=.pre)
C_ASM = $(C_PRE:.pre=.s)
ASM = $(C_ASM)
OBJ = $(ASM:.s=.obj)

all: clean $(SYM)

PERCENT = %

.SECONDEXPANSION:
%.sym: $$(filter %/$$(PERCENT).obj, $(OBJ))
	psylink /g /c /q $^,foo.cpe,$@
	rm -f foo.cpe

%.obj: %.s
	aspsx -q $< -o $@

%.s: %.pre
	cc1psx -quiet -g $< -o $@

%.pre: %.c
	cpppsx -undef -D__GNUC__=2 -lang-c -Dmips -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D_LANGUAGE_C -DLANGUAGE_C $< -o $@

.PHONY: clean ${DIR}

clean:
	rm -f $(C_PRE) $(ASM) $(OBJ) *.sym

#CPP_SRC = $(wildcard */*.cpp)
#CPP_PRE = $(CPP_SRC:.cpp=.pre_cpp)
#CPP_ASM = $(CPP_PRE:.pre_cpp=.s)
#ASM = $(C_ASM) $(CPP_ASM)

#foo.sym:
#	ccpsx -g a.c b.c -ofoo.cpe,$@
#	cpe2x foo.cpe

#%.pre_cpp: %.cpp
#	cpppsx -undef -D__GNUC__=2 -lang-c++ -D__cplusplus -Dmips -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D__CHAR_UNSIGNED__ -D_LANGUAGE_C_PLUS_PLUS $< -o $@

#%.s: %.pre_cpp
#	cc1plpsx -quiet -g $< -o $@

#clean:
#	rm -f *.pre *.pre_cpp *.s *.obj foo.cpe foo.sym
