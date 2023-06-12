/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** check if a given str only contains alphabetical characters
*/

#include "my.h"

bool my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isnum(str[i])) {
            return false;
        }
    }
    return true;
}
