##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## Makefile
##

NAME	=	corewar

SRCDIR		=	src
BUILDDIR	=	build
LIBDIR		=	../lib/my

RUN_ARGS	=	champions/tyron.cor champions/ebola.cor

vpath %.c	$(SRCDIR):\
			$(SRCDIR)/init:\
			$(SRCDIR)/free:\
			$(SRCDIR)/war:\
			$(SRCDIR)/war/instructions:\
			$(SRCDIR)/tools:\
			$(SRCDIR)/dump:\
			$(SRCDIR)/processes:\
			$(SRCDIR)/ncurses:\

SRC	=	main.c \
		../include/op.c \
\
		init.c \
		parse_args.c \
		get_dump.c \
		get_champions.c \
		get_parse_champion.c \
		read_champion.c \
		load_champions.c \
		create_first_processes.c \
\
		free_corewar.c \
		free_champion.c \
		free_processes.c \
		free_parse_champions.c \
\
		args.c \
		read_mem.c \
		put_winner.c \
		war_check.c \
		war_loop.c \
\
		aff.c \
		fork.c \
		ld.c \
		live.c \
		logic.c \
		st.c \
		zjmp.c \
\
		put_hexa.c \
		parse_flag.c \
\
		dump_memory.c \
\
		add_process.c \
		count_champ_processes.c \
		get_processes_count.c \
\
		init_visual.c \
		key_handler.c \
		put_hexa_curse.c \
		handle_visual.c \
		draw_screen.c \
		draw_mem.c \
		draw_skull.c \
		free_visual.c \

SRCS		=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ			=	$(addprefix $(BUILDDIR)/, $(SRC:.c=.o))

CPPFLAGS	=	-Wno-deprecated-declarations -I./inc -I../include
CFLAGS		=	-g -Wall -Wextra -pedantic -fsanitize=address
LDFLAGS		=	-lmy -L./$(LIBDIR) -lncurses

all: lib $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

lib:
		$(MAKE) -C $(LIBDIR)

.PHONY: lib

clean:
	@make -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean:	clean
	@make -C $(LIBDIR) fclean
	rm -f $(NAME)

tests_run:

re:	fclean all
	@make -C $(LIBDIR) re

run: all
	./$(NAME) $(RUN_ARGS)
