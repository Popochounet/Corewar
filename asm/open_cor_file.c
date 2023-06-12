/*
** EPITECH PROJECT, 2022
** little_to_big
** File description:
** a short file description
*/

#include "asm.h"

FILE *open_cor_file(char *file)
{
    int len = my_strlen(file);
    char *cor_file;
    FILE *champion_cor;

    if (file[len - 2] != '.' && file[len - 1] != 's')
        return NULL;
    cor_file = malloc(sizeof(char) * (len + 3));
    my_strncpy(cor_file, file, len - 2);
    my_strcat(cor_file, ".cor");
    champion_cor = fopen(cor_file, "w");
    free(cor_file);
    return champion_cor;
}
