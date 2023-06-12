/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** war_loop.c
*/

#include "war.h"
#include "my.h"
#include "instruction.h"

int switch_instruction(process_t *process, int pc, corewar_t *corewar)
{
    switch (process->op.code) {
        case LIVE: return live(process, corewar);
        case LD: return load(process, pc, corewar);
        case ST: return store(process, pc, corewar);
        case ADD: return add(process, pc, corewar);
        case SUB: return sub(process, pc, corewar);
        case AND: return and_binary(process, pc, corewar);
        case OR: return or_binary(process, pc, corewar);
        case XOR: return xor_binary(process, pc, corewar);
        case ZJMP: return zjmp(process, pc, corewar);
        case LDI: return ldi(process, pc, corewar);
        case STI: return sti(process, pc, corewar);
        case FORK: return fork_inst(process, pc, corewar);
        case LLD: return lld(process, pc, corewar);
        case LLDI: return lldi(process, pc, corewar);
        case LFORK: return lfork(process, pc, corewar);
        case AFF: return aff(process, corewar);
        default: break;
    }
    return process->carry;
}

int execute_instruction(process_t *process, corewar_t* corewar)
{
    int pc = process->pc;
    process->pc = (pc + 1) % MEM_SIZE;
    if (process->op.need_coding_byte) {
        if (!is_coding_byte_valid(corewar->memory[process->pc], process->op))
            return process->carry;
    }
    return switch_instruction(process, pc, corewar);
}

void execute_processes(process_t* first, corewar_t *corewar)
{
    int inst;
    for (process_t *current = first; current; current = current->next) {
        if (current->wait)
            current->wait--;
        else {
            current->carry = execute_instruction(current, corewar);
            inst = corewar->memory[current->pc];
            inst = !inst || inst >= NB_OP ? NB_OP : inst - 1;
            current->op = op_tab[inst];
            current->wait = current->op.nbr_cycles - 1;
        }
    }
}

void war_loop(corewar_t *corewar)
{
    int win = 0;

    for (; !win; win = check_win(corewar->champions, corewar->champion_count)) {
        if (corewar->cycle == corewar->dump_cycle) {
            dump_memory(corewar->memory);
            break;
        }
        execute_processes(corewar->processes, corewar);
        war_check(corewar);
    }
    if (!win)
        return;
    corewar->win = win;
}
