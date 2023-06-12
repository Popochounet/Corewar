/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_flag
*/

#include "my.h"
#include <stdlib.h>

char *parse_flag(int ac, char **av, char *flag_name, int flag_index)
{
    for (int i = flag_index; i < ac; i++) {
        if (my_strcmp(av[i], flag_name) == 0 && i + 1 == ac) {
            my_puterror(flag_name);
            my_puterror(" need an argument\n");
            return NULL;
        }
        if (my_strcmp(av[i], flag_name) == 0) {
            return av[i + 1];
        }
    }
    return NULL;
}
