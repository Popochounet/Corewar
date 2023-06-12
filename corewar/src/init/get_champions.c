/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_champions
*/

#include "initialisation.h"
#include "tools.h"

static void append_parse_champion(parse_champion_t **list,
parse_champion_t *parse_champion)
{
    parse_champion_t *tmp = *list;

    if (tmp == NULL) {
        *list = parse_champion;
        return;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = parse_champion;
}

int get_champions(corewar_t *corewar, int ac, char **av)
{
    parse_champion_t *parse_champion = NULL;

    for (int i = 0; i < ac - 1; i++) {
        if (i + 1 == corewar->dump_index) {
            i++;
            continue;
        }
        parse_champion = malloc(sizeof(parse_champion_t));
        parse_champion->load_address = -1;
        parse_champion->next = NULL;
        get_parse_champion(parse_champion, ac, av, &i);
        if (parse_champion == NULL)
            return 84;
        append_parse_champion(&corewar->parse_champions, parse_champion);
    }
    return 0;
}
