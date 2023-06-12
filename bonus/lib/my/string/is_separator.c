/*
** EPITECH PROJECT, 2022
** hunterv2
** File description:
** a short file description
*/

int is_separator(char c, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i++)
        if (c == separator[i])
            return 1;
    return 0;
}
