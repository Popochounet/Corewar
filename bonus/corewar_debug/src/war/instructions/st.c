/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** st.c
*/

#include "war.h"
#include "instruction.h"
#include "initialisation.h"
#include "visual.h"

void put_in_mem(corewar_t *corewar, int value, int idx)
{
    integer_t nb;

    nb.nb_int = value;
    for (int i = 0; i < REG_SIZE; i++)
        corewar->memory[(MEM_SIZE + idx + i) % MEM_SIZE] = nb.buffer[3 - i];
}

static void color_mem(visual_t *visual, int value, int idx)
{
    for (int i = 0; i < REG_SIZE; i++)
        visual->mem_color[(MEM_SIZE + idx + i) % MEM_SIZE] = value;
}

int store(process_t *current, int pc, corewar_t *corewar, visual_t *visual)
{
    argument_t args[MAX_ARGS_NUMBER];
    int idx;

    if (get_args(current, corewar->memory, &args))
        return 0;
    if (args[1].type == T_REG)
        current->reg[args[1].value - 1] = current->reg[args[0].value - 1];
    if (args[1].type == T_IND) {
        idx = (pc + args[1].value % IDX_MOD) % MEM_SIZE;
        put_in_mem(corewar, current->reg[args[0].value - 1], idx);
    }
    color_mem(visual, current->champ_id, idx);
    return 1;
}

int sti(process_t *current, int pc, corewar_t *corewar, visual_t *visual)
{
    argument_t args[MAX_ARGS_NUMBER];
    int idx;

    if (get_args(current, corewar->memory, &args))
        return 0;
    for (int i = 1, idx; i < 3; i++) {
        if (args[i].type == T_REG)
            args[i].value = current->reg[args[i].value - 1];
        if (args[i].type == T_IND) {
            idx = (pc + args[i].value % IDX_MOD) % MEM_SIZE;
            args[i].value = read_mem(corewar->memory, &idx, IND_SIZE);
        }
    }
    idx = (pc + (args[1].value + args[2].value) % IDX_MOD) % MEM_SIZE;
    put_in_mem(corewar, current->reg[args[0].value - 1], idx);
    color_mem(visual, current->champ_id, idx);
    return 1;
}
