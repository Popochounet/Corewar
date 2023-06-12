/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count the number of characters in a string
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return len;
}
