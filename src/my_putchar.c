/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** put
*/
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}
