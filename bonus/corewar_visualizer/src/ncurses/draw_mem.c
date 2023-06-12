/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** draw_mem
*/

#include "visual.h"

static void highlight_process(visual_t *visual, process_t *process)
{
    pos_t pos;

    for (; process != NULL; process = process->next) {
        pos = get_pos_mem(process->pc, visual->mem_pos, visual->mem_spacing);
        mvwchgat(visual->win, pos.y, pos.x, 2, A_REVERSE, get_color(
            process->champ_id), NULL);
    }
}

static void color_mem(visual_t *visual)
{
    pos_t pos;

    for (int i = 0; i < MEM_SIZE; i++) {
        pos = get_pos_mem(i, visual->mem_pos, visual->mem_spacing);
        mvwchgat(visual->win, pos.y, pos.x, 2, A_NORMAL, get_color(
            visual->mem_color[i]), NULL);
    }
}

void draw_mem(corewar_t *corewar, visual_t *visual)
{
    for (int i = 0; i < MEM_SIZE; i++)
        put_hexa_curse(visual->win, corewar->memory[i],
            get_pos_mem(i, visual->mem_pos, visual->mem_spacing));
    color_mem(visual);
    highlight_process(visual, corewar->processes);
    wnoutrefresh(visual->win);
}
