/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** add_process
*/

#include "struct.h"
#include <stdlib.h>

void add_process(process_t **processes, process_t *process)
{
    process_t *tmp = *processes;

    if (tmp == NULL) {
        *processes = process;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = process;
}
