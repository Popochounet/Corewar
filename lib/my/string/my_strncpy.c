/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy the given string and return an other one
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
        if (src[i] == '\0') {
            dest[i] = '\0';
            i = n;
        }
    }
    dest[i] = '\0';
    return dest;
}
