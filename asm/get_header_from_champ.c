/*
** EPITECH PROJECT, 2022
** little_to_big
** File description:
** a short file description
*/

#include "asm.h"

static header_t init_header(void)
{
    header_t header = {0};

    header.magic = COREWAR_EXEC_MAGIC;
    header.prog_size = 0;
    return header;
}

header_t get_header_from_champ(FILE *champion)
{
    char *line = NULL;
    header_t header = init_header();
    int prog_name = 0;
    int comment = 0;
    size_t size;

    while ((!comment || !prog_name) &&
        getline(&line, &size, champion) != -1) {
        if (line[0] == '#' || line[0] == '\n')
            continue;
        if (!valid_cmd(line, &header, &comment, &prog_name))
            exit(84);
    }
    free(line);
    if (!comment || !prog_name)
        exit(84);
    return header;
}
