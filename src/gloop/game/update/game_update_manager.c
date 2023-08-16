/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** game_update_manager
*/

#include "rpg.h"
#include "network.h"
#include "rpg_particles.h"
#include "colors.h"
#include "destroy.h"
#include "inv_item_share.h"
#include "screen_effect.h"

void update_mouse(rpg_t *rpg)
{
    int id;
    v2f_t pos = sfSprite_getPosition(rpg->cursor->sprite);

    sfSprite_setColor(rpg->cursor->sprite, sfWhite);
    rpg->target_player = NULL;
    if (rpg->cursor->drag) {
        if (rpg->cursor->drag->type == UNCONSO)
            sfSprite_setPosition(rpg->cursor->drag->slots->unconso->sprite,
                (v2f_t){pos.x - 32, pos.y - 32});
        else
            sfSprite_setPosition(rpg->cursor->drag->slots->conso->sprite,
                (v2f_t){pos.x - 32, pos.y - 32});
    }
    for (int i = rpg->player_count - 1; i > 0; i--) {
        id = mouse_on_player(rpg->players[0], rpg->players[i], rpg->mpos);
        if (id != -1) {
            sfSprite_setColor(rpg->cursor->sprite, LIGHT_RED);
            rpg->target_player = rpg->players[i];
        }
    }
}

static void reset_me_launcher(player_t *me)
{
    me->stats.health = me->stats.max_health;
    me->skin.anim_state = IDLE_STATE;
    me->skin.anim_rect.top = 0;
    me->fight.kill_count = 0;
    sfSprite_setTextureRect(me->skin.sprite, me->skin.anim_rect);
    sfSprite_setPosition(me->skin.sprite,
        (v2f_t){LAUNCHER_PLAYER_POS});
    me->fight.target = NULL;
    destroy_anims(me->anims);
    me->anims = NULL;
}

static void reset_to_launcher(rpg_t *rpg)
{
    rpg->scene = LAUNCHER;
    destroy_network(rpg->network);
    rpg->network = NULL;
    for (int i = 1; i < rpg->player_count; i++)
        destroy_player(rpg->players[i]);
    rpg->player_count = 1;
    destroy_map(rpg->map);
    rpg->map = NULL;
    reset_me_launcher(rpg->players[0]);
    rpg->target_player = NULL;
    play_music(rpg->audio_manager, "menu");
}

void update_chat(chat_t *chat)
{
    float pass = sfTime_asSeconds(sfClock_getElapsedTime(chat->clock));
    int op = sfRectangleShape_getFillColor(chat->backgound).a;
    sfColor ct = sfText_getFillColor(chat->history_display);

    if (pass > 0.1) {
        sfRectangleShape_setFillColor(chat-> backgound,
            sfColor_fromRGBA(0, 0, 0, op - 1));
        sfText_setColor(chat->history_display,
            sfColor_fromRGBA(ct.r, ct.g, ct.b, ct.a - 0.5));
        sfText_setColor(chat->input_display,
            sfColor_fromRGBA(ct.r, ct.g, ct.b, ct.a - 0.5));
        if (op < 30) {
            chat->to_display = false;
            sfRectangleShape_setFillColor(chat->backgound,
            sfColor_fromRGBA(0, 0, 0, 150));
        }
        sfClock_restart(chat->clock);
    }
}

void game_update_manager(rpg_t *rpg)
{
    update_mouse(rpg);
    if (update_network(rpg->network) || apply_received(rpg) ||
    send_death_signal(rpg->players[0], rpg->network)) {
        reset_to_launcher(rpg);
        return;
    }
    for (int i = 0; i < rpg->player_count; i++) {
        update_player(rpg->players[i], rpg->dt, rpg->anims_props,
            rpg->map->hitboxes);
        update_portals(rpg->map->portals, rpg->players[i], rpg);
    }
    update_capy(rpg->npc);
    update_me_health(rpg->network, rpg->players[0]);
    if (rpg->players[0]->move.chest != NULL)
        try_open_chest(rpg);
    update_anims(&rpg->anims, rpg->dt);
    update_ftb(rpg->fade_to_black, rpg);
    update_hud(rpg->hud, rpg->players[0]);
    button_manager(rpg, rpg->game);
    update_chat(rpg->chat);
}
