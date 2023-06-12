/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free
*/

#include "free.h"

void free_corewar(corewar_t *corewar)
{
    free_champion(corewar->champions, corewar->champion_count);
    free_processes(corewar->processes);
    free(corewar);
}
