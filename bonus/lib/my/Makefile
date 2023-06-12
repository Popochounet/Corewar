##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my lib
##

NAME	=	libmy.a
OBJDIR	=	obj

vpath %.c	char:\
			math:\
			number:\
			put:\
			string:\
			tab

SRC		=	\
			my_char_isalpha.c \
			my_char_isalphanum.c \
			my_char_isnum.c \
			my_char_isup.c \
			my_char_isspace.c \
			my_swapchar.c \
\
			my_convert_base.c \
\
			my_double_isneg.c \
			my_is_prime.c \
			my_nbrlen.c \
			my_getnbr.c \
			my_square_root.c \
\
			my_putchar.c \
			my_putnbr.c \
			my_putstr.c \
			my_puterror.c \
			my_puttab.c \
\
			my_strlen.c \
			my_strdup.c \
			my_clean_str.c \
			my_revstr.c \
			my_upstr.c \
			my_strlowcase.c \
			my_str_isnum.c \
			my_str_isprintable.c \
			my_str_isalpha.c \
			my_strcpy.c \
			my_strncpy.c \
			my_strcmp.c \
			my_strnbr.c \
			my_strncmp.c \
			my_strcat.c \
			my_strncat.c \
			my_str_to_word_array.c \
			count_word.c \
			is_separator.c \
			my_strcpypart.c \
			my_str_to_word_array_sep.c \
			my_clean_array.c\
			my_strcatdup.c \
\
			my_freetab.c \
			my_tablen.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./

all: $(NAME)

$(OBJ):	%.o: %.c
	gcc $(INCLUDE) -c -o $@ $< -g3

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p ../../include
		cp my.h ../../include/
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:	fclean all
