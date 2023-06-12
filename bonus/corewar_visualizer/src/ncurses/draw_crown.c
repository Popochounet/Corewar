/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** draw_crown
*/

#include "visual.h"

void draw_crown(WINDOW *win, int x, int y)
{
    draw_line(win, x, &y, "  _.+._");
    draw_line(win, x, &y, "(^\\/^\\/^)");
    draw_line(win, x, &y, " \\@*@*@/");
    draw_line(win, x, &y, " {_____}");
    for (int i = 0; i < 4; i++)
        mvwchgat(win, y - 4 + i, x, 9, A_BOLD, 3, NULL);
}
