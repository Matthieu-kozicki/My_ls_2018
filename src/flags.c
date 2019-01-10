/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** some flags
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

void flag_a(int arc, char **arg)
{
    struct dirent *file;
    DIR *rep;

    if (arc == 2)
        rep = opendir(".");
    else
        rep = opendir(arg[2]);
    while (file = readdir(rep))
        my_printf("%s ",file->d_name);
    my_printf("\n");
    closedir(rep);
}

void flag_d(int arc, char **arg)
{
    if (arc == 2)
        my_putchar('.');
    if (arc == 3)
        my_printf("%s\n", arg[2]);
}

void real_file(char *str)
{
    struct stat file;

    if (stat(str, &file) == 0)
        my_printf("%s\n",str);
    else
        my_printf("No such file or directory\n");
}

void no_flag_path(char *arg)
{
    struct dirent *file;
    DIR *rep = opendir(arg);

    if (rep == NULL) {
        real_file(arg);
        closedir(rep);
        return;
    }
    while ((file = readdir(rep)) != NULL) {
        if (file->d_name[0] != '.')
            my_printf("%s  ", file->d_name);
    }
    my_printf("\n");
    closedir(rep);
}

void no_flag(void)
{
    struct dirent *file;
    DIR *rep = opendir(".");

    while (file = readdir(rep)) {
        if (file->d_name[0] != '.')
            my_printf("%s  ", file->d_name);
    }
    my_printf("\n");
    closedir(rep);
}
