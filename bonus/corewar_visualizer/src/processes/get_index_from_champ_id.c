/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** get_index_from_champ_id
*/

#include "struct.h"

int get_index_from_champ_id(corewar_t *corewar, int id)
{
    for (int i = 0; i < corewar->champion_count; i++)
        if (corewar->champions[i]->id == id)
            return i;
    return -1;
}
