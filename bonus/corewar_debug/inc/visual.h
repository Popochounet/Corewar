/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** visual
*/

#pragma once

    #include "struct.h"
    #include <ncurses.h>
    #include <time.h>

    #define VISUAL_NONE 0
    #define VISUAL_PAUSE 1
    #define VISUAL_EXIT -1

    #define MAX_CHAMP_COUNT 4
    #define HEADER_HEIGHT 7
    #define CHAMP_BOX_HEIGHT 13
    #define PROCESS_BOX_HEIGHT 12
    #define BOX_WIDTH 60

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct visual {
    WINDOW *win;
    WINDOW *header;
    WINDOW *champ_win[4];
    WINDOW *process_win;
    int key;
    pos_t mem_pos;
    int line_len;
    mem_t mem_color;
    bool pause;
    bool step_forward;
    float cycle_per_second;
    clock_t last_cycle;
    int viewed_process_id;
} visual_t;

void init_visual(visual_t *visual, unsigned short champ_count);
void put_hexa_curse(WINDOW *win, int nbr, int x, int y);
int handle_visual(corewar_t *corewar, visual_t *visual);
void draw_screen(corewar_t *corewar, visual_t *visual);
void draw_mem(corewar_t *corewar, visual_t *visual);
bool key_handler(visual_t *visual, corewar_t *corewar);
void free_visual(visual_t *visual);
void draw_skull(WINDOW *win, int x, int y);
