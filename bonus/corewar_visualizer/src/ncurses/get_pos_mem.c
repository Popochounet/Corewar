/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_pos_mem
*/

#include "visual.h"

pos_t get_pos_mem(int i, pos_t offset, int spacing)
{
    int j;
    int x_offset = spacing;
    int y_offset = x_offset / 2;

    if (i < MEM_SIZE / 8 * 3) {
        return (pos_t){offset.x + WIDTH_MEM + i % WIDTH_MEM * 3 + x_offset,
            offset.y + i / WIDTH_MEM};
    } if (i < MEM_SIZE / 2) {
        return (pos_t){offset.x + WIDTH_MEM + WIDTH_MEM * 3 - 3 + WIDTH_MEM * 3
            - i / HEIGHT_MEM * 3 + x_offset, offset.y + HEIGHT_MEM + i %
            HEIGHT_MEM + y_offset};
    } if (i < MEM_SIZE / 8 * 7) {
        j = MEM_SIZE / 8 * 7 - i - 1;
        return (pos_t){offset.x + j % WIDTH_MEM * 3,
            offset.y + HEIGHT_MEM + j / WIDTH_MEM + y_offset};
    }
    j = MEM_SIZE - i + HEIGHT_MEM - 1;
    return (pos_t){offset.x + WIDTH_MEM - j / HEIGHT_MEM * 3,
        offset.y + j % HEIGHT_MEM};
}