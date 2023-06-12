/*
** EPITECH PROJECT, 2022
** my_freetab
** File description:
** free all char **
*/

#include <stdlib.h>

void my_freetab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
