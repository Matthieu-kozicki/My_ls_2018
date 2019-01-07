/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** main file
*/

#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"

void flag_a(char *arg)
{
    struct dirent *file;
    DIR *rep = opendir(arg);
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

int main(int arc, char **arg)
{
    if (arc == 1)
        no_flag();
    return (0);
}
