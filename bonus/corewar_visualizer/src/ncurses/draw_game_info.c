/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** draw_game_info
*/

#include "visual.h"
#include "processes.h"

void mark_string(WINDOW *win, pos_t pos, int len, int size)
{
    for (int i = 0; i < size; i++) {
        mvwchgat(win, pos.y - size / 2 + i, pos.x - size, len + size * 2,
            A_BOLD | A_STANDOUT, 0, NULL);
    }
}

void draw_game_info(WINDOW *win, corewar_t *corewar, visual_t *visual)
{
    int y = 3;

    werase(win);
    mvwprintw(win, 2, 5, "GAME INFO");
    mvwchgat(win, 2, 5, 9, A_BOLD, 0, NULL);
    mvwprintw(win, y * 2, 3, "Cycle:\n   %d", corewar->cycle);
    mvwprintw(win, y * 3, 3, "Cycle to die:\n   %d", corewar->cycle_to_die);
    mvwprintw(win, y * 4, 3, "Live count:\n   %d", corewar->live_count);
    mvwprintw(win, y * 5, 3, "Cycle per sec:\n   %.1f",
        visual->cycle_per_second);
    mvwprintw(win, y * 6, 3, "Process_count:\n   %d", get_processes_count(
        corewar->processes));
    if (visual->pause) {
        mvwprintw(win, 27, 7, "PAUSE");
        mark_string(win, (pos_t){7, 27}, 5, 3);
    }
    box(win, 0, 0);
    wnoutrefresh(win);
}
