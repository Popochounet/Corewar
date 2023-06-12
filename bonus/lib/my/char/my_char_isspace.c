/*
** EPITECH PROJECT, 2023
** my_char_isspace
** File description:
** return true if a char is a space, a new line or a tab
*/

#include <stdbool.h>

//return true if a char is a space, a new line or a tab
bool my_char_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\n'
    || c == '\f')
        return true;
    return false;
}
