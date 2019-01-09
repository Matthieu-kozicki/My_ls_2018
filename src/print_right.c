/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** print right
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
#include "my.h"

void print_right3(struct stat file)
{
    if ((file.st_mode & S_IWOTH) != 0)
        my_putchar('w');
    else
        my_putchar('-');
    if ((file.st_mode & S_IXOTH) != 0)
        my_putchar('x');
    else
        my_putchar('-');
    my_putchar(' ');
}

void print_right2(struct stat file)
{
    if ((file.st_mode & S_IRGRP) != 0)
        my_putchar('r');
    else
        my_putchar('-');
    if ((file.st_mode & S_IWGRP) != 0)
        my_putchar('w');
    else
        my_putchar('-');
    if ((file.st_mode & S_IXGRP) != 0)
        my_putchar('x');
    else
        my_putchar('-');
    if ((file.st_mode & S_IROTH) != 0)
        my_putchar('r');
    else
        my_putchar('-');
    print_right3(file);
}

void print_right(struct stat file)
{
    if ((file.st_mode & S_IFDIR) != 0)
        my_putchar('d');
    else
        my_putchar('-');
    if ((file.st_mode & S_IRUSR) != 0)
        my_putchar('r');
    else
        my_putchar('-');
    if ((file.st_mode & S_IWUSR) != 0)
        my_putchar('w');
    else
        my_putchar('-');
    if ((file.st_mode & S_IXUSR) != 0)
        my_putchar('x');
    else
        my_putchar('-');
    print_right2(file);
}
