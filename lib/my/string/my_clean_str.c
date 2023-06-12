/*
** EPITECH PROJECT, 2023
** MiniShell1
** File description:
** my_clean_str
*/

#include "my.h"

void my_clean_str(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        for (; my_char_isspace(str[i]); i++);
        if (my_char_isspace(str[i]))
            continue;
        if (i > 0 && j > 0 && my_char_isspace(str[i - 1]))
            str[j++] = ' ';
        str[j++] = str[i++];
    }
    if (j > 0 && my_char_isspace(str[j - 1]))
        str[j - 1] = '\0';
    else
        str[j] = '\0';
}
