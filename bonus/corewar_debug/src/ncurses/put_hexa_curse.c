/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** put_hexa_curse
*/

#include "visual.h"
#include "tools.h"
#include <stdlib.h>

void put_hexa_curse(WINDOW *win, int nbr, int x, int y)
{
    char *hexa = my_convert_base(nbr, 16, true);
    bool one_letter = 0;

    if (my_strlen(hexa) < 2) {
        mvwprintw(win, y, x, "0");
        one_letter = 1;
    }
    mvwprintw(win, y, x + one_letter, hexa);
    free(hexa);
}
