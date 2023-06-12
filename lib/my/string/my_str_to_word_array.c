/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** takes a str and return a tab of all the words in it
*/

#include "my.h"
#include <stdlib.h>

static int count_words(char const *str)
{
    int word_count = str[0] != '\0' ? 1 : 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isspace(str[i]))
            word_count++;
    }
    return word_count;
}

static void insert_word(char **tab, int word_count, int word_size, char *str)
{
    tab[word_count] = malloc(sizeof(char) * (word_size + 1));
    my_strncpy(tab[word_count], str, word_size);
}

char **my_str_to_word_array(char const *src)
{
    char *str = my_strdup(src);
    my_clean_str(str);
    int tab_len = count_words(str);
    char **tab = malloc(sizeof(char *) * (tab_len + 1));
    int word_count = 0;
    int word_size = 0;
    int i = 0;

    for (; str[i] != '\0'; i++, word_size++) {
        if (my_char_isspace(str[i])) {
            insert_word(tab, word_count, word_size, str + i - word_size);
            word_count++;
            word_size = 0;
            i++;
        }
    }
    insert_word(tab, word_count, word_size, str + i - word_size);
    tab[tab_len] = NULL;
    free(str);
    return tab;
}
