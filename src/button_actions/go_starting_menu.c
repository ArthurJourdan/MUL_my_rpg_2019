/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** go_starting_menu.c
*/

#include "global.h"
#include "gui.h"

global_t *go_starting_menu(global_t *global)
{
    change_scene(GS, HOME);
    return global;
}