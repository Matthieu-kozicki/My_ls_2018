/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** print total
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

void total_path(char **arg)
{
    struct dirent *fil;
    DIR *rep;
    int i = 0;
    int total = 0;
    struct stat files;
    char *path;

    rep = opendir(arg[2]);
    while (fil = readdir(rep)) {
        if (fil->d_name[0] != '.') {
            path = melt(arg[2], fil->d_name);
            stat(path, &files);
            total = total + files.st_blocks;
            i++;
        }
    }
    total = total / 2;
    if (i > 1)
        my_printf("total %d\n",total);
    closedir(rep);
}

void total_here(char **arg)
{
    struct dirent *fil;
    DIR *rep;
    int i = 0;
    int total = 0;
    struct stat files;

    rep = opendir(".");
    while (fil = readdir(rep)) {
        if (fil->d_name[0] != '.') {
            stat(fil->d_name, &files);
            total = total + files.st_blocks;
            i++;
        }
    }
    total = total / 2;
    if (i > 1)
        my_printf("total %d\n",total);
    closedir(rep);
}
