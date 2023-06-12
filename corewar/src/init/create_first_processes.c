/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** create_first_processes
*/

#include "initialisation.h"
#include "processes.h"

void create_first_processes(corewar_t *corewar)
{
    process_t *process;

    for (int i = 0, inst; i < corewar->champion_count; i++) {
        process = malloc(sizeof(process_t));
        process->pc = corewar->champions[i]->load_address;
        process->carry = 1;
        process->reg[0] = corewar->champions[i]->id;
        for (int j = 1; j < REG_NUMBER; j++)
            process->reg[j] = 0;
        process->next = NULL;
        process->champ_id = corewar->champions[i]->id;
        inst = corewar->memory[process->pc];
        inst = !inst || inst >= NB_OP ? NB_OP : inst - 1;
        process->op = op_tab[inst];
        process->wait = process->op.nbr_cycles - 1;
        process->carry = 1;
        add_process(&corewar->processes, process);
    }
}
