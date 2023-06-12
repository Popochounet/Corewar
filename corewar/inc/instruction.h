/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** instruction.h
*/

#pragma once

    #include "war.h"

int live(process_t *current, corewar_t *corewar);
int load(process_t *current, int pc, corewar_t *corewar);
int store(process_t *current, int pc, corewar_t *corewar);
int add(process_t *current, int pc, corewar_t *corewar);
int sub(process_t *current, int pc, corewar_t *corewar);
int and_binary(process_t *current, int pc, corewar_t *corewar);
int or_binary(process_t *current, int pc, corewar_t *corewar);
int xor_binary(process_t *current, int pc, corewar_t *corewar);
int zjmp(process_t *current, int pc, corewar_t *corewar);
int ldi(process_t *current, int pc, corewar_t *corewar);
int sti(process_t *current, int pc, corewar_t *corewar);
int fork_inst(process_t *current, int pc, corewar_t *corewar);
int lld(process_t *current, int pc, corewar_t *corewar);
int lldi(process_t *current, int pc, corewar_t *corewar);
int lfork(process_t *current, int pc, corewar_t *corewar);
int aff(process_t *current, corewar_t *corewar);
