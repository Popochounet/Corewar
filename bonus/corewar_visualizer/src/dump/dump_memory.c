/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** dump_memory
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include "tools.h"

static void put_prefix(int i)
{
    char *prefix = my_convert_base(i, 16, true);

    my_putstr(prefix);
    for (int i = my_strlen(prefix); i < 5; i++)
        my_putchar(' ');
    my_putstr(": ");
    free(prefix);
}

void dump_memory(mem_t memory)
{
    int line_length = 32;

    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % line_length == 0)
            put_prefix(i);
        put_hexa(memory[i]);
        my_putchar(' ');
        if (i % line_length == line_length - 1)
            my_putstr("\n");
    }
}
