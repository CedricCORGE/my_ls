/*
** EPITECH PROJECT, 2020
** print_l_spe.c
** File description:
** print l
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "my_ls.h"

void print_l_spe(char *path)
{
    char *stock2;
    struct dirent *dirent;
    DIR *directory;

    print_total(path);
    directory = opendir(path);
    while ((dirent = readdir(directory)) != 0) {
        stock2 = my_strdup(path);
        if (dirent->d_name[0] != '.')
            print_l_init(stock2, dirent, 1);
        free(stock2);
        }
    closedir(directory);
}