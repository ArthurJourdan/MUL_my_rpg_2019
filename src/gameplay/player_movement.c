/*
** EPITECH PROJECT, 2020
** player_movement.c
** File description:
** player movements manager
*/

#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include "my_rpg.h"
#include "sfml_tools.h"

void line_player_deplacement(global_t *global)
{
    if (GGPC.on_up && !GGPC.on_left &&
        !GGPC.on_down && !GGPC.on_right) {
        GGP.pos.y -= GGP.speed;
    }
    if (!GGPC.on_up && GGPC.on_left &&
        !GGPC.on_down && !GGPC.on_right) {
        GGP.pos.x -= GGP.speed;
    }
    if (!GGPC.on_up && !GGPC.on_left &&
        GGPC.on_down && !GGPC.on_right) {
        GGP.pos.y += GGP.speed;
    }
    if (!GGPC.on_up && !GGPC.on_left &&
        !GGPC.on_down && GGPC.on_right) {
        GGP.pos.x += GGP.speed;
    }
}

void diag_player_deplacement(global_t *global)
{
    if (GGPC.on_up && GGPC.on_left) {
        GGP.pos.y -= sin(M_PI / 4) * GGP.speed;
        GGP.pos.x -= cos(M_PI / 4) * GGP.speed;
    }
    if (GGPC.on_left && GGPC.on_down) {
        GGP.pos.y += sin(M_PI / 4) * GGP.speed;
        GGP.pos.x -= cos(M_PI / 4) * GGP.speed;
    }
    if (GGPC.on_down && GGPC.on_right) {
        GGP.pos.y += sin(M_PI / 4) * GGP.speed;
        GGP.pos.x += cos(M_PI / 4) * GGP.speed;
    }
    if (GGPC.on_right && GGPC.on_up) {
        GGP.pos.y -= sin(M_PI / 4) * GGP.speed;
        GGP.pos.x += cos(M_PI / 4) * GGP.speed;
    }
}

void player_key_pressed(global_t *global)
{
    if (sfKeyboard_isKeyPressed(GGPC.up)) {
        GGPC.on_up = true;
        GGP.sprite = GGP.ss[3][GGP.frame];
    } else
        GGPC.on_up = false;
    if (sfKeyboard_isKeyPressed(GGPC.left)) {
        GGPC.on_left = true;
        GGP.sprite = GGP.ss[1][GGP.frame];
    } else
        GGPC.on_left = false;
    if (sfKeyboard_isKeyPressed(GGPC.down)) {
        GGPC.on_down = true;
        GGP.sprite = GGP.ss[0][GGP.frame];
    } else
        GGPC.on_down = false;
    if (sfKeyboard_isKeyPressed(GGPC.right)) {
        GGPC.on_right = true;
        GGP.sprite = GGP.ss[2][GGP.frame];
    } else
        GGPC.on_right = false;
}

void check_next_pos(global_t *global, sfVector2f *next_pos)
{
    if (GGPC.on_up)
        next_pos->y = (GGP.pos.y - GGP.speed) - GGP.hitbox;
    if (GGPC.on_down)
        next_pos->y = (GGP.pos.y + GGP.speed) + GGP.hitbox;
    if (GGPC.on_left)
        next_pos->x = (GGP.pos.x - GGP.speed) - GGP.hitbox;
    if (GGPC.on_right)
        next_pos->x = (GGP.pos.x + GGP.speed) + GGP.hitbox;
    if (next_pos->x < 0)
        next_pos->x = 0;
    if (next_pos->y < 0)
        next_pos->y = 0;
    if (next_pos->x > GGW)
        next_pos->x = GGW;
    if (next_pos->y > GGH)
        next_pos->y = GGH;
}

void player_movements(global_t *global)
{
    sfVector2f next_pos = {GGP.pos.x, GGP.pos.y};
    sfColor color;
    sfVector2f next;
    sfVector2f relat;

    player_key_pressed(global);
    check_next_pos(global, &next_pos);
    move_check(next_pos, global);
    swap_map(next_pos, global);
    relat = sfV2F{next_pos.x - GGP.pos.x, next_pos.y - GGP.pos.y};
    next = sfV2F{next_pos.x + SIGN(relat.x) * 165, next_pos.y + SIGN(relat.y) * 165};
    next = sfV2F{((next.x > 0) ? next.x : 1), ((next.y > 0) ? next.y : 1)};
    next = sfV2F{((next.x < GGW) ? next.x : GGW - 1),
                        ((next.y < GGH) ? next.y : GGH - 1)};
    color = sfImage_getPixel(GGLMM[GGLP.y][GGLP.x].coll,
                             next.x * (float)1650 / (float)GGW,
                             next.y * (float)990 / (float)GGH);
    player_dash(next_pos, global, color);
    GGP.collider->left = GGP.pos.x;
    GGP.collider->top = GGP.pos.y;
}
