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

static void init_right_boxes(visual_t *visual, unsigned short champ_count)
{
    int x_offset = visual->line_len * 3 + 3;
    visual->win = initscr();
    visual->header = newwin(HEADER_HEIGHT, BOX_WIDTH, 1, x_offset);
    visual->process_win = newwin(PROCESS_BOX_HEIGHT, BOX_WIDTH,
        HEADER_HEIGHT + 2, x_offset);
    for (int i = 0; i < champ_count && i < MAX_CHAMP_COUNT; i++)
        visual->champ_win[i] = newwin(CHAMP_BOX_HEIGHT, BOX_WIDTH,
            HEADER_HEIGHT + PROCESS_BOX_HEIGHT + 3 + CHAMP_BOX_HEIGHT * i,
            x_offset);
}

void init_visual(visual_t *visual, unsigned short champ_count)
{
    visual->mem_pos = (pos_t){1, 0};
    visual->line_len = 82;
    init_right_boxes(visual, champ_count);
    noecho();
    curs_set(0);
    keypad(visual->win, TRUE);
    nodelay(visual->win, TRUE);
    visual->pause = true;
    visual->step_forward = false;
    visual->cycle_per_second = 1000;
    visual->last_cycle = clock();
    visual->viewed_process_id = 0;
    init_colors();
}
