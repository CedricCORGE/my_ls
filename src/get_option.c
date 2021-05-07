/*
** EPITECH PROJECT, 2020
** get_option.c
** File description:
** get_option
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_ls.h"
#include "my.h"
#include <stdlib.h>

int get_option(char *str, my_ls *ls)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] == 'l')
            ls->l = 1;
        if (str[i] == 'r')
            ls->r = 1;
        if (str[i] == 'd')
            ls->d = 1;
        if (str[i] == 't')
            ls->t = 1;
        if (str[i] == 'R')
            ls->R = 1;
        if (str[i] != 'R' && str[i] != 't' && str[i] != 'r' && str[i] != 'd' \
&& str[i] != 'l') {
            my_printf("ls : invalid option -- '%s'\n", str);
            return (-1);
        }
        i++;
    }
    return (0);
}