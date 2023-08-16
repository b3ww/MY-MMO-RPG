/*
** EPITECH PROJECT, 2022
** v2f_operations.h
** File description:
** V2F_OPERATIONS
*/

#ifndef V2F_OPERATIONS
    #define V2F_OPERATIONS

    #include "rpg.h"

v2f_t v2i_to_v2f(v2i_t vector_i);
v2f_t float_multiply_v2f(v2f_t v, float x);
v2f_t float_add_v2f(v2f_t v, float x);
v2f_t add_two_v2f(v2f_t v1, v2f_t v2);
float vector_norm(v2f_t vector);

#endif /* !V2F_OPERATIONS */
