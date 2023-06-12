/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** different_sexion
*/

#include "asm.h"

labels_t *add_new_label(char *nbr, labels_t **label, body_t *str, int size)
{
    labels_t *ele = malloc(sizeof(labels_t));
    int i = 0;

    for (; my_strcmp(op_tab[i].mnemonique, str->cmd_name); i++);
    ele->size = (size == 2) ? 1 : 0;
    ele->pos_cmd = str->starting_cmd_pos;
    ele->pos_label = str->pos;
    ele->label = my_strcatdup(nbr, ":");
    ele->next = *label;
    return ele;
}

int wrong_index(op_t tab, char *str, int i)
{
    if (str[0] == 'r')
        if (tab.type[i - 1] & T_REG)
            return 1;
    if (str[0] == DIRECT_CHAR)
        if (tab.type[i - 1] & T_DIR)
            return 1;
    if (tab.type[i - 1] & T_IND)
        return 1;
    return 0;
}

char *direct_indirect_number(body_t *new_str, char *nbr, labels_t **labels, int
size_param)
{
    unsigned int ref = 0;
    char ref_char[size_param];

    ref_char[size_param - 1] = '\0';
    if (nbr[0] != ':' && !my_char_isnum(nbr[0]) && nbr[0] != '-')
        exit(84);
    if (nbr[0] == ':')
        *labels = add_new_label(&nbr[1], labels, new_str, size_param);
    else
        ref = my_getnbr(&nbr[0]);
    for (int i = size_param - 1; i >= 0; i--) {
        ref_char[i] = ref;
        ref >>= 8;
    }
    return my_strcat_body(new_str, ref_char, 1, size_param);
}

void add_directives(body_t *str, str_list_t *list, op_t tab, labels_t **lab)
{
    int i = 1;

    for (char nbr = 0; tab.nbr_args >= i; i++) {
        if (!list->array[i] || !wrong_index(tab, list->array[i], i))
            exit(84);
        if (list->array[i][0] == 'r') {
            nbr = my_getnbr(&list->array[i][1]);
            check_register(nbr);
            str->str = my_strcat_body(str, &nbr, 1, 1);
            continue;
        }
        if (list->array[i][0] == DIRECT_CHAR) {
            str->str = direct_indirect_number(str, &list->array[i][1], lab,
                (tab.is_index) ? IND_SIZE : DIR_SIZE);
            continue;
        }
        str->str = direct_indirect_number(str, list->array[i],lab, IND_SIZE);
    }
    if (list->array[i])
        exit(84);
}
