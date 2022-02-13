##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_putbase.c	\
		my_longtostr.c	\
		return_base.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_sslen.c	\
		my_char_isnum.c	\
		my_getstrnbr.c	\
		my_putss.c	\
		my_strtoss.c	\
		my_inttostr.c	\
		deladd_cis.c	\
		deladd_siss.c	\
		my_char_isbase.c	\
		my_str_isbase.c	\
		deladd_ucis.c	\
		my_ustrlen.c	\
		my_ustrdup.c	\
		my_str_toarray.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
