/*
** EPITECH PROJECT, 2022
** my_char_isnum
** File description:
** check if a given str only contains alphabetical characters
*/

#include <stdbool.h>

bool my_char_isnum(char const c)
{
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
