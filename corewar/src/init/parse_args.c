/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parse_args
*/

#include "initialisation.h"

int parse_args(corewar_t *corewar, int ac, char **av)
{
    if (get_dump(corewar, ac, av) == 84)
        return 84;
    if (get_champions(corewar, ac, av) == 84)
        return 84;
    return 0;
}
