/*
** EPITECH PROJECT, 2023
** corewar_visualizer
** File description:
** get_color
*/

int get_color(int id)
{
    if (id <= 0)
        return 0;
    if (id < 5)
        return id;
    return id % 2 + 5;
}
