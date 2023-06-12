/*
** EPITECH PROJECT, 2022
** my_tablen
** File description:
** count the number of element in a tab
*/

#include <stdlib.h>

int my_tablen(char *const *tab)
{
    int len = 0;

    for (; tab[len] != NULL; len++);
    return len;
}
