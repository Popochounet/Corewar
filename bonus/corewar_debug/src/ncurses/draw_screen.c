/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** draw_screen
*/

#include "struct.h"
#include "visual.h"
#include "my.h"
#include <unistd.h>
#include "processes.h"

static void draw_header(WINDOW *win, corewar_t *corewar, visual_t *visual)
{
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Cycle: %d", corewar->cycle);
    mvwprintw(win, 2, 2, "Cycle to die: %d", corewar->cycle_to_die);
    mvwprintw(win, 3, 2, "Live count: %d", corewar->live_count);
    mvwprintw(win, 4, 2, "Cycle per sec: %.1f", visual->cycle_per_second);
    mvwprintw(win, 5, 2, "Process_count: %d", get_processes_count(
        corewar->processes));
    if (visual->pause)
        mvwprintw(win, 1, 40, "PAUSE");
    wrefresh(win);
}

static void draw_champ_box(WINDOW *win, champion_t *champion,
process_t *processes, bool pause)
{
    if (champion == NULL)
        return;
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "%d : %s", champion->id, champion->name);
    mvwchgat(win, 1, 2, my_strlen(champion->name) + 5, A_BOLD, champion->id,
        NULL);
    mvwprintw(win, 2, 2, "Cycle before die: %d", champion->cycle_before_die);
    mvwprintw(win, 3, 2, "Size: %d", champion->size);
    mvwprintw(win, 4, 2, "Process_count: %d",
        count_champ_processes(processes, champion->id));
    if (champion->saying_live) {
        mvwprintw(win, 8, 2, "I'M ALIVE!");
        if (!pause)
            champion->saying_live = false;
    }
    if (!champion->alive)
        draw_skull(win, 30, 2);
    wrefresh(win);
}

static void draw_process_box_registers(WINDOW *win, process_t *process)
{
    mvwprintw(win, 1, 20, "Registers:");
    for (int x = 0; x < 2; x++)
        for (int i = 0; i < REG_NUMBER / 2; i++)
            mvwprintw(win, 2 + i % 8, x && !i ? 21 + x * 16 : 20 + x * 16,
                "%d: %X", i + x * 8 + 1,
                process->reg[i + (REG_NUMBER / 2) * x]);
}

// put_hexa_curse(win, process->reg[i], 21 + x * 12, 2 + i % 8);
static void draw_process_box(WINDOW *win, process_t *process, visual_t *visual)
{
    werase(win);
    box(win, 0, 0);
    for (int i = 0; process && i < visual->viewed_process_id; i++)
        process = process->next;
    mvwprintw(win, 1, 2, "Process %d", visual->viewed_process_id + 1);
    mvwchgat(win, 1, 2, 11, A_BOLD, process->champ_id, NULL);
    mvwprintw(win, 2, 2, "Owned by %d", process->champ_id);
    mvwchgat(win, 2, 2, 11, A_BOLD, process->champ_id, NULL);
    mvwprintw(win, 3, 2, "PC: %d", process->pc);
    mvwchgat(visual->win,
            visual->mem_pos.y + process->pc / visual->line_len,
            visual->mem_pos.x + process->pc % visual->line_len * 3, 2,
            visual->pause ? A_UNDERLINE | A_BOLD | A_BLINK :
            A_UNDERLINE | A_BOLD , process->champ_id, NULL);
    mvwprintw(win, 4, 2, "Carry: %d", process->carry);
    mvwprintw(win, 5, 2, "Wait: %d", process->wait + 1);
    draw_process_box_registers(win, process);
    wrefresh(win);
}

void draw_screen(corewar_t *corewar, visual_t *visual)
{
    draw_header(visual->header, corewar, visual);
    draw_mem(corewar, visual);
    draw_process_box(visual->process_win, corewar->processes, visual);
    for (int i = 0; visual->champ_win[i] && i < MAX_CHAMP_COUNT; i++)
        draw_champ_box(visual->champ_win[i], corewar->champions[i],
            corewar->processes, visual->pause);
    wrefresh(visual->win);
}
