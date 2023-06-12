/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** body_parse
*/

#include "asm.h"

void put_adress(labels_t *labels, labels_t *labels_ref, int pos, body_t *str)
{
    if (!my_strcmp(labels->label, labels_ref->label)) {
        for (int i = 3 - 2 * labels->size; i >= 0; i--) {
            str->str[labels->pos_label + i] = (char) pos;
            pos >>= 8;
        }
    }
}

static void new_ele_str(str_list_t **o_list, char *str)
{
    str_list_t *ele = malloc(sizeof(str_list_t));
    ele->array = clean_array(str);
    str_list_t *list = *o_list;

    if (!ele->array) {
        free(ele);
        return;
    }
    if (!list) {
        ele->next = list;
        *o_list = ele;
        return;
    }
    while (list->next)
        list = list->next;
    ele->next = list->next;
    list->next = ele;
}

static str_list_t *str_constructor(FILE *champion)
{
    int i = 0;
    str_list_t *list = NULL;
    char *str = NULL;
    size_t csize;

    for (; getline(&str, &csize, champion) != -1; i++) {
        new_ele_str(&list, str);
    }
    free(str);
    return list;
}

void add_labels(labels_t *labels, labels_t *labels_ref, body_t *str)
{
    labels_t *temp = labels;

    while (labels_ref) {
        if (check_label_char(labels_ref->label))
            exit(84);
        labels = temp;
            while (labels) {
                put_adress(labels, labels_ref, labels_ref->pos_label -
                    labels->pos_cmd, str);
                labels = labels->next;
            }
            labels_ref = labels_ref->next;
        }
}

body_t body_parse(FILE *champion)
{
    body_t str;
    str_list_t *list = str_constructor(champion);
    labels_t *labels = NULL;
    labels_t *labels_ref = NULL;

    str = add_command_body(list, &labels, &labels_ref);
    add_labels(labels, labels_ref, &str);
    free_str_construction(list);
    free_labels(labels);
    free_labels(labels_ref);
    return str;
}
