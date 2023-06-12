/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free_visual
*/

#include "visual.h"
#include <stdlib.h>

void free_visual(visual_t *visual)
{
    delwin(visual->win);
    endwin();
    free(visual);
}
