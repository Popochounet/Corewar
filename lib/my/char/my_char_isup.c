/*
** EPITECH PROJECT, 2022
** my_char_isup
** File description:
** check if a given str only contains small alphabetical characters
*/

#include <stdbool.h>

bool my_char_isup(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}
