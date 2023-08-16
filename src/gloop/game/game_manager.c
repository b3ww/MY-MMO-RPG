/*
** EPITECH PROJECT, 2023
** 4_MyMMORPG
** File description:
** game_manager
*/

#include "rpg.h"

#include "destroy.h"
#include "create.h"
#include "tools.h"
#include "network.h"
#include "inv_item_share.h"

static void create_manequin(rpg_t *rpg)
{
    pname_t manequin_name = "Manequin";
    player_t *manequin = create_player_me(rpg->font, manequin_name,
        rpg->file_config.player_class);

    manequin->skin.pclass = LANCEKNIGHT;
    manequin->skin.color = GREEN;
    manequin->move.pos = (v2f_t){900, 500};
    send_player_connect_update(rpg->network, manequin, PLAYER_CONNECTION,
        rpg->map->id);
    destroy_player(manequin);
}

static void get_base_stats_csv(player_t *p, wcsv_t *pcsv)
{
    char *class = get_pclass_str(p->skin.pclass);

    p->fight.range_type = get_csv_value(pcsv, class, "range_type");
    p->fight.range = get_csv_value(pcsv, class, "range");
    p->fight.attack_damage = get_csv_value(pcsv, class, "attack_damage");
    p->fight.attack_speed = (float)get_csv_value(pcsv, class, "attack_speed")
        / 100;
    p->fight.projectile_speed = get_csv_value(pcsv, class, "projectile_speed");
    p->move.speed = get_csv_value(pcsv, class, "movement_speed");
    p->stats.max_health = get_csv_value(pcsv, class, "max_health");
    p->stats.health = p->stats.max_health;
    p->stats.max_mana = get_csv_value(pcsv, class, "max_mana");
    p->stats.mana = p->stats.max_mana;
    p->stats.regen = get_csv_value(pcsv, class, "regen");
}

static bool connect_network(rpg_t *rpg)
{
    if (rpg->network == NULL) {
        if (GET_CLOCK_SEC(rpg->timeout_clock) > 1) {
            rpg->scene = LAUNCHER;
            sfClock_destroy(rpg->timeout_clock);
            return true;
        }
        if (!(rpg->network = create_network(rpg->server_ip_address,
        rpg->server_port)))
            return true;
        get_base_stats_csv(rpg->players[0], rpg->file_config.player_class);
        rpg->copy_player.speed = rpg->players[0]->move.speed;
        rpg->copy_player.attack_damage = rpg->players[0]->fight.attack_damage;
        rpg->copy_player.health = rpg->players[0]->stats.health;
        send_player_connect_update(rpg->network, rpg->players[0],
            PLAYER_CONNECTION, rpg->map->id);
        if (0)
            create_manequin(rpg);
    }
    return false;
}

void game_manager(rpg_t *rpg)
{
    game_event_manager(rpg);
    if (connect_network(rpg))
        return;
    game_update_manager(rpg);
    game_draw_manager(rpg);
}
