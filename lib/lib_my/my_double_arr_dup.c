/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** double_arr_dup.c
*/

#include "my.h"

char **double_char_arrcpy(char **src, bool free)
{
    size_t len = my_arrlen(src);
    char **dup = malloc(sizeof(char *) * (len + 1));

    if (!dup)
        len = 0;
    for (size_t a = 0; a < len; a++) {
        dup[a] = my_strcpy(src[a]);
    }
    dup[len] = NULL;
    if (free)
        free_double_char_arr(src);
    return dup;
}
