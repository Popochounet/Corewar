/*
** EPITECH PROJECT, 2022
** little_to_big
** File description:
** a short file description
*/

#include "asm.h"

static int tab_only(char *string, int idx_str)
{
    for (int i = idx_str + 1; string[i + 1]; i++) {
        if (string[i] != ' ' && string[i] != '\t')
            return 0;
    }
    return 1;
}

static int parse_name(char *string, header_t *header)
{
    int idx_str = 0;
    int max_tok = PROG_NAME_LENGTH + 1;

    while (*string == ' ' || *string == '\t')
        string++;
    if (string[0] != '"' || header->prog_name[0])
        return 0;
    string++;
    while (string[idx_str] != '"' && string[idx_str] && idx_str != max_tok) {
        header->prog_name[idx_str] = string[idx_str];
        idx_str++;
    }
    if (!string[idx_str] || idx_str == max_tok || !tab_only(string, idx_str))
        return 0;
    return 1;
}

static int parse_comment(char *string, header_t *header)
{
    int idx_str = 0;
    int max_tok = COMMENT_LENGTH + 1;

    while (*string == ' ' || *string == '\t')
        string++;
    if (string[0] != '"' || header->comment[0])
        return 0;
    string++;
    while (string[idx_str] != '"' && string[idx_str] && idx_str != max_tok) {
        header->comment[idx_str] = string[idx_str];
        idx_str++;
    }
    if (!string[idx_str] || idx_str == max_tok || !tab_only(string, idx_str))
        return 0;
    return 1;
}

int valid_cmd(char *line, header_t *header, int *comment, int *prog_name)
{
    while (*line == ' ' || *line == '\t')
        line++;
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0) {
        *prog_name = 1;
        return parse_name(line + my_strlen(NAME_CMD_STRING) + 1, header);
    } else if (my_strncmp(line, COMMENT_CMD_STRING,
                            my_strlen(COMMENT_CMD_STRING)) == 0) {
        *comment = 1;
        return parse_comment(line + my_strlen(COMMENT_CMD_STRING) + 1, header);
    } else
        return 0;
}
