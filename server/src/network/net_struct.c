/*
** EPITECH PROJECT, 2023
** MMOPRG_ONLINE [SSH]
** File description:
** net_struct
*/

#include <stdio.h>
#include "wnetcsfml.h"

static FILE *get_log_file(void)
{
    FILE *log_file_ret = NULL;

    if (!(log_file_ret = fopen(".log", "a")))
        return NULL;
    return log_file_ret;
}

main_net_t *init_net_struct(uss_t port, int number_max_of_clients)
{
    main_net_t *ret = malloc(sizeof(main_net_t));

    ret->listener = sfTcpListener_create();
    ret->selector = sfSocketSelector_create();
    ret->clients = malloc(sizeof(client_t) * number_max_of_clients);
    for (int i = 0; i < number_max_of_clients; i++) {
        ret->clients[i].to_read = false;
    }
    ret->listen_address = sfIpAddress_Any;
    ret->listen_port = port;
    ret->num_clients = 0;
    ret->log_file = get_log_file();
    if (!ret->log_file)
        return NULL;
    return ret;
}

void destroy_net_struct(main_net_t *net, int number_max_of_clients)
{
    sfSocketSelector_destroy(net->selector);
    sfTcpListener_destroy(net->listener);
    free(net->clients);
}
