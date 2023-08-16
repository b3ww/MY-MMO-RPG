/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** mainlopp
*/

#include "rpg_online_manager.h"
#include "wnetcsfml.h"

static bool net_wait(main_net_t *net, int mps)
{
    if (sfSocketSelector_wait(net->selector, sfMicroseconds(mps)) ==
    sfSocketError) {
        WLOG("Erreur d'attente sur le socket selecteur", net->log_file);
        return false;
    }
    return true;
}

int w_netloop(uss_t port, int ms, void own_update(main_net_t *, void *))
{
    main_net_t *net = init_net_struct(port, 50);
    manager_t *manager = init_manager();

    if (selector_is_ready(net) || !net)
        sfSocketSelector_addTcpListener(net->selector, net->listener);
    else
        return 0;
    while (true) {
        if (!net_wait(net, ms))
            break;
        if (sfSocketSelector_isTcpListenerReady(net->selector, net->listener))
            get_new_client(net);
        for (int i = 0; i < net->num_clients; i++)
            selector_receive(net, &i);
        own_update(net, manager);
    }
    destroy_net_struct(net, MAX_CLIENTS);
    return 1;
}
