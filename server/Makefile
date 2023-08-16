##
## EPITECH PROJECT, 2023
## MMOPRG_ONLINE [SSH]
## File description:
## Makefile
##

CC = gcc
HEADERS = -I./inc -I../share -I../inc
OBJECTS = objects

NAME = rpg.serv

vpath %.c src
vpath %.c src/utils
vpath %.c src/network
vpath %.c src/rpg_manager
vpath %.c ../share
vpath %.c ../share/csv/parse
vpath %.c ../share/csv/encode

SRC = 	main.c \
		net_loop.c \
		net_struct.c \
		net_selector.c \
		memory_tools.c \
		manager_main.c \
		get_type_size.c \
		update_player.c \
		move_player_map.c \
		player_connexion.c \
		manage_clients.c \
		str_tools.c \
		read_data.c \
		send_to_map_w.c \
		manager_struct.c \
		parse.c \
		my_tablen.c \
		wcsv_request.c \
		get_with_value.c \
		open_file.c \
		wcsv_destroy.c \
		apply.c \
		generate.c \
		wstr_to_word_array.c \
		tabs_tools.c \
		percent_rand.c \
		sort_scores.c \

OBJ = $(patsubst %.c, $(OBJECTS)/%.o, $(SRC))

all : create_dir $(NAME)

create_dir :| $(OBJECTS)

$(OBJECTS):
	@mkdir -p $@

$(OBJECTS)/%.o: %.c
	@$(CC) -c -o $@ $< $(HEADERS) \
	-Wno-deprecated-declarations -fsanitize=address -g
	@echo "-[DONE] $@-"

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) -I./includes -l csfml-network -l \
	csfml-system -g -fsanitize=address
	@echo "-[SUCCESS]-"

re:
	@rm -rf $(OBJECTS)
	@echo "-[RM] objects files-"
	@make

clean:
	@rm -rf $(OBJECTS)
	@echo "-[RM] objects files-"

fclean:
	@rm -rf $(OBJECTS)
	@echo "-[RM] objects files-"
	@rm -f $(NAME)
	@echo "-[RM] $(NAME)-"
