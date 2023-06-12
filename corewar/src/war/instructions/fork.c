/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** fork.c
*/

#include "instruction.h"
#include "processes.h"
#include <stdlib.h>

int fork_inst(process_t *current, int pc, corewar_t *corewar)
{
    int index = read_mem(corewar->memory, &current->pc, IND_SIZE);
    process_t *new = malloc(sizeof(process_t));
    int inst;

    new->champ_id = current->champ_id;
    for (int i = 0; i < REG_NUMBER; i++)
        new->reg[i] = current->reg[i];
    new->carry = current->carry;
    new->pc = (MEM_SIZE + pc + index % IDX_MOD) % MEM_SIZE;
    new->next = NULL;
    inst = corewar->memory[new->pc];
    inst = !inst || inst >= NB_OP ? NB_OP : inst - 1;
    new->op = op_tab[inst];
    new->wait = new->op.nbr_cycles;
    add_process(&corewar->processes, new);
    return current->carry;
}

int lfork(process_t *current, int pc, corewar_t *corewar)
{
    int index = read_mem(corewar->memory, &current->pc, IND_SIZE);
    process_t *new = malloc(sizeof(process_t));
    int inst;

    new->champ_id = current->champ_id;
    for (int i = 0; i < REG_NUMBER; i++)
        new->reg[i] = current->reg[i];
    new->carry = current->carry;
    new->pc = (MEM_SIZE + pc + index) % MEM_SIZE;
    new->next = NULL;
    inst = corewar->memory[new->pc];
    inst = !inst || inst >= NB_OP ? NB_OP : inst - 1;
    new->op = op_tab[inst];
    new->wait = new->op.nbr_cycles;
    add_process(&corewar->processes, new);
    return current->carry;
}
