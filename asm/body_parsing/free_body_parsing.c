/*
** EPITECH PROJECT, 2023
** B_CPE_200_LYN_2_1_corewar_adrien_audiard
** File description:
** free_body_parsing
*/

#include "asm.h"

void free_labels(labels_t *labels)
{
    if (!labels)
        return;
    free_labels(labels->next);
    if (labels->label)
        free(labels->label);
    free(labels);
}

void free_str_construction(str_list_t *list)
{
    if (!list)
        return;
    free_str_construction(list->next);
    for (int i = 0; list->array[i]; i++)
        free(list->array[i]);
    free(list->array);
    free(list);
}
