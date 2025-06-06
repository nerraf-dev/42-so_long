# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 12:30:50 by sfarren           #+#    #+#              #
#    Updated: 2025/05/14 12:25:08 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := $(shell command -v clang 2>/dev/null || command -v gcc 2>/dev/null || command -v cc 2>/dev/null)
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
MLX_DIR = lib/mlx

LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_INC = -I$(MLX_DIR)

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

PARSING_DIR = $(SRC_DIR)/map_validation
UTILS_DIR = $(SRC_DIR)/utils
GAME_DIR = $(SRC_DIR)/game
GUI_DIR = $(SRC_DIR)/gui

GAME_FILES = game_init.c \
			init_data.c \
			hooks.c \
			move_player.c \
			images/blit_image.c \
			images/display_textures.c \
			images/display_ui_textures.c \
			images/display_wall_textures.c \
			images/frame_buffer.c \
			images/image_data_init.c \
			images/image_load.c \
			images/image_management.c \

PARSING_FILES = cell_check.c \
				check_adjacent.c \
				map_dimensions.c \
				map_parsing.c \
				map_validation.c \
				path_validation.c \
				queue_management.c \
				validation_helpers.c \
				visited_mem.c \

UTILS_FILES = so_long_utils.c \
				files.c \

MAIN_FILES = so_long.c \

SRC_FILES = $(addprefix $(GAME_DIR)/, $(GAME_FILES)) \
			$(addprefix $(PARSING_DIR)/, $(PARSING_FILES)) \
			$(addprefix $(UTILS_DIR)/, $(UTILS_FILES)) \
			$(addprefix $(SRC_DIR)/, $(MAIN_FILES))

SRCS = $(SRC_FILES)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = so_long

all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $< $(MLX_INC)

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning libft..."; \
		git clone https://github.com/nerraf-dev/42-libft.git $(LIBFT_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MiniLibX..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
