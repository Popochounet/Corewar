/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** MY
*/

#ifndef MY
    #define MY
    #define ABS(x)  x < 0 ? x * -1 : x

    #include <stdbool.h>

typedef union nb_binary {
    double nb;
    unsigned long long binary;
} nb_binary_t;


// CHAR
bool my_char_isalpha(char const c);
bool my_char_isalphanum(char const c);
bool my_char_isnum(char const c);
bool my_char_isup(char const c);
bool my_char_isspace(char c);


// MATH
char *my_convert_base(unsigned long nb, int base, bool maj);


// NUMBER
bool my_double_isneg(double const nb);
bool my_is_prime(int nb);
int my_nbrlen(long const nb);
int my_getnbr(char const *str);
int my_square_root(int nb);

// PUT
void my_putchar(char c);
int my_putstr(char const *str);
int my_puterror(char const *str);
void my_puttab(char *const *tab);
int my_putnbr(int nb);


// STRING
int my_strlen(char const *str);
char *my_strdup(char const *src);
void my_clean_str(char *str);
char *my_revstr(char *str);
char *my_upstr(char *str);
void my_swapchar(char *a, char *b);
bool my_str_isalpha(char const *str);
bool my_str_isnum(char const *str);
bool my_str_isprintable(char const *str);
char *my_strlowcase(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *src);
int is_separator(char c, char *separator);
int count_word(char const *str, char *separator);
char **my_str_to_word_array_sep(char *str, char *separator);
char *my_strnbr(unsigned int input);
char *my_strcpypart(char *dest, char *src, int ind_start, int ind_end);

// TAB
void my_freetab(char **tab);
int my_tablen(char *const *tab);


#endif /* !MY */
