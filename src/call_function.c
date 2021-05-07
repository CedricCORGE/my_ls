/*
** EPITECH PROJECT, 2020
** check_option.c
** File description:
** check_option
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_ls.h"
#include "my.h"

void call_function(int ac, char **av, my_ls *ls)
{
    if (ls->l == 1 && ls->d == 0 && ls->t == 0 && ls->r == 0 \
&& ls->R == 0)
            ls_l(ac, av, opendir("./"));
    if (ls->l == 0 && ls->d == 1 && ls->t == 0 && ls->r == 0 \
&& ls->R == 0)
            ls_d(ac, av);
    if (ls->l == 0 && ls->d == 0 && ls->t == 0 && ls->r == 1 \
&& ls->R == 0)
            ls_r(ac, av);
    if (ls->l == 0 && ls->d == 0 && ls->t == 0 && ls->r == 0 \
&& ls->R == 0)
            simple_ls(ac, av);
}