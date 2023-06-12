/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** add_command_body
*/

#include "asm.h"

char *add_coding_byte(body_t *str, str_list_t *list, op_t op_list)
{
    unsigned char coding_bytes = '\0';
    char registers = 1 << 6;
    unsigned char direct = 1 << 7;
    unsigned char indirect = 3 << 6;

    if (!op_list.need_coding_byte)
        return str->str;
    for (int j = op_list.nbr_args; j > 0; j--) {
        coding_bytes >>= 2;
        if (list->array[j][0] == 'r')
            coding_bytes |= registers;
        if (list->array[j][0] == DIRECT_CHAR)
            coding_bytes |= direct;
        if (list->array[j][0] != DIRECT_CHAR && list->array[j][0] != 'r')
            coding_bytes |= indirect;
    }
    return my_strcat_body(str,(char *) &coding_bytes, 1, 1);
}

int is_label(labels_t **label, str_list_t *list, body_t *str, char *str_label)
{
    int i = 1;
    labels_t *ele = malloc(sizeof(labels_t));

    ele->label = my_strdup(str_label);
    ele->pos_label = str->pos;
    free(list->array[0]);
    for (; list->array[i]; i++)
        list->array[i - 1] = list->array[i];
    list->array[i - 1] = NULL;
    ele->next = *label;
    *label = ele;
    if (!list->array[0])
        return -1;
    for (i = 0; op_tab[i].mnemonique &&
        my_strcmp(op_tab[i].mnemonique, list->array[0]); i++);
    if (!op_tab[i].mnemonique)
        exit(84);
    return i;
}

body_t add_head(body_t str, labels_t **labels_ref, str_list_t **list, int *i)
{
    if (!op_tab[*i].mnemonique)
        *i = is_label(labels_ref, *list, &str, (*list)->array[0]);
    if (*i == -1) {
        *list = (*list)->next;
        return str;
    }
    str.str = my_strcat_body(&str, &op_tab[*i].code, 1, 1);
    str.cmd_name = my_strdup(op_tab[*i].mnemonique);
    str.starting_cmd_pos = str.pos - 1;
    str.str = add_coding_byte(&str, *list, op_tab[*i]);
    return str;
}

body_t add_command_body(str_list_t *list, labels_t **l1, labels_t **l2)
{
    body_t str;
    labels_t *labels = *l1;
    labels_t *labels_ref = *l2;

    str.str = malloc(sizeof(char));
    str.str[0] = '\0';
    str.pos = 0;
    for (int i = 0; list; i = 0) {
        for (; op_tab[i].mnemonique &&
        my_strcmp(op_tab[i].mnemonique, list->array[0]); i++);
        str = add_head(str, &labels_ref, &list, &i);
        if (i == -1)
            continue;
        add_directives(&str, list, op_tab[i], &labels);
        free(str.cmd_name);
        list = list->next;
    }
    *l1 = labels;
    *l2 = labels_ref;
    return str;
}
