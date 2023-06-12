/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** a short file description
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int char_is_alpha_num(char c)
{
    if ((c >= 48) && (c <= 57))
        return 1;
    if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
        return 1;
    return 0;
}

int my_word_len(char const *str, int ind_string, char *separator)
{
    int i = ind_string;
    int occ = 0;

    while (str[i] != '\0' && !is_separator(str[i], separator)) {
        i++;
        occ++;
    }
    return occ;
}

char **my_str_to_word_array_sep(char *str, char *separator)
{
    int word_len = 0;
    char **array;
    int ind_string = 0;
    int nb_word;

    nb_word = count_word(str, separator);
    if (*str == '\0' || *str == '\n' || nb_word == 0)
        return NULL;
    array = malloc(sizeof(char *) * (nb_word + 1));
    for (int i = 0; i < nb_word; i++) {
        while (is_separator(str[ind_string], separator))
            ind_string++;
        word_len = my_word_len(str, ind_string, separator);
        array[i] = malloc(sizeof(char) * (word_len + 1));
        array[i][word_len] = '\0';
        my_strcpypart(array[i], str, ind_string, ind_string + word_len);
        ind_string += word_len;
    }
    array[nb_word] = NULL;
    return array;
}
