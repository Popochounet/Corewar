/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** logic.c
*/

#include "war.h"
#include "instruction.h"

int add(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];

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
    current->reg[args[2].value - 1] = args[0].value + args[1].value;
    return 1;
}

int sub(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];

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
    current->reg[args[2].value - 1] = args[0].value - args[1].value;
    return 1;
}

int and_binary(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];

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
    current->reg[args[2].value - 1] = args[0].value & args[1].value;
    return 1;
}

int or_binary(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];

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
    current->reg[args[2].value - 1] = args[0].value | args[1].value;
    return 1;
}

int xor_binary(process_t *current, int pc, corewar_t *corewar)
{
    argument_t args[MAX_ARGS_NUMBER];

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
    current->reg[args[2].value - 1] = args[0].value ^ args[1].value;
    return 1;
}
