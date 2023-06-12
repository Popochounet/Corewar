/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#pragma once

    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>

    #include "my.h"
    #include "visual.h"
    #include "struct.h"

void war_loop(corewar_t *corewar, visual_t *visual);
void dump_memory(mem_t memory);
void put_winner(corewar_t *corewar);
