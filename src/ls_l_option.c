/*
** EPITECH PROJECT, 2020
** ls_l_option.c
** File description:
** option -l for ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include "my_ls.h"
#include <errno.h>
#include <stdio.h>
#include "my.h"

void print_total(char *av)
{
    struct stat s;
    struct dirent *dirent;
    int stock = 0;
    char *path;
    DIR *directory = opendir(av);

    if (directory == NULL)
        exit(84);
    while ((dirent = readdir(directory)) != 0) {
        if (dirent->d_name[0] != '.') {
            path = malloc(sizeof(char) * \
(my_strlen(av) + my_strlen(dirent->d_name) + 1));
            my_strcpy(path, av);
            my_strcat(path, dirent->d_name);
            lstat(path, &s);
            stock += s.st_blocks;
            free(path);
        }
    }
    my_printf("total %d\n", stock / 2);
    closedir(directory);
}

void print_l(char *path, struct dirent *dirent, int indic)
{
    struct stat s;
    struct passwd *pw;
    struct group *grp;

    lstat(path, &s);
    type_print(&s);
    right_print(&s);
    my_printf(". %d", s.st_nlink);
    pw = getpwuid(s.st_uid);
    my_printf(" %s", pw->pw_name);
    grp = getgrgid(s.st_gid);
    my_printf(" %s", grp->gr_name);
    my_printf(" %lu ", s.st_size);
    print_time(&s);
    if (indic == 1)
        my_printf(" %s\n", dirent->d_name);
    else
        my_printf(" %s\n", path);
}

void print_l_init(char *stock, struct dirent *dirent, int indic)
{
    char *path;

    if (dirent != NULL)
        path = malloc(sizeof(char) * \
(my_strlen(stock) + my_strlen(dirent->d_name) + 1));
    else
        path = malloc(sizeof(char) * (my_strlen(stock) + 1));
    if (indic == 1) {
        my_strcpy(path, stock);
        my_strcat(path, dirent->d_name);
    } else if (indic == 2)
        my_strcpy(path, stock);
    else
        my_strcpy(path, dirent->d_name);
    print_l(path, dirent, indic);
    free(path);
}

void ls_l_spe(int ac, char **av)
{
    char *path;

    for (int i = 2; i < ac; i++) {
        path = check_pathname(av[i]);
        if (i > 2 && ((check_file(path) != 1) || i == 3))
            my_putchar('\n');
        if (ac > 3 && (check_file(path) != 1))
            my_printf("%s:\n", av[i]);
        if (check_file(path) != 1) {
            print_l_spe(path);
        } else
            print_l_init(path, NULL, 2);
        free(path);
    }
}

void ls_l(int ac, char **av, DIR *directory)
{
    struct dirent *dirent;

    if (ac == 2) {
        print_total("./");
        while ((dirent = readdir(directory)) != 0) {
            if (dirent->d_name[0] != '.') {
                print_l("", dirent, 0);
            }
        }
    } else {
        ls_l_spe(ac, av);
    }
}