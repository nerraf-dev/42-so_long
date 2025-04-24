# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 12:30:50 by sfarren           #+#    #+#              #
#    Updated: 2025/04/24 10:02:34 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
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

# Subdirectories for organized source files
PARSING_DIR = $(SRC_DIR)/map_validation
UTILS_DIR = $(SRC_DIR)/utils
GAME_DIR = $(SRC_DIR)/game
GUI_DIR = $(SRC_DIR)/gui


# Source files in each category
GAME_FILES = game_init.c \
			image_management.c \

# GUI_FILES = window.c \

PARSING_FILES = cell_check.c \
				check_adjacent.c \
				map_dimensions.c \
				map_parsing.c \
				map_validation.c \
				path_validation.c \
				queue_management.c \
				visited_mem.c \

UTILS_FILES = so_long_utils.c \
				files.c \

MAIN_FILES = so_long.c \
				debugging.c \


# Combine all source files
SRC_FILES = $(addprefix $(GAME_DIR)/, $(GAME_FILES)) \
			$(addprefix $(PARSING_DIR)/, $(PARSING_FILES)) \
			$(addprefix $(UTILS_DIR)/, $(UTILS_FILES)) \
			$(addprefix $(SRC_DIR)/, $(MAIN_FILES))

# $(addprefix $(GUI_DIR)/, $(GUI_FILES)) \

SRCS = $(SRC_FILES)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $< $(MLX_INC)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
