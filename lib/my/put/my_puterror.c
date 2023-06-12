/*
** EPITECH PROJECT, 2022
** my_puterror
** File description:
** print a string on the error output
*/

#include "my.h"
#include <unistd.h>

int my_puterror(char const *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return len;
}
