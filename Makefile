##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_ls.c	\
		files.c	\
		sort_tab_l.c	\
		sort_tab_t.c	\
		display.c	\
		chain.c	\
		print.c	\
		max_calcule.c	\
		max_calcule_bis.c	\
		rights.c	\
		sort.c	\
		print_flags.c	\
		sort_list.c	\
		noflag.c	\
		flags.c	\
		l_option.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra	

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	make -C ./lib/my_printf/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -L./lib/my_printf -lmypf

clean:
	make clean -C ./lib/my/
	make clean -C ./lib/my_printf/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	make fclean -C ./lib/my_printf/
	rm -f $(NAME)

re:	fclean all
