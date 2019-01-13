/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** flag l
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

void print_date(char *str)
{
    my_putchar(str[4]);
    my_putchar(str[5]);
    my_putchar(str[6]);
    my_putchar(' ');
    my_putchar(str[8]);
    my_putchar(str[9]);
    my_putchar(' ');
    my_putchar(str[11]);
    my_putchar(str[12]);
    my_putchar(str[13]);
    my_putchar(str[14]);
    my_putchar(str[15]);
    my_putchar(' ');
}

void print_info2(char *str)
{
    struct stat file;
    struct passwd *pwd;
    struct group *grp;
    char *time;

    if(stat(str, &file) == 0) {
        print_right(file);
        pwd = getpwuid(file.st_uid);
        grp = getgrgid(file.st_gid);
        my_printf("%d %s ", file.st_nlink, pwd->pw_name);
        my_printf("%s %d ", grp->gr_name, file.st_size);
        time = ctime(&(file.st_mtim.tv_sec));
        print_date(time);
        my_printf("%s",str);
    }
    else
        my_printf("No such file or directory");
}

void print_info(char *str, int arc, char **arg)
{
    struct stat file;
    struct passwd *pwd;
    struct group *grp;
    char *time;
    char *path;

    path = melt(arg[2], str);
    stat(path, &file);
    print_right(file);
    pwd = getpwuid(file.st_uid);
    grp = getgrgid(file.st_gid);
    my_printf("%d %s ", file.st_nlink, pwd->pw_name);
    my_printf("%s %d ", grp->gr_name, file.st_size);
    time = ctime(&(file.st_mtim.tv_sec));
    print_date(time);
    free(path);
}

void flag_l_here(int arc, char **arg)
{
    struct dirent *file;
    DIR *rep;

    total_here(arg);
    rep = opendir(".");
    while (file = readdir(rep)) {
        if (file->d_name[0] != '.') {
            print_info2(file->d_name);
            my_printf("\n");
        }
    }
    closedir(rep);
}

void flag_l(int arc, char **arg)
{
    struct dirent *file;
    DIR *rep;

    rep = opendir(arg[2]);
    if (rep == NULL) {
        print_info2(arg[2]);
        my_putchar('\n');
    }
    else {
        total_path(arg);
        while (file = readdir(rep)) {
            if (file->d_name[0] != '.') {
                print_info(file->d_name, arc, arg);
                my_printf("%s\n",file->d_name);
            }
        }
    }
    closedir(rep);
}
