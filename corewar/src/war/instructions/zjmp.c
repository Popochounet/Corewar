/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** zjmp.c
*/

#include "instruction.h"

int zjmp(process_t *current, int pc, corewar_t *corewar)
{
    int index = read_mem(corewar->memory, &current->pc, T_DIR);

    if (current->carry)
        current->pc = (MEM_SIZE + pc + index % IDX_MOD) % MEM_SIZE;
    else
        current->pc++;
    return current->carry;
}
