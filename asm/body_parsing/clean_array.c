/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** clean_array
*/

#include "asm.h"

char **clean_array(char *str)
{
    char **array;
    int i = 0;

    for (; str[i] && str[i] != COMMENT_CHAR; i++);
    str[i] = '\0';
    array = my_str_to_word_array_sep(str, " ,\t\n");
    return array;
}
