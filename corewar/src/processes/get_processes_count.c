/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_processes_count
*/

#include "struct.h"

int get_processes_count(process_t *process)
{
    int count = 0;

    for (; process; process = process->next)
        count++;
    return count;
}
