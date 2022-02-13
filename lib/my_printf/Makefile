##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	dot.c	\
		pointer.c	\
		dot_hard.c	\
		my_puthbase.c	\
		my_putlbase.c	\
		my_putllbase.c	\
		my_puthubase.c	\
		my_putlubase.c	\
		my_putllubase.c	\
		my_putubase.c	\
		my_puthumbase.c	\
		my_putlumbase.c	\
		my_putllumbase.c	\
		my_putumbase.c	\
		my_printf.c	\
		my_putmbase.c	\
		my_getlnbr.c	\
		scan.c	\
		bin.c	\
		flags_basic.c	\
		flags_hard.c	\
		hexa.c	\
		hexam.c	\
		int.c	\
		octa.c	\
		scan.c	\
		st_flags.c	\
		usd.c	\
		my_retbase.c	\
		my_putbase.c	\
		my_longtostr.c	\
		my_getnbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_isnum.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_strupcase.c	\
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

NAME	=	libmypf.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
