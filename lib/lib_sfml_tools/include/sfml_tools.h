/*
** EPITECH PROJECT, 2020
** SFML lib
** File description:
** sfml_tools.h
*/

#ifndef SFML_TOOLS_H
#define SFML_TOOLS_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

// WINDOW
sfRenderWindow *create_window(unsigned int width, unsigned int height,
unsigned int bbp, char const *name);
// !WINDOW

// SPRITE
sfSprite *create_image(sfSprite *sprite, char const *filepath);
sfSprite *create_image_fullscreen(sfSprite *sprite, sfRenderWindow *window,
char const *filepath);

void set_sprite_fullscreen(sfRenderWindow *window, sfSprite *sprite);
void set_sprite_arr_fullscreen(sfRenderWindow *window, sfSprite **sprites);

void display_one_sprite(sfRenderWindow *window, sfSprite *sprite);
void display_images(sfRenderWindow *window, sfSprite **images);
// !SPRITE

// RECTANGLESHAPE
sfRectangleShape *create_rectshape(sfRectangleShape *rect, sfVector2f size);

void add_texture_RectShape(sfRectangleShape *rect, char *filepath);
void set_rectshape_color(sfRectangleShape *rectshape,
sfColor in, sfColor out, float outline_thickness);
// !RECTANGLESHAPE

// TEXT
sfText *create_text(sfText *text, char *str, char *font, int size);

void display_texts(sfRenderWindow *window, sfText **texts);
// !TEXT

// SOUND
sfSound *create_sound(sfSound *sound, char *filepath, float volume);

void change_sound_volume(sfSound *sound, float increase);
void set_sound_volume(sfSound *sound, float volume);
// !SOUND

// MUSIC
void set_music_volume(sfMusic *music, float volume);
void change_music_volume(sfMusic *music, float increase);


// !MUSIC

#endif /* !SFML_TOOLS_H */