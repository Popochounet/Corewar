/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** my_strnbr
*/

#include <stdlib.h>

char *my_strnbr(unsigned int input)
{
    unsigned int temp = input;
    int num_digits = 0;
    char *output;

    for (; temp > 0; temp /= 10, num_digits++);
    output = malloc(sizeof(char) * (num_digits + 1));
    for (int i = num_digits - 1; input > 0; i--) {
        output[i] = '0' + (input % 10);
        input /= 10;
    }
    output[num_digits] = '\0';
    return output;
}
