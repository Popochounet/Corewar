/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** draw_title
*/

#include "visual.h"

void draw_title(WINDOW *win, int x, int y)
{
    draw_line(win, x, &y, " _____  _____ ______  _____  _    _   ___  ______ ");
    draw_line(win, x, &y, "/  __ \\|  _  || ___ \\|  ___|| |  | | / _ \\ | ___ \\");
    draw_line(win, x, &y, "| /  \\/| | | || |_/ /| |__  | |  | |/ /_\\ \\| |_/ /");
    draw_line(win, x, &y, "| |    | | | ||    / |  __| | |\\/| ||  _  ||    / ");
    draw_line(win, x, &y, "| \\__/\\\\ \\_/ /| |\\ \\ | |___ \\  /\\  /| | | || |\\ \\ ");
    draw_line(win, x, &y, " \\____/ \\___/ \\_| \\_|\\____/  \\/  \\/ \\_| |_/\\_| \\_|");
    for (int i = 0; i < 6; i++)
        mvwchgat(win, y - 6 + i, x, 50, A_BOLD, 0, NULL);
}
