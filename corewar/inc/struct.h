/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** struct.h
*/

#pragma once

    #include <stdbool.h>

    #include "../../include/op.h"

typedef unsigned char mem_t[MEM_SIZE];

typedef struct argument {
    int type;
    int value;
} argument_t;

typedef enum instruction {
    NONE = 0,
    LIVE,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF,
} e_instruction;

typedef struct process {
    int champ_id;
    int reg[REG_NUMBER];
    int pc;
    int carry;
    int wait;
    op_t op;
    struct process *next;
} process_t;

typedef struct parse_champion {
    char *path;
    int id;
    int load_address;
    struct parse_champion *next;
} parse_champion_t;

typedef struct champion {
    int id;
    char *name;
    char *comment;
    int size;
    unsigned char *body;
    int cycle_before_die;
    bool alive;
    bool saying_live;
    int load_address;
} champion_t;

typedef struct corewar {
    mem_t memory;
    int cycle;
    int live_count;
    int cycle_to_die;
    process_t *processes;
    champion_t **champions;
    unsigned short champion_count;
    parse_champion_t *parse_champions;
    unsigned int load_address_delta;
    int dump_cycle;
    int dump_index;
    bool visual;
    int win;
} corewar_t;
