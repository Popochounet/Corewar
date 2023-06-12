/*
** EPITECH PROJECT, 2022
** my_upstr
** File description:
** uppercase a string
*/

char *my_upstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}
