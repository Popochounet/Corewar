/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy the given string and return an other one
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
