/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** load_champions
*/

#include "initialisation.h"
#include "my.h"

static void load_champion_in_memory(corewar_t *corewar, int i, visual_t *visual)
{
    int load_address;

    if (corewar->champions[i]->load_address != -1)
        load_address = corewar->champions[i]->load_address;
    else
        load_address = i * MEM_SIZE / corewar->champion_count +
            corewar->load_address_delta - corewar->champions[i]->size / 2;
    corewar->champions[i]->load_address = load_address;
    for (int j = 0; j < corewar->champions[i]->size; j++) {
        corewar->memory[load_address + j] = corewar->champions[i]->body[j];
        visual->mem_color[load_address + j] = corewar->champions[i]->id;
    }
}

int load_champions(corewar_t *corewar, visual_t *visual)
{
    parse_champion_t *p_champ = corewar->parse_champions;
    champion_t *champion = NULL;

    for (int i = 0; p_champ; p_champ = p_champ->next, i++) {
        champion = read_champion(p_champ);
        if (champion == NULL) {
            my_puterror("Error: invalid champion ");
            my_puterror(p_champ->path);
            my_puterror("\n");
            return 84;
        }
        if (i == 0) {
            corewar->load_address_delta = champion->size / 2;
        }
        champion->id = i + 1;
        corewar->champions[i] = champion;
        load_champion_in_memory(corewar, i, visual);
    }
    return 0;
}
