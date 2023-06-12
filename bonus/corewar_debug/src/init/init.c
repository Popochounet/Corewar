/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init
*/

#include "initialisation.h"
#include "free.h"
#include "visual.h"

static int count_champions(int ac, char **av)
{
    int champion_count = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            i++;
            continue;
        }
        champion_count++;
    }
    return champion_count;
}

static void init_with_null(corewar_t *corewar, visual_t *visual)
{
    corewar->champions = malloc(sizeof(champion_t *) * corewar->champion_count);
    for (int i = 0; i < corewar->champion_count; i++)
        corewar->champions[i] = NULL;
    for (int i = 0; i < MEM_SIZE; i++) {
        corewar->memory[i] = 0;
    }
    corewar->dump_cycle = -1;
    corewar->parse_champions = NULL;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    for (int i = 0; i < MEM_SIZE; i++)
        visual->mem_color[i] = COLOR_BLACK;
    for (int i = 0; i < MAX_CHAMP_COUNT; i++)
        visual->champ_win[i] = NULL;
    corewar->win = -2;
}

int init_corewar(corewar_t *corewar, visual_t *visual, int ac, char **av)
{
    corewar->champion_count = count_champions(ac, av);
    init_with_null(corewar, visual);
    if (parse_args(corewar, ac, av) == 84)
        return 84;
    if (load_champions(corewar, visual) == 84) {
        free_parse_champions(corewar->parse_champions);
        return 84;
    }
    create_first_processes(corewar);
    free_parse_champions(corewar->parse_champions);
    if (corewar->visual)
        init_visual(visual, corewar->champion_count);
    return 0;
}
