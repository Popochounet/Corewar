/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** draw_champ_box
*/

#include "visual.h"
#include "processes.h"
#include "my.h"

static int get_champ_size(mem_t mem, int champ_id)
{
    int size = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        if (mem[i] == champ_id)
            size++;
    return size;
}

void draw_champ_box(WINDOW *win, champion_t *champion, process_t *processes,
visual_t *visual)
{
    if (champion == NULL)
        return;
    werase(win);
    mvwprintw(win, 1, 3, "%d : %s", champion->id, champion->name);
    mvwchgat(win, 1, 3, my_strlen(champion->name) + 5, A_BOLD, champion->id,
        NULL);
    mvwprintw(win, 2, 3, champion->comment);
    mvwprintw(win, 4, 3, "Cycle before die: %d", champion->cycle_before_die);
    mvwprintw(win, 5, 3, "Size: %d", get_champ_size(visual->mem_color,
        champion->id));
    mvwprintw(win, 6, 3, "Process_count: %d",
        count_champ_processes(processes, champion->id));
    if (champion->saying_live) {
        mvwprintw(win, 8, 3, "I'M ALIVE!");
        if (!visual->pause)
            champion->saying_live = false;
    }
    if (!champion->alive)
        draw_skull(win, 40, 0);
    wattron(win, COLOR_PAIR(champion->id));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(champion->id));
    wnoutrefresh(win);
}
