##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c	\
			src/no_option_ls.c	\
			src/ls_l_option.c	\
			src/ls_d_option.c	\
			src/ls_r_option.c	\
			src/call_function.c	\
			src/simple_ls.c		\
			src/print_time.c	\
			src/sort_dir.c		\
			src/check_pathname.c	\
			src/right_print.c	\
			src/print_l_spe.c	\
			src/get_option.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	+=	-Wall -Werror -Wshadow -Wshadow -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
			make re -C lib/my/
			cc $(OBJ) -o $(NAME) -L./lib/ -lmy

unit_tests:	$(OBJ)
			make re -C lib/my/
			make re -C tests/

run_tests:
			./tests/unit_tests


clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			make fclean -C lib/my/
			rm -f lib/libmy.a

re:			fclean all