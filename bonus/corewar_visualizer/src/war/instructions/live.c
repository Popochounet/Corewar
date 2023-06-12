/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** live.c
*/

#include "instruction.h"

int live(process_t *current, corewar_t *corewar)
{
    int plyr = read_mem(corewar->memory, &current->pc, sizeof(int));
    if (plyr > 0 && plyr <= corewar->champion_count) {
        corewar->champions[plyr - 1]->cycle_before_die = corewar->cycle_to_die;
        if (!corewar->visual) {
            my_putstr("The player ");
            my_putnbr(corewar->champions[plyr - 1]->id);
            my_putstr("(");
            my_putstr(corewar->champions[plyr - 1]->name);
            my_putstr(") is alive.\n");
        } else {
            corewar->champions[plyr - 1]->saying_live = true;
        }
    }
    corewar->live_count++;
    if (corewar->live_count == NBR_LIVE) {
        corewar->live_count = 0;
        corewar->cycle_to_die -= CYCLE_DELTA;
    }
    return current->carry;
}
