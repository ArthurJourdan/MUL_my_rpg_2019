/*
** EPITECH PROJECT, 2020
** add_spell
** File description:
** add a spell to the inventory
*/

#include "my_rpg.h"
#include "rpg_structs.h"
#include "sfml_tools.h"
#include "file.h"
#include "player.h"

extern const spell1;
extern const spell2;

void add_spell(player_t *player, game_t *game, int spell_id, int spell_nb)
{
    if (spell_nb == 0) {
        player->p_invent->spell_nodes[spell_nb]->spell_id = spell_id;
        player->p_invent->spell_nodes[spell_nb]->key = spell1;
    } else if(spell_nb == 1) {
        player->p_invent->spell_nodes[spell_nb]->spell_id = spell_id;
        player->p_invent->spell_nodes[spell_nb]->key = spell2;
    }
    player->p_invent->nb_spells++;
}

void check_spell(global_t *global, int spell_id, player_t *player)
{
    int replace = 0;

    if (player->p_invent->nb_spells == 2) {
        replace = show_replace(global);
        if (!replace) {
            add_spell(player, &GG, spell_id, replace - 1);
            return;
        } else
            return;
    }
    if (!show_pickup(global))
        return;
    else
        add_spell(player, &GG, spell_id, player->p_invent->nb_spells);
}
