/*
** EPITECH PROJECT, 2022
** main
** File description:
** a short file description
*/

#include "asm.h"

static FILE *verif_args(int ac, char **av)
{
    FILE *champion;

    if (ac != 2)
        exit(84);
    if (my_strcmp(av[1], "-h") == 0) {
        disp_usage();
        exit(0);
    }
    champion = fopen(av[1], "r");
    if (champion == NULL)
        exit(84);
    return champion;
}

void write_and_close(header_t header, body_t body, FILE *champion,
FILE *champion_cor)
{
    fwrite(&header, sizeof(header), 1, champion_cor);
    fwrite(body.str, sizeof(char), body.pos, champion_cor);
    free(body.str);
    fclose(champion);
    fclose(champion_cor);
}

int main(int ac, char **av)
{
    FILE *champion = verif_args(ac, av);
    FILE *champion_cor;
    header_t header;
    body_t body;

    header = get_header_from_champ(champion);
    header.magic = little_to_big_endian(header.magic);
    body = body_parse(champion);
    header.prog_size = little_to_big_endian(body.pos);
    champion_cor = open_cor_file(av[1]);
    if (champion_cor == NULL) {
        fclose(champion);
        return (84);
    }
    write_and_close(header, body, champion, champion_cor);
    return (0);
}
