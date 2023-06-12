/*
** EPITECH PROJECT, 2022
** my_swapchar
** File description:
** swaps the content of two variables
*/

void my_swapchar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
