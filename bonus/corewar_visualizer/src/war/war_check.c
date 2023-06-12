/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** war_check.c
*/

#include "war.h"

int check_win(champion_t **champions, int nb_champ)
{
    int win = 0;

    for (int i = 0; i < nb_champ; i++) {
        if (champions[i]->alive && win)
            return 0;
        if (champions[i]->alive && !win)
            win = champions[i]->id;
    }
    return win ? win : -1;
}

void war_check(corewar_t *corewar)
{
    corewar->cycle++;
    for (int i = 0; i < corewar->champion_count; i++) {
        if (!corewar->champions[i]->alive)
            continue;
        corewar->champions[i]->cycle_before_die--;
        if (!corewar->champions[i]->cycle_before_die)
            corewar->champions[i]->alive = false;
    }
}
