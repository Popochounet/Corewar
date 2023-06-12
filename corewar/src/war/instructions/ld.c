/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** ld.c
*/

#include "war.h"
#include "instruction.h"

int load(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];
    int idx;

    if (get_args(current, corewar->memory, &args))
        return 0;
    if (args[0].type == T_REG)
        args[0].value = current->reg[args[0].value - 1];
    if (args[0].type == T_IND) {
        idx = (pc + args[0].value % IDX_MOD) % MEM_SIZE;
        args[0].value = read_mem(corewar->memory, &idx, REG_SIZE);
    }
    current->reg[args[1].value - 1] = args[0].value;
    return 1;
}

int lld(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];
    int idx;

    if (get_args(current, corewar->memory, &args))
        return 0;
    if (args[0].type == T_REG)
        args[0].value = current->reg[args[0].value - 1];
    if (args[0].type == T_IND) {
        idx = (pc + args[0].value) % MEM_SIZE;
        args[0].value = read_mem(corewar->memory, &idx, REG_SIZE);
    }
    current->reg[args[1].value - 1] = args[0].value;
    return 1;
}

int ldi(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];
    int sum;

    if (get_args(current, corewar->memory, &args))
        return 0;
    for (int i = 0, idx; i < 2; i++) {
        if (args[i].type == T_REG)
            args[i].value = current->reg[args[i].value - 1];
        if (args[i].type == T_IND) {
            idx = (pc + args[i].value % IDX_MOD) % MEM_SIZE;
            args[i].value = read_mem(corewar->memory, &idx, IND_SIZE);
        }
    }
    sum = (pc + (args[0].value + args[1].value) % IDX_MOD) % MEM_SIZE;
    current->reg[args[2].value - 1] = read_mem(corewar->memory, &sum, REG_SIZE);
    return 1;
}

int lldi(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];
    int sum;

    if (get_args(current, corewar->memory, &args))
        return 0;
    for (int i = 0, idx; i < 2; i++) {
        if (args[i].type == T_REG)
            args[i].value = current->reg[args[i].value - 1];
        if (args[i].type == T_IND) {
            idx = (pc + args[i].value) % MEM_SIZE;
            args[i].value = read_mem(corewar->memory, &idx, IND_SIZE);
        }
    }
    sum = (pc + (args[0].value + args[1].value)) % MEM_SIZE;
    current->reg[args[2].value - 1] = read_mem(corewar->memory, &sum, REG_SIZE);
    return 1;
}
