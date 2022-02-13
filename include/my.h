/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

char *return_base(long long nb, int base);
void my_putchar(char c);
int my_isneg(int nb);
void my_swap(char *a, char *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_ustrlen(unsigned char const *str);
long my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *str);
int my_sslen(char **ss);
int my_char_isnum(char const chr);
char *my_getstrnbr(char const *str, int i, int base);
void my_putss(char **ss);
char **my_strtoss(char *str, int base);
char *my_inttostr(int nb);
void delete_cis(char *str, int pos, int const n);
char *add_cis(char *str, int pos, char *to_add);
void delete_siss(char **ss, int pos, int const n);
char **add_siss(char **ss, int pos, char *to_add);
int my_char_isbase(char const chr, int base);
int my_str_isbase(char const *str, int base);
void delete_ucis(unsigned char *str, int pos, int const n);
unsigned char *add_ucis(unsigned char *str, int pos, char *to_add);
char *my_ustrdup(unsigned char const *str);
int neg(char *nb1, char *nb2);
char **my_str_toarray(char *str, int global_size);
int my_char_iscbase(char const chr, char base);
char *my_longtostr(long nb);
void my_put_basenbr(long long nb, int base);

#endif /* MY_H_ */
