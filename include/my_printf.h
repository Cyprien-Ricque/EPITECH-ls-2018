/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_H_
#define MY_H_

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
char *my_longtostr(long long nb);
char *file_read(char *file_path);
int my_printf(char *str, ...);
int hredirection(char *str, int *i);
int lredirection(char *str, int *i);
int redirection(char *str, int *i, va_list *ap);
int space_plus(long long nb, char *str, int val, int base);
int zero(long long nb, char *str, int val, int to_add);
int scan(char *str, int val, long nb, int base);
int ez_scan(char *str, int pos, char to_find);
int my_nblen(long nb, int base);
int spe_scan(char *str, int val);
long my_getlnbr(char const *str, int pos);
int die_z(long long nb, char *str, int val, int to_add);
char *my_retbasenbr(long long nb, int base);
int diez_scan(char *str, int val);
int initialisation(long *nb, char *str, int val);
void dot_plus_minus(long long nb, char *str, int val);
void dot_diez(char *str, int val);
int dot_managment(long long nb, char *str, int val, int base);
int the_choice(long long nb, char *str, int val, int base);
int find_zero_nb(char *str, int val);
int find_spaces_nb(char *str, int val);
int pos_neg_scan(long long nb, char *str, int val);
int dot_zero(long long nb, char *str, int val, int base);
int dot_spaces(long long nb, char *str, int val, int base);
void my_put_basemnbr(long long nb, int base);
int st_flags(int val, char *str, char *strtp);
int st_scan(int val, char *str, char *strtp);
int space_minus(char *str, int val, long long nb, int base);
int strin_g(va_list ap, int val, char *str);
int cha_r(va_list ap, int val, char *str);
int pointe_r(va_list ap, int val, char *str);
int nothin_g(va_list ap, int val, char *str);
int spestrin_g(va_list ap, int val, char *str);
int in_t(va_list ap, int val, char *str);
int lin_t(va_list ap, int val, char *str);
int llin_t(va_list ap, int val, char *str);
int hin_t(va_list ap, int val, char *str);
int hhin_t(va_list ap, int val, char *str);
int octa(va_list ap, int val, char *str);
int locta(va_list ap, int val, char *str);
int llocta(va_list ap, int val, char *str);
int hocta(va_list ap, int val, char *str);
int hhocta(va_list ap, int val, char *str);
int usd(va_list ap, int val, char *str);
int lusd(va_list ap, int val, char *str);
int llusd(va_list ap, int val, char *str);
int husd(va_list ap, int val, char *str);
int hhusd(va_list ap, int val, char *str);
int hexa(va_list ap, int val, char *str);
int lhexa(va_list ap, int val, char *str);
int llhexa(va_list ap, int val, char *str);
int hhexa(va_list ap, int val, char *str);
int hhhexa(va_list ap, int val, char *str);
int hexam(va_list ap, int val, char *str);
int lhexam(va_list ap, int val, char *str);
int llhexam(va_list ap, int val, char *str);
int hhexam(va_list ap, int val, char *str);
int hhhexam(va_list ap, int val, char *str);
int bin(va_list ap, int val, char *str);
int lbin(va_list ap, int val, char *str);
int llbin(va_list ap, int val, char *str);
int hbin(va_list ap, int val, char *str);
int hhbin(va_list ap, int val, char *str);
int cha_r(va_list ap, int val, char *str);
int strin_g(va_list ap, int val, char *str);
int pointe_r(va_list ap, int val, char *str);
int nothin_g(va_list ap, int val, char *str);
int spestrin_g(va_list ap, int val, char *str);
void my_put_basenbr(int nb, int base);
void my_put_lbasenbr(long nb, int base);
void my_put_llbasenbr(long long nb, int base);
void my_put_hbasenbr(short nb, int base);
void my_put_lubasenbr(unsigned long nb, int base);
void my_put_ubasenbr(unsigned int nb, int base);
void my_put_llubasenbr(unsigned long long nb, int base);
void my_put_hubasenbr(unsigned short int nb, int base);
void my_put_ubasemnbr(unsigned int nb, int base);
void my_put_lubasemnbr(unsigned long nb, int base);
void my_put_llubasemnbr(unsigned long long nb, int base);
void my_put_hubasemnbr(unsigned short int nb, int base);
void pointeur(char *str, int val);
#endif /* MY_H_ */
