/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** lowercase a string
*/

#include "my.h"

char *my_strlowcase(char const *str)
{
    char *tmp = my_strdup(str);
    int i = 0;

    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            tmp[i] = tmp[i] + 32;
    }
    return tmp;
}
