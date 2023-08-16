/*
** EPITECH PROJECT, 2023
** ParticleManager
** File description:
** render_animation
*/

#include "particle.h"
#include <SFML/Graphics/RenderWindow.h>

static void draw_shape(sfRenderWindow *win, shape_type_t shape_type,
shape_union_t shape)
{
    switch (shape_type) {
    case RECT_OUTLINE: case RECT:
        sfRenderWindow_drawRectangleShape(win, shape.rect, NULL);
        break;
    case CIRCLE_OUTLINE: case CIRCLE:
        sfRenderWindow_drawCircleShape(win, shape.circle, NULL);
        break;
    case SPRITE_CENTER: case SPRITE:
        sfRenderWindow_drawSprite(win, shape.sprite, NULL);
        break;
    default:
        break;
    }
}

void anim_draw(sfRenderWindow *win, anim_t *anim)
{
    particles_t *particle;

    if (anim == NULL)
        return;
    particle = anim->particles;
    if (anim->show_zones) {
        sfRenderWindow_drawRectangleShape(win, anim->shape_start->body.rect,
            NULL);
        if (anim->shape_end->type != MIRROR)
            sfRenderWindow_drawRectangleShape(win, anim->shape_end->body.rect,
                NULL);
    }
    for (; particle != NULL; particle = particle->next) {
        if (particle->arrived)
            continue;
        draw_shape(win, particle->shape_type, particle->shape);
    }
}
