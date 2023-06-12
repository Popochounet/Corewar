/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_dump_index
*/

#include "initialisation.h"
#include "my.h"

static int get_dump_at_index(int ac, char **av, int i, int *dump_index)
{
    bool dump_found = false;

    if (my_strcmp(av[i], "-dump") == 0) {
        if (dump_found) {
            my_puterror("There can only be one -dump\n");
            return DUMP_INDEX_ERROR;
        }
        if (i + 1 == ac) {
            my_puterror("Dump need an argument\n");
            return DUMP_INDEX_ERROR;
        }
        *dump_index = i;
        dump_found = true;
    }
    return 0;
}

static int get_dump_index(int ac, char **av)
{
    int dump_index = DUMP_INDEX_NOT_FOUND;

    for (int i = 1; i < ac; i++) {
        if (get_dump_at_index(ac, av, i, &dump_index) == DUMP_INDEX_ERROR)
            return DUMP_INDEX_ERROR;
    }
    return dump_index;
}

int get_dump(corewar_t *corewar, int ac, char **av)
{
    corewar->dump_index = get_dump_index(ac, av);
    if (corewar->dump_index == DUMP_INDEX_ERROR)
        return 84;
    if (corewar->dump_index != DUMP_INDEX_NOT_FOUND)
        corewar->dump_cycle = my_getnbr(av[corewar->dump_index + 1]);
    return 0;
}
