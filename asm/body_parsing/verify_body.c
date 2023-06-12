/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** verify_body
*/

#include "asm.h"

void check_register(int reg)
{
    if (!(reg > 0 && reg <= REG_NUMBER))
        exit(84);
}

int check_label_char(char *label)
{
    int j = 0;
    char *valid_char = DIRECT_CHARS;

    for (int i = 0; i < my_strlen(label); i++) {
        for (j = 0; valid_char[j] && valid_char[j] != label[i]; j++);
        if (valid_char[i] != label[i])
            return 0;
    }
    return 1;
}
