/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** read_mem.c
*/

#include "instruction.h"
#include "initialisation.h"

int read_mem_char(mem_t mem, int *idx)
{
    char nb_buffer[1] = {0};
    char_t char_union;

    for (int i = 0; i >= 0; i--, ++(*idx) % MEM_SIZE) {
        nb_buffer[i] = mem[(*idx)];
    }
    for (int i = 0; i < 1; i++) {
        char_union.buffer[i] = nb_buffer[i];
    }
    return char_union.nb_int;
}

int read_mem_short(mem_t mem, int *idx)
{
    char nb_buffer[2] = {0, 0};
    short_t short_union;

    for (int i = 1; i >= 0; i--, ++(*idx) % MEM_SIZE) {
        nb_buffer[i] = mem[(*idx)];
    }
    for (int i = 0; i < 2; i++) {
        short_union.buffer[i] = nb_buffer[i];
    }
    return short_union.nb_int;
}

int read_mem_int(mem_t mem, int *idx)
{
    char nb_buffer[4] = {0, 0, 0, 0};
    integer_t int_union;

    for (int i = 3; i >= 0; i--, ++(*idx) % MEM_SIZE) {
        nb_buffer[i] = mem[(*idx)];
    }
    for (int i = 0; i < 4; i++) {
        int_union.buffer[i] = nb_buffer[i];
    }
    return int_union.nb_int;
}

int read_mem(mem_t mem, int *idx, int size)
{
    switch (size) {
        case 1: return read_mem_char(mem, idx);
        case 2: return read_mem_short(mem, idx);
        case 4: return read_mem_int(mem, idx);
    }
    return 0;
}
