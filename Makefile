# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 12:18:57 by tglandai          #+#    #+#              #
#    Updated: 2020/03/22 06:36:46 by dhaouhao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

NAME		= cub3d

SRC_PATH 	= srcs
PARSE_PATH 	= parse
SRC_NAME 	= raycast.c cast_sky_flr.c cast_walls.c cast_sprite.c draw.c \
			shade_color.c free_sprite.c init_buffz.c load_xpm.c start_game.c \
			ft_exit.c init_orientation.c key_hook.c move.c create_bmp.c \
			check_conf.c check_map_utils.c file_exist.c find_player.c \
			free_conf.c free_sprite.c parse_file.c set_resolution.c \
			check_map.c exit_error.c fill_map.c find_sprites.c \
			free_line_n_split.c init_conf.c set_color.c set_texture.c \
			small_map.c main.c

OBJ_PATH	= objs
OBJ_NAME	= $(SRC_NAME:.c=.o)

MINIFT_DIR	= minilibft
MINIFT_LIB	= $(addprefix $(MINIFT_DIR)/,minilibft.a)
MINIFT_INC	= -I $(MINIFT_DIR)
MINIFT_LNK	= -L $(MINIFT_DIR)

MLX_DIR		= _minilibx
MLX_LIB		= $(addprefix $(MLX_DIR)/,libmlx.a)
MLX_INC		= -I $(MLX_DIR)
MLX_LNK		= -L $(MLX_DIR)
MLX_LNK		+= -l mlx -framework OpenGL -framework AppKit

INC			= -I includes
ALL_INC		= $(INC) $(MINIFT_INC) $(MLX_INC)

OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: objs libminift libmlx $(NAME)

$(NAME): $(MINIFT_LIB) $(MLX_LIB) $(OBJ)
			@$(CC) $(MINIFT_LNK) $(MLX_LNK) $^ -o $@
			@echo "Compilation of cub3d:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
			@$(CC) $(CFLAGS) -c $< $(INC) -o $@
			@echo "-c -o ${<:.c=.o} $<"

$(OBJ_PATH)/%.o: $(PARSE_PATH)/%.c
			@$(CC) $(CFLAGS) -c $< $(INC) -o $@
			@echo "-c -o ${<:.c=.o} $<"

$(OBJ_PATH)/%.o:%.c
			@$(CC) $(CFLAGS) -c $< $(INC) -o $@
			@echo "-c -o ${<:.c=.o} $<"

objs:
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@echo "Make objs directory:	\033[1;32mOK\033[m"

libmlx:
			@make -C $(MLX_DIR)

libminift:
			@make -C $(MINIFT_DIR)

clean:
			@make -C $(MLX_DIR) clean
			@make -C $(MINIFT_DIR) clean
			@rm -f $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true
			@echo "Removing cub3d objs"

fclean:
			@make -C $(MLX_DIR) clean
			@make -C $(MINIFT_DIR) fclean
			@rm -f $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true
			@echo "Removing cub3d objs"
			@rm -f $(NAME)
			@echo "Removing cub3d"

re: fclean all

.PHONY:		fclean clean re all
