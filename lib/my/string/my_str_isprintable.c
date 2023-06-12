/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** check if a given str only contains printable characters
*/

#include <stdbool.h>

bool my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126)
            return false;
    }
    return true;
}
