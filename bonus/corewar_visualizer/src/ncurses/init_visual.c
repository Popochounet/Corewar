/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** init_visual
*/

#include "visual.h"

static void init_colors(void)
{
    start_color();

    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
}

// newwin(HEIGHT, WIDTH, Y, X)
static void init_right_boxes(visual_t *visual, unsigned short champ_count)
{
    visual->win = initscr();
    visual->game_info_win = newwin(32, 20, 1, 76);
    visual->process_win = newwin(32, 20, 43, 220);
    if (0 < champ_count)
        visual->champ_win[0] = newwin(10, 60, 33, 4);
    if (1 < champ_count)
        visual->champ_win[1] = newwin(10, 60, 33, 66 + 62 * 3);
    if (2 < champ_count)
        visual->champ_win[2] = newwin(10, 60, 33, 4 + 62 * 1);
    if (3 < champ_count)
        visual->champ_win[3] = newwin(10, 60, 33, 66 + 62 * 2);
}

void init_visual(visual_t *visual, unsigned short champ_count)
{
    visual->mem_pos = (pos_t){14, 9};
    visual->line_len = 82;
    init_right_boxes(visual, champ_count);
    noecho();
    curs_set(0);
    keypad(visual->win, TRUE);
    nodelay(visual->win, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    visual->pause = true;
    visual->step_forward = false;
    visual->cycle_per_second = 1000;
    visual->last_cycle = clock();
    visual->viewed_process_id = 0;
    visual->detailed_view = false;
    visual->mem_spacing = 2;
    init_colors();
}
