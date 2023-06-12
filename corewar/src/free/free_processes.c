/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** free_processes.c
*/

#include "free.h"

void free_processes(process_t *process)
{
    process_t *next = NULL;

    if (!process)
        return;

    for (; process != NULL; process = next) {
        next = process->next;
        free(process);
    }
}
