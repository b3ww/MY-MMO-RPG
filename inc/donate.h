/*
** EPITECH PROJECT, 2023
** My_MMORPG
** File description:
** donate
*/

#pragma once

#ifdef _WIN32
    #define DONATE_LINK "start https://www.paypal.me/antoineesman/2"
#elif __APPLE__
    #define DONATE_LINK "open https://www.paypal.me/antoineesman/20"
#else
    #define DONATE_LINK "xdg-open https://www.paypal.me/antoineesman/5"
#endif
