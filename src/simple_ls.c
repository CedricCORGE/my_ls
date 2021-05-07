/*
** EPITECH PROJECT, 2020
** simple_ls.c
** File description:
** ls with specific directory
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int check_file(char *av)
{
    struct stat s;
    struct stat s2;
    DIR *directory;

    stat(av, &s);
    if ((S_IFMT & (s.st_mode)) == S_IFDIR) {
        directory = opendir(av);
        if (directory == NULL) {
            perror("ls");
            exit(84);
        }
        closedir(directory);
        return (0);
    } else {
        if (stat(av, &s2) == -1) {
            perror("ls");
            exit(84);
        }
        return (1);
    }
}

void multiple_dir2(char *av)
{
    struct dirent *dirent;
    DIR* directory;

    directory = opendir(av);
    if (directory == NULL) {
        perror("my_ls");
        exit(84);
    }
    dirent = readdir(directory);
    my_printf("%s:\n", av);
    while (dirent != 0) {
        if (dirent->d_name[0] != '.')
            my_printf("%s ", dirent->d_name);
        dirent = readdir(directory);
    }
}

void multiple_dir(int ac, char **av)
{
    int i = 1;

    while (i < ac) {
        if (i > 1)
            my_putchar('\n');
        if (check_file(av[i]) != 1) {
            multiple_dir2(av[i]);
            my_putchar('\n');
            i++;
        } else {
            my_printf("%s ", av[i]);
            i++;
            my_putchar('\n');
        }
    }
}

void simple_ls(int ac, char **av)
{
    struct dirent *dirent;
    DIR* directory;

    if (ac == 2) {
        if (check_file(av[1]) != 1) {
            directory = opendir(av[1]);
            if (directory == NULL) {
                perror("ls");
                exit(84);
            }
            while ((dirent = readdir(directory)) != 0) {
                if (dirent->d_name[0] != '.')
                    my_printf("%s ", dirent->d_name);
            }
            my_putchar('\n');
        } else
            my_printf("%s\n", av[1]);
    } else {
        multiple_dir(ac, av);
    }
}