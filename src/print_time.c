/*
** EPITECH PROJECT, 2020
** print_time.c
** File description:
** print time
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

void print_time(struct stat *s)
{
    write(1, (ctime(&s->st_mtime) + 4), 12);
}