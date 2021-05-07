/*
** EPITECH PROJECT, 2020
** right_print.c
** File description:
** right_print
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void type_print(struct stat *s)
{
    if ((S_IFMT & (s->st_mode)) == S_IFDIR)
        my_putchar('d');
    if ((S_IFMT & (s->st_mode)) == S_IFLNK)
        my_putchar('l');
    if ((S_IFMT & (s->st_mode)) == S_IFCHR)
        my_putchar('c');
    if ((S_IFMT & (s->st_mode)) == S_IFREG)
        my_putchar('-');
    if ((S_IFMT & (s->st_mode)) == S_IFBLK)
        my_putchar('b');
    if ((S_IFMT & (s->st_mode)) == S_IFIFO)
        my_putchar('p');
    if ((S_IFMT & (s->st_mode)) == S_IFSOCK)
        my_putchar('s');
}

void right_print(struct stat *s)
{
    (s->st_mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (s->st_mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (s->st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (s->st_mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (s->st_mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (s->st_mode & S_IXGRP) ? my_putchar('x') : my_putchar('-');
    (s->st_mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (s->st_mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    (s->st_mode & S_IXOTH) ? my_putchar('x') : my_putchar('-');
}