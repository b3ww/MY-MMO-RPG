##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my cat
##

NAME	=	my_rpg

SRC	=	$(SRCDIR)/main.c \
		$(GLOOPDIR)/gloop.c \
		$(GAMEDIR)/game_manager.c \
		$(LAUNCHERDIR)/launcher_manager.c \
		$(SETTINGSDIR)/settings_manager.c \
\
		splash_manager.c \
		splash_update.c \
		splash_draw.c \
\
		create_manager.c \
		set_rpg_necessary.c \
		create_window.c \
		create_cursor.c \
		create_chat.c \
		player/create_player_me.c \
		player/create_player_health_bar.c \
		player/set_player_client.c \
		player/set_skin.c \
		create_draw_text.c \
		create_button.c \
		create_network.c \
		create_scene_launcher.c \
		create_scene_launcher_ip_port.c \
		create_text.c \
		create_inventory.c \
		create_fade_to_black.c \
		create_npc.c \
		create_portals.c \
		create_chest.c \
		create_settings.c \
		create_scene_game.c \
		create_item.c \
		create_audio.c \
		create_audio_manager.c \
		create_splash.c \
		load_textures.c \
		item_manage.c \
		anims/create_anims_props_list.c \
		anim_rain.c \
		anim_spawn.c \
		anim_smoke.c \
		anim_splash_smoke.c \
		adjust_spawn_anim.c \
		anim_arrow.c \
		anim_go_to.c \
		load_map.c \
		stack.c \
		adjust_go_to_anim.c \
		create_hud.c \
\
		destroy_manager.c \
		destroy_chat.c \
		destroy_cursor.c \
		destroy_map.c \
		destroy_network.c \
		destroy_player_client.c \
		destroy_launcher.c\
		destroy_text.c \
		destroy_settings.c \
		destroy_button.c \
		destroy_inventory.c \
		destroy_item.c \
		destroy_scene_game.c \
		destroy_audio_manager.c \
		destroy_textures.c \
		destroy_portals.c \
		destroy_fade_to_black.c \
		destroy_csv.c \
		destroy_npc.c \
		destroy_hud.c \
		destroy_splash.c \
		my_freetab.c \
\
		get_delta_t.c \
		center_circle_origin.c \
		center_sprite.c \
		get_color.c \
		get_distance.c \
		create_player_id.c \
		get_texture_from_id.c \
		get_csv_value.c \
		get_pclass_str.c \
		my_putstr.c \
		my_getnbr.c \
		my_strlen.c \
		my_strcpy.c \
		my_strcmp.c \
		my_strdup.c \
		my_strcat.c \
		my_strnbr.c \
		wstr_to_word_array.c \
		skipws.c \
		tabcpy.c \
		print_help.c \
		v2f_operations.c \
\
		gloop_event.c \
		gloop_update.c \
		update_chat.c \
		move_cursor.c \
\
		game_event_manager.c \
		player/reload_player_skin.c \
		player/get_player_id.c \
		player/set_player_class.c \
		player/set_player_direction.c \
		player/set_player_velocity.c \
		player/actions/move_player_and_send.c \
		network/send_player_connect_update.c \
		mouse/mouse.c \
		mouse/manage_mouse_move.c \
		mouse/manage_mouse_pressed.c \
		mouse/mouse_pressed_chest.c \
		mouse/manage_mouse_released.c \
		mouse/manage_mouse_npc.c \
		mouse/manage_mouse_inventory.c \
		try_open_chest.c \
		keys.c \
