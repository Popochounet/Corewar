/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** draw_process_box
*/

#include "visual.h"
#include "processes.h"

static void draw_process_box_registers(WINDOW *win, process_t *process)
{
    mvwprintw(win, 12, 3, "Registers:");
    for (int i = 0; i < REG_NUMBER; i++)
        mvwprintw(win, 14 + i, i < 9 ? 4 : 3, "%d: %X", i + 1, process->reg[i]);
}

void draw_process_box(WINDOW *win, process_t *process, corewar_t *corewar,
visual_t *visual)
{
    pos_t pos;
    int color;

    werase(win);
    for (int i = 0; process && i < visual->viewed_process_id; i++)
        process = process->next;
    pos = get_pos_mem(process->pc, visual->mem_pos, visual->mem_spacing);
    color = get_color(process->champ_id);

    mvwprintw(win, 2, 3, "Process %d", visual->viewed_process_id + 1);
    mvwchgat(win, 2, 3, 11, A_BOLD, color, NULL);
    mvwprintw(win, 4, 3, "Owned by");
    mvwprintw(win, 5, 3, "%s (%d)", corewar->champions[get_index_from_champ_id(
        corewar, process->champ_id)]->name, process->champ_id);
    mvwchgat(win, 5, 3, 16, A_NORMAL, color, NULL);
    mvwprintw(win, 8, 3, "Wait: %d", process->wait + 1);
    mvwprintw(win, 9, 3, "PC: %d", process->pc);
    mvwprintw(win, 10, 3, "Carry: %d", process->carry);
    mvwchgat(visual->win, pos.y, pos.x, 2, visual->pause ?
        A_UNDERLINE | A_BOLD | A_BLINK : A_UNDERLINE | A_BOLD,
        color, NULL);
    draw_process_box_registers(win, process);
    wattron(win, COLOR_PAIR(color));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(color));
    wnoutrefresh(win);
}
