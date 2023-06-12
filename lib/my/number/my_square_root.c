/*
** EPITECH PROJECT, 2022
** my_square_root
** File description:
** find the square_root of an int
*/

int my_square_root(int nb)
{
    int square_root = 2;
    int square = square_root;

    for (; square != nb; square++) {
        square = square_root * square_root;
        if (square > nb || square < square_root) {
            return (0);
        }
    }
    return square_root;
}
