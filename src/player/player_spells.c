/*
** EPITECH PROJECT, 2020
** player_spells
** File description:
** player_spells
*/

#include "my_rpg.h"

void move_spell(global_t *global, int i)
{
    GGO->s_obj[i].pos.x += GGO->s_obj[i].speed.x;
    GGO->s_obj[i].pos.y += GGO->s_obj[i].speed.y;
    if (GGO->s_obj[i].pos.x > GGO->s_obj[i].starting_pos.x + GGO->s_obj[i].range)
        GGO->s_obj[i].obj_status = false;
}

void check_spell_collision(s_obj_t *spell, global_t *global)
{
    if (!GG.e_obj)
        return;
    for (int i = 0; i < 64; i++) {
        if (sfIntRect_intersects(spell->collider,
        &GG.e_obj[i]->collider, NULL)) {
            if (GG.e_obj[i]->hp != 0) {
                GG.e_obj[i]->hp -= GGS[spell->id]->base_damage;
            }
        }
    }

}

void player_spells(global_t *global)
{
    if (!GGS || !GGO)
        return;
    for (int i = 0; i < 2; i++) {
        if (GGO->s_obj[i].obj_status) {
            move_spell(global, i);
            check_spell_collision(&GGO->s_obj[i], global);
        }
    }
}
