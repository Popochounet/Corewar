/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** draw_line
*/

#include "visual.h"

void draw_line(WINDOW *win, int x, int *y, char *str)
{
    mvwprintw(win, *y, x, str);
    (*y)++;
}
