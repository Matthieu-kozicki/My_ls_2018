/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_put_base(char *base, unsigned int nb)
{
    char *result = malloc(sizeof(char) * 25);
    int k = 0;

    while ( nb != 0) {
        result[k] = base[nb % my_strlen(base)];
        nb = nb / my_strlen(base);
        k = k + 1;
    }
    result = my_revstr(result);
    result[25] = '\0';
    my_putstr(result);
}

int  my_put_nbri(unsigned int nb)
{
    unsigned int z = 0;
    unsigned int i = nb;
    unsigned int d = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb *-1;
    }
    while (nb/d >= 10) {
        d *= 10;
    }
    while (d >= 1 ) {
        z = nb / d;
        z = z + 48;
        my_putchar(z);
        nb = nb % d;
        d = d / 10;
    }
}
void flag(char *s, va_list ap, int d)
{
    if (s[d+1] == 'u')
        my_put_nbri(va_arg(ap, unsigned int));
    if (s[d+1] == 'b')
        my_put_base("01", va_arg(ap, unsigned int));
    if (s[d+1] == 'o')
        my_put_base("01234567", va_arg(ap, unsigned int));
    if (s[d+1] == 'x')
        my_put_base("0123456789abcdef", va_arg(ap, unsigned int));
    if (s[d+1] == 'X')
        my_put_base("0123456789ABCDEF", va_arg(ap, unsigned int));
}

void flag_two(char *s, va_list ap, int d)
{
    if (s[d+1] == 'd' || s[d+1] == 'i')
        my_put_nbr(va_arg(ap, int));
    if (s[d+1] == '%')
        my_putchar('%');
    if (s[d+1] == 's')
        my_putstr(va_arg(ap, char*));
    if (s[d+1] == 'c')
        my_putchar(va_arg(ap, int));
}

int my_printf(char *s, ...)
{
    va_list ap;
    int d = 0;

    va_start(ap, s);
    while (s[d] != '\0') {
        if (s[d] == '%') {
            flag(s, ap, d);
            flag_two(s, ap, d);
            d = d + 1;
        } else {
            my_putchar(s[d]);
        }
        d = d + 1;
    }
    va_end(ap);
}
