/*
** EPITECH PROJECT, 2020
** check_pathname.c
** File description:
** check pathname
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char *check_pathname(char *av)
{
    int i = my_strlen(av);
    char *path;
    struct stat s;

    stat(av, &s);
    if (av[i - 1] != '/' && (S_IFMT & (s.st_mode)) == S_IFDIR) {
        path = malloc(sizeof(char) * (i + 1));
        my_strcpy(path, av);
        path[i] = '/';
        path[i + 1] = '\0';
    } else {
        path = malloc(sizeof(char) * (i + 1));
        my_strcpy(path, av);
    }
    return (path);
}