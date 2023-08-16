##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my lib
##

SRC	=	set/anim_set_id.c \
		set/anim_set_color.c \
		set/anim_set_duration.c \
		set/anim_set_frequency.c \
		set/anim_set_batch_size.c \
		set/anim_set_rotation.c \
		set/anim_set_scale_modifier.c \
		set/anim_set_scale.c \
		set/anim_set_shape_part.c \
		set/anim_set_shape_start.c \
		set/anim_set_shape_end.c \
		set/anim_set_speed.c \
		set/anim_set_is_generating.c \
\
		create/anim_create.c \
		create/anim_append.c \
		create/particle_create/particle_create.c \
		create/particle_create/get_from_circle.c \
		create/particle_create/get_from_rect.c \
		create/particle_create/get_random_pos.c \
		create/particle_create/get_sprite_center.c \
		create/particle_create/set_particle_shape.c \
		create/particle_create/set_particle_movement.c \
		create/particle_create/set_particle_destination.c \
\
		update/anim_update.c \
		update/particle_update/particle_update.c \
		update/particle_update/particle_move_or_ended.c \
		update/particle_update/particle_rotate.c \
\
		anim_props/create_anim_props.c \
		anim_props/append_anim_props.c \
		anim_props/set_anim_props.c \
		anim_props/get_anims_props.c \
\
		draw/anim_draw.c \
\
		utils/v2f_operations.c \
		utils/vector_norm.c \
		utils/get_random_between.c \
		utils/get_delta_time.c \
		utils/is_anim_ended.c \
\
		destroy/destroy_shape.c \
		destroy/destroy_anims.c \
		destroy/anim_destroy.c \
		destroy/destroy_anims_props.c \
		destroy/particle_destroy.c \
		destroy/destroy_particles.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	= -I./ -I../../inc/ -I../../share
NAME	=	libparticle.a
HEADER	=	particle.h
CFLAGS	=	-g3 -c
LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lm

BOLD	=	\e[1m
GREEN	=	\e[92m
WHITE	=	\e[0m
BLUE	=	\e[94m
RED		=	\e[31m

all:	$(NAME)

$(OBJ):	%.o: %.c
	@gcc $(CFLAGS) -o $@ $(INCLUDE) $< $(LDFLAGS)
	@echo -e "$(BOLD)$(BLUE)File $(RED)$@$(BLUE) created.$(WHITE)"

$(NAME):	$(OBJ)
		@mkdir -p ../../inc
		@cp particle.h ../../inc/
		@cp struct_particle.h ../../inc/
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../
		@echo -e "$(BOLD)$(GREEN) -- LIB SUCCESSFULLY COMPILED -- $(WHITE)"

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)
		@rm -f ../$(NAME)

re:	fclean all
