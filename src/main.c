/*
** EPITECH PROJECT, 2022
** main
** File description:
** EXECUTE CODE
*/

#include <time.h>
#include "rpg.h"
#include "destroy.h"
#include "create.h"
#include "tools.h"

int main(int ac, char **av)
{
    rpg_t *rpg;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return 0;
    }
    srand(time(NULL));
    rpg = create_manager();
    gloop(rpg);
    destroy_manager(rpg);
    return 0;
}
