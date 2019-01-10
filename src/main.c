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
    if (arg[1][1] == 'a' && arg[1][0] == '-')
        flag_a(arc, arg);
    if (arg[1][1] == 'd' && arg[1][0] == '-')
        flag_d(arc, arg);
    if (arg[1][1] == 'l' && arg[1][0] == '-' && arc == 3)
        flag_l(arc, arg);
    if (arg[1][1] == 'l' && arg[1][0] == '-' && arc == 2)
        flag_l_here(arc, arg);
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
