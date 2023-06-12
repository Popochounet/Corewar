/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** key_handler
*/

#include "visual.h"
#include "processes.h"

static void key_cycle_per_second(int key, visual_t *visual)
{
    switch (key) {
    case 'c':
        visual->cycle_per_second *= 1.2;
        break;
    case 'x':
        visual->cycle_per_second *= 0.8;
        if (visual->cycle_per_second < 0.5)
            visual->cycle_per_second = 0.5;
        break;
    default:
        break;
    }
}

static void key_viewed_process(int key, visual_t *visual, process_t *processes)
{
    switch (key) {
    case KEY_UP:
        visual->viewed_process_id++;
        if (visual->viewed_process_id > get_processes_count(processes)
        - 1)
            visual->viewed_process_id = 0;
        break;
    case KEY_DOWN:
        visual->viewed_process_id--;
        if (visual->viewed_process_id < 0)
            visual->viewed_process_id = get_processes_count(processes)
                - 1;
        break;
    default:
        break;
    }
}

bool key_handler(visual_t *visual, corewar_t *corewar)
{
    int key = getch();
    visual->key = key;
    key_cycle_per_second(key, visual);
    key_viewed_process(key, visual, corewar->processes);
    switch (key) {
    case 27: case 'q':
        return true;
    case ' ':
        visual->pause = !visual->pause;
        visual->last_cycle = clock();
        break;
    case KEY_RIGHT:
        visual->step_forward = true;
        for (int i = 0; i < corewar->champion_count; i++)
            corewar->champions[i]->saying_live = false;
        break;
    default:
        return false;
    }
    return false;
}
