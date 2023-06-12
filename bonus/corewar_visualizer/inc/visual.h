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
    #define CHAMP_BOX_HEIGHT 13
    #define WIDTH_MEM 72
    #define HEIGHT_MEM 32

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct visual {
    WINDOW *win;
    WINDOW *game_info_win;
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
    int mem_spacing;
    bool detailed_view;
} visual_t;

void init_visual(visual_t *visual, unsigned short champ_count);
int get_color(int id);
pos_t get_pos_mem(int i, pos_t offset, int spacing);
void put_hexa_curse(WINDOW *win, int nbr, pos_t pos);
int handle_visual(corewar_t *corewar, visual_t *visual);
void draw_screen(corewar_t *corewar, visual_t *visual);
void draw_mem(corewar_t *corewar, visual_t *visual);
bool key_handler(visual_t *visual, corewar_t *corewar);
void free_visual(visual_t *visual);
void draw_line(WINDOW *win, int x, int *y, char *str);
void draw_skull(WINDOW *win, int x, int y);
void draw_title(WINDOW *win, int x, int y);
void draw_crown(WINDOW *win, int x, int y);
void draw_game_info(WINDOW *win, corewar_t *corewar, visual_t *visual);
void draw_process_box(WINDOW *win, process_t *process, corewar_t *corewar,
visual_t *visual);
void draw_champ_box(WINDOW *win, champion_t *champion, process_t *processes,
visual_t *visual);

char *convert_to_hexa(int number);
