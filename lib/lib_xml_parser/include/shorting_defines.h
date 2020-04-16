/*
** EPITECH PROJECT, 2020
** MUL_my_rpg
** File description:
** shorting_definess.h
*/

#ifndef SHORTING_DEFINES_H
#define SHORTING_DEFINES_H

#define GM global->scene_list
#define GW global->window
#define FPS global->fps
#define GS global->scene_list

#define ACT global->scene_list->index
#define SC_B global->scene_list->scenes[global->scene_list->index]->buttons
#define SC_I global->scene_list->scenes[global->scene_list->index]->images
#define SC_T global->scene_list->scenes[global->scene_list->index]->text
#define SC_S global->scene_list->scenes[global->scene_list->index]->sound

#define SL scene_list->scenes
#define ACT_S scene_list->index

// INIT
#define SCL_O sc_list->scenes[sc_nb]
#define SCL_NB scene_list->scenes[scene_nb]
#define SCL_B scene_list->scenes[scene_nb]->buttons
#define SCL_I scene_list->scenes[scene_nb]->images
#define SCL_T scene_list->scenes[scene_nb]->text

#endif /* !SHORTING_DEFINES_H */