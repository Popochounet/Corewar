/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** free.h
*/

#pragma once

    #include <stdlib.h>

    #include "struct.h"

void free_champion(champion_t **champion, int champion_count);
void free_corewar(corewar_t *corewar);
void free_processes(process_t *process);
void free_parse_champions(parse_champion_t *parse_champion);
