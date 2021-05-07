/*
** EPITECH PROJECT, 2020
** sort_dir.c
** File description:
** sort dir
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"

void sort_dir(DIR *directory)
{
    int i = 0;
    char *stock = malloc(sizeof(char) * 1000);
    char *str;
    char **stock2;
    struct dirent *dirent;

    while ((dirent = readdir(directory)) != 0) {
        if (dirent->d_name[0] != '.') {
            str = my_strcat(dirent->d_name, "/");
            stock = my_strcat(stock, str);
            i++;
        }
    }
    stock2 = my_str_to_word_array(stock);
    for (; i - 1 >= 0; i--) {
        my_printf("%s ", stock2[i - 1]);
    }
    my_printf("\n");
}