/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** aff.c
*/

#include "instruction.h"

int aff(process_t *current, corewar_t *corewar)
{
    int ascii = read_mem(corewar->memory, &current->pc, T_REG);
    my_putchar(ascii % 256);
    return current->carry;
}
