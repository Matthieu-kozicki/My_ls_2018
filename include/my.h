/*
** EPITECH PROJECT, 2018
** my
** File description:
** h
*/

#ifndef MY_H
#define MY_H

//print
void my_putchar(char c);
int my_put_nbr(int nb);
int my_printf(char *s, ...);
char *my_revstr(char *str);
void my_putstr(char const *str);
int my_strlen(char const *str);
void print_info(char *str, int arc, char **arg);
void total_path(char **arg);
void total_here(char **arg);
void print_right3(struct stat file);
void print_right2(struct stat file);
void print_right(struct stat file);

//flags
void flag_a(int arc, char **arg);
void flag_d(int arc, char **arg);
void flag_l(int arc, char **arg);
void flag_l_here(int arc, char **arg);
void no_flag_path(char *arg);
void no_flag(void);

//modify path
char *melt(char *str,char *cpy);

#endif
