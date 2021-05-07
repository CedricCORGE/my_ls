/*
** EPITECH PROJECT, 2020
** ls_without_option.c
** File description:
** simple ls
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void no_option_ls(DIR *directory)
{
    struct dirent *dirent;

    if (directory == NULL) {
        perror("my_ls");
        exit(84);
    }
    dirent = readdir(directory);
    while (dirent != 0) {
        if (dirent->d_name[0] != '.')
            my_printf("%s ", dirent->d_name);
        dirent = readdir(directory);
    }
    my_putchar('\n');
}