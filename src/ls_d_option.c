/*
** EPITECH PROJECT, 2020
** ls_d_option.c
** File description:
** ls -d
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_ls.h"
#include "my.h"

void ls_d(int ac, char **av)
{
    int i = 2;

    if (ac == 2)
        my_printf(".\n");
    else {
        while (i < ac) {
            my_printf("%s ", av[i]);
            i++;
        }
        my_putchar('\n');
    }
}