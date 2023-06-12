##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## a short file description
##

all: oe

LIBDIR	=	lib/my/

oe:
	$(MAKE) -C $(LIBDIR)
	$(MAKE) -C asm/
	$(MAKE) -C corewar/

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(MAKE) -C asm/ clean
	$(MAKE) -C corewar/ clean

fclean:
	$(MAKE) -C $(LIBDIR) fclean
	$(MAKE) -C asm/ fclean
	$(MAKE) -C corewar/ fclean

re: fclean all
