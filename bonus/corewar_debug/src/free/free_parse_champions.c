/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** free_parse_champions
*/

#include "free.h"

void free_parse_champions(parse_champion_t *parse_champion)
{
    if (parse_champion == NULL)
        return;
    free_parse_champions(parse_champion->next);
    free(parse_champion);
}