\
		game_update_manager.c \
		portals/update_portals.c \
		portals/animate_portal.c \
		update_ftb.c \
		update_capy.c \
		update_hud.c \
		buttons/game_update_button.c \
		buttons/game_update_button_continues.c \
		load_chest.c \
		spawn_chest_when_kill.c \
		player/update_player.c \
		player/update_player_portal.c \
		player/move_player.c \
		player/mouse_on_player.c \
		player/player_send_attack.c \
		player/update_me_health.c \
		player/send_death_signal.c \
		player/spawn_player.c \
		player/calculate_velocity.c \
		player/attack_or_move.c \
		player/move_player_ui.c \
		player/animate_player.c \
		network/update_network.c \
		network/send_to_server.c \
		network/apply_received.c \
		network/apply_move.c \
		network/apply_player_connection.c \
		network/apply_player_update.c \
		network/remove_player_in_list.c \
		network/setup_connected_players.c \
		network/update_player_health.c \
		anims/update_anims.c \
		anims/end_smoke.c \
		update_buttons.c \
\
		game_draw_manager.c \
		draw_items.c \
		draw_chat.c \
		draw_map_entities.c \
		draw_button_game.c \
		draw_bin_smoke.c \
		draw_players.c \
		draw_particles.c \
		draw_portals.c \
		draw_cursor_drag.c \
		draw_hud.c \
\
		launcher_event_manager.c \
		launcher_event_button.c \
		set_pseudo.c \
		write_ip_port.c \
		play_button_clicked.c \
\
		launcher_update_manager.c \
		update_player_stat.c \
		update_arrows.c \
\
		launcher_draw_manager.c \
\
		settings_draw_manager.c \
\
		settings_events_manager.c \
		settings_events_changing_command.c \
		settings_update_button.c \
		key_changer_letter.c \
\
		settings_update_manager.c \
\
		share/get_type_size.c \
\
		parse.c \
		my_tablen.c \
		open_file.c \
		get_with_value.c \
		wcsv_request.c \
		open_file.c \
		wcsv_destroy.c \
		add_to_chat.c \
		apply.c \
\

SRCDIR	=	src
GLOOPDIR	=	$(SRCDIR)/gloop
SPLASHDIR	=	$(GLOOPDIR)/splash
LAUNCHERDIR	=	$(GLOOPDIR)/launcher
GAMEDIR		=	$(GLOOPDIR)/game
SETTINGSDIR	=	$(GLOOPDIR)/settings
BUILDDIR=	build
PARTICLEDIR	=	lib/particle
SERVERDIR	=	server

SRCS	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ		=	$(addprefix $(BUILDDIR)/, $(SRC:.c=.o))

CFLAGS	=	-g -Wall -Wextra -fsanitize=address
CPPFLAGS	= -Wno-deprecated-declarations  -I./inc -I./share
LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-network -lcsfml-window \
			-lm -L./lib -lparticle -lcsfml-audio

vpath %.c	$(SRCDIR)/tools:\
			$(SRCDIR)/create:\
			$(SRCDIR)/create/launcher:\
			$(SRCDIR)/create/anims/anims_props:\
			$(SRCDIR)/destroy:\
			$(SRCDIR)/destroy/launcher:\
			$(SRCDIR)/maps:\
			$(GLOOPDIR)/network:\
			$(GLOOPDIR)/event:\
			$(GLOOPDIR)/update:\
			$(GAMEDIR)/draw:\
			$(GAMEDIR)/events:\
			$(GAMEDIR)/update:\
			$(LAUNCHERDIR)/draw:\
			$(LAUNCHERDIR)/events:\
			$(LAUNCHERDIR)/update:\
			$(SPLASHDIR):\
			$(SETTINGSDIR)/draw:\
			$(SETTINGSDIR)/events:\
			$(SETTINGSDIR)/update:\
			share/csv/parse:\
			share/csv/encode:\

all: particle_and_server $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

particle_and_server:
		$(MAKE) -C $(PARTICLEDIR)
		$(MAKE) -C $(SERVERDIR)

clean:
		$(MAKE) -C $(PARTICLEDIR) clean
		$(MAKE) -C $(SERVERDIR) fclean
		rm -f $(OBJ)

fclean:	clean
		$(MAKE) -C $(PARTICLEDIR) fclean
		$(MAKE) -C $(SERVERDIR) fclean
		rm -f $(NAME)

re:	fclean all
