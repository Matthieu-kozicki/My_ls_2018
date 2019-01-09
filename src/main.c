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
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

int parser(int arc, char **arg)
{
    if (arg[1][0] != '-')
        no_flag_path(arg[1]);
    if (arg[1][1] == 'a')
        flag_a(arg[2]);
    if (arg[1][1] == 'd')
        flag_d(arg[2]);
    if (arg[1][1] == 'l')
        flag_l(arc, arg);
}

int main(int arc, char **arg)
{
    if (arc == 1)
        no_flag();
    else {
        parser(arc, arg);
    }
    return (0);
}
