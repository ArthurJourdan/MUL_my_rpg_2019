/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** global.h
*/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "time.h"
#include <SFML/Audio.h>

#include "maps.h"

typedef struct global_vars {
    sfRenderWindow *window;
    size_t fps;
    size_t volume;
    gui_t *scene_list;
    maps_t **maps;
    // game_t *game;
} global_t;


void destroy_game(global_t *global);

#endif /* !GLOBAL_H */