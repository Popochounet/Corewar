/*
** EPITECH PROJECT, 2022
** my_char_isalpha
** File description:
** check if a given char is alphabetical
*/

#include <stdbool.h>

//return true is a char is between 'A' and 'Z' or 'a' and 'z'.
bool my_char_isalpha(char const c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return true;
    return false;
}
