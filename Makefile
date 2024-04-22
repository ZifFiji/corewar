##
## EPITECH PROJECT, 2023
## make create
## File description:
## make
##

SRC = ./src/main.c
SRC += ./src/corewar.c

OBJ = $(SRC:.c=.o)

SRC_T = ./src/amazed.c \

NAME =	corewar 

CFLAGS = -W -Wall -Wextra -Wno-deprecated-declarations

CPPFLAGS = -I./include

CRITFLAGS = --coverage -lcriterion

CC = gcc

DIRLIB = lib/

# TEST FILES
DIRT = tests/tests.c \

LDLIBS = -L./lib/ -lmy

all: compile $(NAME)

$(NAME): $(OBJ)
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

re: fclean compile all

compile:
	make -C $(DIRLIB)

unit_tests: compile
	gcc -o unit_tests $(SRC_T) $(DIRT) $(LDLIBS) $(CPPFLAGS) $(CRITFLAGS)

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

debug: all
	$(CC) -g $(SRC) $(LIB) $(NAMELIB) $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean debug fclean re compile unit_tests tests_run
