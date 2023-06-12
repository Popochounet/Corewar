/*
** EPITECH PROJECT, 2023
** my_strcpypart
** File description:
** a short file description
*/

char *my_strcpypart(char *dest, char *src, int ind_start, int ind_end)
{
    int i1 = ind_start;
    int i2 = ind_end;
    int i_dest = 0;
    int i = 0;

    while (i1 < i2) {
        dest[i_dest] = src[i1];
        i_dest++;
        i1++;
        i++;
    }
    dest[ind_end - ind_start] = '\0';
}
