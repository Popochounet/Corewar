/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** put_winner
*/

#include "corewar.h"

void put_winner(corewar_t *corewar)
{
    if (corewar->win == -2)
        return;
    if (corewar->win == -1)
        my_putstr("\nAll dead.\n");
    else {
        my_putstr("\nThe Player ");
        my_putnbr(corewar->win);
        my_putstr("(");
        my_putstr(corewar->champions[corewar->win - 1]->name);
        my_putstr(") has won.\n");
    }
}
