/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** args.c
*/

#include "war.h"

int get_size(argument_t args, bool index)
{
    switch (args.type) {
    case T_REG: return 1;
    case T_DIR: return index ? IND_SIZE : DIR_SIZE;
    case T_IND: return IND_SIZE;
    default: break;
    }
    return 0;
}

int get_args(process_t *current, mem_t memory,
    argument_t args[][MAX_ARGS_NUMBER])
{
    int coding_byte_pc = current->pc;
    int err = 0;
    unsigned char arg_byte;
    current->pc = (current->pc + 1) % MEM_SIZE;
    for (int i = 0; i < current->op.nbr_args; i++) {
        arg_byte = memory[coding_byte_pc];
        arg_byte <<= 2 * i;
        arg_byte >>= 6;
        if (arg_byte == 3)
            arg_byte = T_IND;
        (*args)[i].type = arg_byte;
        (*args)[i].value = read_mem(memory, &current->pc,
            get_size((*args)[i], current->op.is_index));
        if ((*args)[i].type == T_REG &&
            (!(*args)[i].value || (*args)[i].value > 16))
            err = 1;
    }
    return err;
}

bool is_coding_byte_valid(char byte, op_t op)
{
    unsigned char test_byte;
    for (int i = 0; i < 4; i++) {
        test_byte = byte;
        test_byte <<= 2 * i;
        test_byte >>= 6;
        if (op.nbr_args < i + 1 && test_byte)
            return false;
        if (test_byte == 3)
            test_byte = T_IND;
        if (i < op.nbr_args && !(op.type[i] & test_byte))
            return false;
    }
    return true;
}
