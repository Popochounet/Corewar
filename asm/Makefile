##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## a short file description
##

SRC =		main.c							\
			../include/op.c					\
			disp_usage.c					\
			little_to_big.c					\
			get_header_from_champ.c			\
			valid_cmd.c						\
			open_cor_file.c					\
			body_parsing/add_command_body.c	\
			body_parsing/add_directives.c	\
			body_parsing/body_parse.c		\
			body_parsing/free_body_parsing.c\
			body_parsing/clean_array.c 		\
			body_parsing/verify_body.c		\
			tools/my_strcat_body.c			\

OBJ =		$(SRC:.c=.o)

NAME = asm

LIBFLAGS	=	-L../lib -lmy
CFLAGS		=	-g -Wall -Wextra -pedantic
CPPFLAGS	=	-I./include -I../include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)

debug: fclean $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all
