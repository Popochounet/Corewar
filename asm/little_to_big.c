/*
** EPITECH PROJECT, 2022
** little_to_big
** File description:
** a short file description
*/

#include "my.h"

int little_to_big_endian(int num)
{
    int result = ((num & 0x000000FF) << 24);

    result |= ((num & 0x0000FF00) << 8);
    result |= ((num & 0x00FF0000) >> 8);
    result |= ((num & 0xFF000000) >> 24);
    return result;
}
