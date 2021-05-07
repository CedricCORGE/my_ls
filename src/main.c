/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include <sys/types.h>
#include <dirent.h>
#include "my_ls.h"
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int i = 1;
    int indic = 0;
    my_ls *ls = malloc(sizeof(my_ls));

    if (ls == NULL)
        return (84);
    if (ac == 1) {
        no_option_ls(opendir("./"));
        return (0);
    }
    while (i < ac) {
        if (av[i][0] == '-')
            indic = get_option(av[i], ls);
        i++;
    }
    if (indic == -1)
        return (84);
    call_function(ac, av, ls);
    return (0);
}