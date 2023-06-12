/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_parse_champion
*/

#include "initialisation.h"
#include "tools.h"

parse_champion_t *get_parse_champion(parse_champion_t *parse_champion, int ac,
char **av, int *i)
{
    char *load_address = NULL;
    char *id_flag = NULL;
    static int id = 0;
    int move_index = 0;

    parse_champion->id = id;
    load_address = parse_flag(ac, av, "-a", (*i) + 1);
    id_flag = parse_flag(ac, av, "-n", (*i) + 1);
    if (load_address) {
        parse_champion->load_address = my_getnbr(load_address);
        move_index += 2;
    } if (id_flag) {
        parse_champion->id = my_getnbr(id_flag);
        move_index += 2;
    } else {
        id++;
    }
    (*i) += move_index;
    parse_champion->path = av[*i + 1];
    return parse_champion;
}
