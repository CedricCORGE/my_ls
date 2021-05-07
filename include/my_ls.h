/*
** EPITECH PROJECT, 2020
** my_ls.h
** File description:
** my_ls header
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct option my_ls;

struct option
{
    int l;
    int r;
    int R;
    int d;
    int t;
};

void no_option_ls(DIR *directory);

void ls_l(int ac, char **av, DIR *directory);

void ls_l_spec(int ac, char **av);

void ls_d(int ac, char **av);

void ls_r(int ac, char **av);

void sort_dir(DIR *directory);

char *check_pathname(char *av);

void right_print(struct stat *s);

void type_print(struct stat *s);

void simple_ls(int ac, char **av);

void print_l_spe(char *path);

void print_l_init(char *stock, struct dirent *dirent, int indic);

void print_total(char *av);

void call_function(int ac, char **av, my_ls *ls);

void print_time(struct stat *s);

int check_file(char *av);

int get_option(char *str, my_ls *ls);

#endif /* !MY_LS_H_ */
