SRCS = $(shell find instructions -name "*.c")
OBJS = $(patsubst %.c,%.o,$(SRCS))
NOMAKEDIR = $()
INCLUDE=$(addprefix -I./,$(filter-out $NOMAKEDIR), $(shell find * -type d))

asm : $(SRCS) asm.c instructions/commands.h
	gcc -o asm $(SRCS) asm.c

