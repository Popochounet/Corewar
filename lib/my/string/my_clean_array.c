/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** my_clean_array
*/

#include <stdlib.h>

int my_strlen(char *str);
char *my_strndup(char *str, int size);

static int is_a_delim(char c, char *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return 1;
    return 0;
}

char **my_clean_array(char **array, char *delim)
{
    int i;
    int size;
    void *temp;

    for (int j = 0; array[j]; j++) {
        for (i = 0; array[j][i] && is_a_delim(array[j][i], delim); i++);
        for (size = my_strlen(array[j]) - 1; size > i &&
        is_a_delim(array[j][size], delim); size--);
        temp = array[j];
        array[j] = my_strndup(&array[j][i], i - size);
        free(temp);
    }
    return array;
}
