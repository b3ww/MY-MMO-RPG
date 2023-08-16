/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-matthias.von-rakowski [SSH: 193.70.40.62]
** File description:
** items_transfert
*/

#pragma once

    #include "share.h"

typedef struct serv_inv {
    data_type_t *type;
    uss_t id;
    char slots[12][20];
} serv_inv_t;
