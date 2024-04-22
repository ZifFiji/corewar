##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/main.c
SRC += ./src/corewar.c
SRC += ./src/display/display_help.c

OBJ = $(SRC:.c=.o)

SRC_T = ./src/corewar.c \

NAME =	corewar

CFLAGS = -W -Wall -Wextra -Wno-deprecated-declarations

CPPFLAGS = -I./include

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
