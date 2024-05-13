##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	my_strlen.c				\
		my_putstr.c				\
		my_getnbr.c				\
		my_str_to_word_array.c	\
		my_strcmp.c				\
		my_getbuff.c			\
		my_show_array.c			\
		my_cleanstr.c			\
		my_strdup.c				\
		my_strcat.c				\
		math.c					\
		my_is_alphanum.c		\
		my_char_is_alpha.c		\
		my_isdigit.c			\
		my_isalphanum.c			\
		my_put_nbr_base.c		\
		my_putchar.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@find -name '*.a' -delete
	@find -name '*~' -delete
	@find -name '*.o' -delete
	@find -name '*gcda' -delete
	@find -name '*gcno' -delete
	@find -name 'vgcore*' -delete
	@find -name '*.log' -delete

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY:	re all fclean clean
