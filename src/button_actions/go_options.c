/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** go_options.c
*/

#include "global.h"
#include "gui.h"

global_t *go_options(global_t *global)
{
    change_scene(GS, OPTIONS);
    return global;
}