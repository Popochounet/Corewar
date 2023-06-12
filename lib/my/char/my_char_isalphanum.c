/*
** EPITECH PROJECT, 2022
** my_char_isalphanum
** File description:
** check if a given char is alphabetical or number
*/

#include <stdbool.h>

bool my_char_isalphanum(char const c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9'))
        return true;
    return false;
}
