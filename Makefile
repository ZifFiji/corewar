##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/main.c
SRC += ./src/corewar.c
SRC += ./src/op.c
SRC += ./src/parser/parser_file.c
SRC += ./src/parser/parser_input.c
SRC += ./src/instructions/and.c
SRC += ./src/instructions/live.c
SRC += ./src/instructions/add.c
SRC += ./src/instructions/aff.c
SRC += ./src/instructions/zjmp.c
SRC += ./src/instructions/xor.c
SRC += ./src/instructions/sti.c
SRC += ./src/instructions/st.c
SRC += ./src/instructions/lldi.c
SRC += ./src/instructions/or.c
SRC += ./src/instructions/lld.c
SRC += ./src/instructions/lfork.c
SRC += ./src/instructions/ldi.c
SRC += ./src/instructions/ld.c
SRC += ./src/instructions/fork.c
SRC += ./src/instructions/sub.c
SRC += ./src/display/display_help.c
SRC += ./src/display/display_champions.c
SRC += ./src/display/display_memory.c
SRC += ./src/memory_management/init_structure.c
SRC	+= ./src/parser/parser_instructions.c

OBJ = $(SRC:.c=.o)

SRC_T = ./src/corewar.c \

NAME =	corewar

CFLAGS = -W -Wall -Wextra -Wno-deprecated-declarations

CPPFLAGS = -I./include -g3

CRITFLAGS = --coverage -lcriterion

CC = gcc

DIRLIB = lib/

# TEST FILES
DIRT = tests/tests.c \

LDLIBS = -L./lib/ -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DIRLIB)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	find . -name "vgcore" -delete
	find . -name "*coding-style*" -delete
	rm -f vgcore*
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)
	make clean -C $(DIRLIB)

re: fclean all

unit_tests:
	make -C $(DIRLIB)
	gcc -o unit_tests $(SRC_T) $(DIRT) $(LDLIBS) $(CPPFLAGS) $(CRITFLAGS)

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

debug:	CPPFLAGS	+= -g3
debug:	re

.PHONY: all clean debug fclean re unit_tests tests_run
