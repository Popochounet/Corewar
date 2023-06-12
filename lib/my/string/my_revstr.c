/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** swap each character in a string, it reverses it
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);

    for (int i = 0; i < str_len / 2; i++)
        my_swapchar(&str[i], &str[str_len - 1 - i]);
    return str;
}
