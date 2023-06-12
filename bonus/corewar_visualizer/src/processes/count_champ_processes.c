/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** count_champ_processes
*/

#include "struct.h"

int count_champ_processes(process_t *process, int champ_id)
{
    int count = 0;

    for (; process; process = process->next) {
        if (process->champ_id == champ_id)
            count++;
    }
    return count;
}
