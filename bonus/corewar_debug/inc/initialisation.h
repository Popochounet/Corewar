/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** initialisation.h
*/

#pragma once

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include "visual.h"
    #include "struct.h"

    #define DUMP_INDEX_ERROR -1
    #define DUMP_INDEX_NOT_FOUND -2

typedef union char_s {
    char nb_int;
    char buffer[1];
} char_t;

typedef union short_s {
    short nb_int;
    char buffer[2];
} short_t;

typedef union integer_s {
    int nb_int;
    char buffer[4];
} integer_t;

int init_corewar(corewar_t *corewar, visual_t *visual, int ac,
char **av);
int get_dump(corewar_t *corewar, int ac, char **av);
champion_t *read_champion(parse_champion_t *p_champ);
int get_champions(corewar_t *corewar, int ac, char **av);
int parse_args(corewar_t *corewar, int ac, char **av);
int load_champions(corewar_t *corewar, visual_t *visual);
parse_champion_t *get_parse_champion(parse_champion_t *parse_champion, int ac,
char **av, int *i);
void create_first_processes(corewar_t *corewar);
