/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-adrien.audiard
** File description:
** struct
*/

#pragma once

    #include "my.h"
    #include "op.h"
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>

typedef struct str_list {
    char **array;
    struct str_list *next;
} str_list_t;

typedef struct labels {
    int pos_label;
    char *label;
    int pos_cmd;
    int size;
    struct labels *next;
} labels_t;

typedef struct body {
    char *str;
    int pos;
    char *cmd_name;
    int starting_cmd_pos;
} body_t;

void disp_usage(void);
int little_to_big_endian(int num);
header_t get_header_from_champ(FILE *champion);
void get_progname(char *dest, char *line);
int valid_cmd(char *line, header_t *header, int *comment, int *prog_name);
FILE *open_cor_file(char *file);
body_t body_parse(FILE *champion);
body_t add_command_body(str_list_t *list, labels_t **l1, labels_t **l2);
void add_directives(body_t *str, str_list_t *list, op_t tab, labels_t **labels);
char *my_strcat_body(body_t *dest, char *src, int free_args, int size);
char **my_clean_array(char **array, char *delim);
void free_str_construction(str_list_t *list);
void free_labels(labels_t *labels);
void index_section(body_t **str, str_list_t *list, op_t tab, labels_t **lab);
void not_index(body_t **str, str_list_t *list, op_t tab, labels_t **lab);
char **clean_array(char *str);
int check_label_char(char *label);
void check_register(int reg);
char *my_strcatdup(char *before, char *after);
