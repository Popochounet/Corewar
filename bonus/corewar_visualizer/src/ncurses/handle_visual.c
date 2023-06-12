/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** handle_visual
*/

#include "visual.h"
#include <unistd.h>

int handle_visual(corewar_t *corewar, visual_t *visual)
{
    clock_t now = clock();
    double elapsed_time = (double)(now - visual->last_cycle) / CLOCKS_PER_SEC;
    double time_to_wait = 1 / visual->cycle_per_second - elapsed_time * 1000;

    if (!corewar->visual)
        return VISUAL_NONE;
    draw_screen(corewar, visual);
    if (key_handler(visual, corewar))
        return VISUAL_EXIT;
    if (visual->pause) {
        usleep(10000);
        if (visual->step_forward)
            visual->step_forward = false;
        else
            return VISUAL_PAUSE;
    }
    if (time_to_wait > 0)
        usleep(time_to_wait * 1000000);
    visual->last_cycle = clock();
    return VISUAL_NONE;
}
