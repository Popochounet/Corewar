/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concentrate two strings in one, if free_args = 0, no free, 1 dest, 2 sec, all
*/

#include <stdlib.h>
#include "asm.h"

char *my_strcat_body(body_t *dest, char *src, int free_args, int size)
{
    int i = dest->pos;
    char *str = malloc(sizeof(char) * (size + i));
    int k = 0;

    dest->pos += size;
    for (; k < i; k++)
        str[k] = dest->str[k];
    for (k = 0; k < size; k++) {
        str[i + k] = src[k];
    }
    switch (free_args) {
        case 1: free(dest->str); break;
        case 2: free(src); break;
        case 3: free(dest->str);
            free(src);
            break;
        default: break;
    };
    return str;
}
