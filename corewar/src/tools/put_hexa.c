/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** put_hexa_base_2
*/

#include <stdlib.h>
#include "tools.h"

void put_hexa(unsigned char nbr)
{
    char *hexa = my_convert_base(nbr, 16, true);

    if (my_strlen(hexa) < 2)
        my_putchar('0');
    my_putstr(hexa);
    free(hexa);
}
