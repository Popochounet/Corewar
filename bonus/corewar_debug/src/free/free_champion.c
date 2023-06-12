/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** free_champion
*/

#include "free.h"

void free_champion(champion_t **champion, int champion_count)
{
    if (champion == NULL)
        return;
    for (int i = 0; i < champion_count; i++) {
        if (champion[i] == NULL)
            continue;
        free(champion[i]->name);
        free(champion[i]->comment);
        free(champion[i]->body);
        free(champion[i]);
    }
    free(champion);
}
