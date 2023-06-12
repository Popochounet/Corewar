/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** war.h
*/

#pragma once

    #include <stdio.h>
    #include "struct.h"
    #include "tools.h"
    #include "corewar.h"

int get_args(process_t *current, mem_t memory,
    argument_t args[][MAX_ARGS_NUMBER]);
int read_mem(mem_t mem, int *idx, int size);
bool is_coding_byte_valid(char byte, op_t op);

int check_win(champion_t **champions, int nb_champ);
void war_check(corewar_t *corewar);
