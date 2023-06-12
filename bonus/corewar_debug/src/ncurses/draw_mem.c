/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** draw_mem
*/

#include "visual.h"

static void highlight_process(visual_t *visual, process_t *process)
{
    for (; process != NULL; process = process->next) {
        mvwchgat(visual->win,
            visual->mem_pos.y + process->pc / visual->line_len,
            visual->mem_pos.x + process->pc % visual->line_len * 3, 2,
            A_REVERSE, process->champ_id, NULL);
    }
}

static void color_mem(visual_t *visual)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        mvwchgat(visual->win, visual->mem_pos.y + i / visual->line_len,
            visual->mem_pos.x + i % visual->line_len * 3, 2, A_NORMAL,
            visual->mem_color[i], NULL);
    }
}

void draw_mem(corewar_t *corewar, visual_t *visual)
{
    for (int i = 0; i < MEM_SIZE; i++)
        put_hexa_curse(visual->win, corewar->memory[i], visual->mem_pos.x + i %
            visual->line_len * 3, visual->mem_pos.y + i / visual->line_len);
    mvwchgat(visual->win, 10, 10, 20, A_NORMAL, 2, NULL);
    color_mem(visual);
    highlight_process(visual, corewar->processes);
}
