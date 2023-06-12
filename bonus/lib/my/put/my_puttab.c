/*
** EPITECH PROJECT, 2022
** my_puttab
** File description:
** displays char **
*/

#include "my.h"
#include <stdio.h>

void my_puttab(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
