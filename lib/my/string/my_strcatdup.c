/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** my_strcatdup
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcatdup(char *before, char *after)
{
    int size_be = my_strlen(before);
    int size_af = my_strlen(after);
    char *str = malloc(sizeof(char) * (size_be + size_af + 1));

    for (int i = 0; i < size_be; i++)
        str[i] = before[i];
    for (int i = 0; i < size_af; i++)
        str[size_be + i] = after[i];
    str[size_be + size_af] = '\0';
    return str;
}
