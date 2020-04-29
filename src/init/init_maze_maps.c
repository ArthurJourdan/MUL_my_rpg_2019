/*
** EPITECH PROJECT, 2020
** init_maze_maps.c
** File description:
** initialize the maze_map strust
*/

#include "my_rpg.h"

void init_maze_map(global_t *global)
{
    char **temp = maze_main();

    GGLMM = malloc(sizeof(char *) * 8);
    for (int i = 0; i != 7; i++) {
        GGLMM[i] = malloc(sizeof(char) * 8);
        for (int j = 0; j != 7; j++) {
            GGLMM[i][j] = temp[i + 2][j + 2];
        }
        GGLMM[i][7] = '\0';
    }
    GGLMM[7] = NULL;
    for (size_t i = 0; GGLMM[i]; i++) {
        for (size_t j = 0; GGLMM[i][j]; j++)
            printf("%c", GGLMM[i][j]);
        printf("\n");
    }
}