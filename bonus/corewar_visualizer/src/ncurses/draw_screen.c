/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** draw_screen
*/

#include "visual.h"

static void draw_credits(visual_t *visual)
{
    mvwprintw(visual->win, 4, 317 / 8 - 7, "Adrien AUDIARD");
    mvwchgat(visual->win, 4, 317 / 8 - 7, 25, A_DIM, 0, NULL);
    mvwprintw(visual->win, 4, 317 / 8 * 2 - 5, "Antoine ESMAN");
    mvwchgat(visual->win, 4, 317 / 8 * 2 - 5, 15, A_DIM, 0, NULL);
    mvwprintw(visual->win, 4, 317 / 8 * 6 - 11, "Matthias VON RAKOWSKI");
    mvwchgat(visual->win, 4, 317 / 8 * 6 - 11, 25, A_DIM, 0, NULL);
    mvwprintw(visual->win, 4, 317 / 8 * 7 - 8, "Samuel BRUSCHET");
    mvwchgat(visual->win, 4, 317 / 8 * 7 - 8, 25, A_DIM, 0, NULL);
}

void draw_screen(corewar_t *corewar, visual_t *visual)
{
    mvwprintw(visual->win, 78, 10, "#jejoueaminecraftenfullscreen");
    draw_mem(corewar, visual);
    if (!visual->detailed_view) {
        draw_credits(visual);
        draw_title(visual->win, 133, 1);
        wnoutrefresh(visual->win);
        doupdate();
        return;
    }
    draw_process_box(visual->process_win, corewar->processes, corewar, visual);
    draw_game_info(visual->game_info_win, corewar, visual);
    for (int i = 0; visual->champ_win[i] && i < MAX_CHAMP_COUNT; i++)
        draw_champ_box(visual->champ_win[i], corewar->champions[i],
            corewar->processes, visual);
    draw_title(visual->win, 133, 35);
    if (corewar->win != -2) {
        draw_crown(visual->champ_win[corewar->win - 1], 40, 3);
        wnoutrefresh(visual->champ_win[corewar->win - 1]);
    }
    doupdate();
}
