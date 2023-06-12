/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** read_champion
*/

#include "initialisation.h"
#include <fcntl.h>

static int my_read_int(FILE *fd)
{
    char nb_buffer[4];
    integer_t int_union;

    fread(nb_buffer, sizeof(int), 1, fd);
    for (int i = 0; i < 4; i++)
        int_union.buffer[i] = nb_buffer[3 - i];
    return int_union.nb_int;
}

static int is_path_folder(const char *path)
{
    int fd = open(path, O_RDONLY | O_DIRECTORY);

    if (fd != -1) {
        close(fd);
        return 1;
    }
    return 0;
}

champion_t *read_champion(parse_champion_t *p_champ)
{
    champion_t *champion;
    FILE *champ = fopen(p_champ->path, "r");

    if (!p_champ->path || !champ || is_path_folder(p_champ->path))
        return NULL;
    champion = malloc(sizeof(champion_t));
    champion->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 4));
    champion->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 4));
    my_read_int(champ);
    fread(champion->name, sizeof(char), PROG_NAME_LENGTH + 4, champ);
    champion->size = my_read_int(champ);
    fread(champion->comment, sizeof(char), COMMENT_LENGTH + 4, champ);
    champion->body = malloc(sizeof(char) * (champion->size + 1));
    fread(champion->body, sizeof(char), champion->size, champ);
    champion->id = p_champ->id;
    champion->load_address = p_champ->load_address;
    champion->alive = true;
    champion->saying_live = false;
    champion->cycle_before_die = CYCLE_TO_DIE;
    return champion;
}
