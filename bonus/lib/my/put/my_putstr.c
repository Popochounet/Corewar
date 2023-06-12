/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displays the characters of a string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}
