/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** hytr
*/

#include "my.h"
char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str);
    int temp = 0;

    j = j - 1;
    while (i < j) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j = j - 1;
        i = i + 1;
    }
    return (str);
}
