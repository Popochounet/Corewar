/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** processes
*/

#pragma once

    #include "struct.h"

void add_process(process_t **processes, process_t *process);
int count_champ_processes(process_t *process, int champ_id);
int get_processes_count(process_t *process);
