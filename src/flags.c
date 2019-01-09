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

void flag_a(char *arg)
{
    struct dirent *file;
    DIR *rep = opendir(arg);

    while (file = readdir(rep))
        my_printf("%s ",file->d_name);
    my_printf("\n");
    closedir(rep);
}

void flag_d(char *arg)
{
    my_printf("%s\n", arg);
}

void no_flag_path(char *arg)
{
    struct dirent *file;
    DIR *rep = opendir(arg);

    while (file = readdir(rep)) {
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
