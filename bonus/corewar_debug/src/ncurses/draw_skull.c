/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** draw_skull
*/

#include "visual.h"

void draw_skull(WINDOW *win, int x, int y)
{
    mvwprintw(win, y + 0, x, "      _");
    mvwprintw(win, y + 1, x, "  .-'( )'_.");
    mvwprintw(win, y + 2, x, ",'_/(_u_)\\_`.");
    mvwprintw(win, y + 3, x, "| ,-,(_),-, |");
    mvwprintw(win, y + 4, x, "|(\\O/) (\\O/)|");
    mvwprintw(win, y + 5, x, "\\ '-'/\"\\'-' /");
    mvwprintw(win, y + 6, x, " `;,_   _,;'");
    mvwprintw(win, y + 7, x, "  \\-HHHHH-/");
    mvwprintw(win, y + 8, x, "   '-----'");
}
