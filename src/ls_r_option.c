/*
** EPITECH PROJECT, 2020
** ls_r_option.c
** File description:
** reverse sort
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "my_ls.h"
#include <unistd.h>

void sort_file(int ac, char **av, int i)
{
    char *str;
    char *stock = malloc(sizeof(char) * 1000);
    char **stock2;
    char *str2;
    int j = 0;

    while (i < ac) {
        if (check_file(av[i]) == 1) {
            str2 = my_strdup(av[i]);
            str = my_strcat(str2, "/");
            stock = my_strcat(stock, str);
            j++;
            i++;
            str2 = NULL;
        } else
            i++;
    }
    stock2 = my_str_to_word_array(stock);
    for (; j - 1 >= 0; j--)
        my_printf("%s ", stock2[j - 1]);
    free (stock);
}

void ls_r_spe3(int ac, char **av, int j)
{
    DIR *directory;
    int indic = 0;

    while (j < ac) {
        if (j > 2 && indic == 0)
            my_putchar('\n');
        if (check_file(av[j]) == 1 && indic == 0) {
            sort_file(ac, av, j);
            indic++;
            my_putchar('\n');
            if (j == 2)
                my_putchar('\n');
        }
        if (check_file(av[j]) == 0) {
            my_printf("%s:\n", av[j]);
            directory = opendir(av[j]);
            sort_dir(directory);
        }
        j++;
    }
}

void ls_r_spe2(int ac, char **av)
{
    if (ac == 3 && (check_file(av[2]) == 1))
        my_printf("%s\n", av[2]);
    else
        ls_r_spe3(ac, av, 2);
}

void ls_r_spe(int ac, char **av)
{
    int i = 0;
    int j = 2;
    DIR *directory = opendir(av[j]);
    struct dirent *dirent;
    char *stock = malloc(sizeof(char) * 1000);
    char *str;
    char **stock2;

    if (ac == 3 && (check_file(av[2]) == 0)) {
        while (j < ac) {
            while ((dirent = readdir(directory)) != 0) {
                if (dirent->d_name[0] != '.') {
                    str = my_strcat(dirent->d_name, "/");
                    stock = my_strcat(stock, str);
                    i++;
                }
            }
            stock2 = my_str_to_word_array(stock);
            for (;i - 1 >= 0; i--)
                my_printf("%s ", stock2[i - 1]);
            my_putchar('\n');
            j++;
        }
    } else
        ls_r_spe2(ac, av);
    free (stock);
}

void ls_r(int ac, char **av)
{
    char *stock = malloc(sizeof(char) * 1000);
    char *str;
    char **stock2;
    int i = 0;
    DIR *directory = opendir("./");
    struct dirent *dirent;

    if (ac == 2) {
        while ((dirent = readdir(directory)) != 0) {
            if (dirent->d_name[0] != '.') {
                str = my_strcat(dirent->d_name, "/");
                stock = my_strcat(stock, str);
                i++;
            }
        }
        stock2 = my_str_to_word_array(stock);
        for (;i - 1 >= 0; i--)
            my_printf("%s ", stock2[i - 1]);
        my_putchar('\n');
    } else
        ls_r_spe(ac, av);
    free(stock);
}