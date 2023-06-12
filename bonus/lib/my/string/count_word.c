/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-samuel.bruschet
** File description:
** a short file description
*/

#include "my.h"

static void verif_separation(int *separator, int *count_word)
{
    if (*separator == 1) {
        *count_word += 1;
        *separator = 0;
    }
}

int count_word(char const *str, char *separator)
{
    int separator_int = 1;
    int count_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_separator(str[i], separator))
            verif_separation(&separator_int, &count_word);
        else
            separator_int = 1;
    }
    return count_word;
}
