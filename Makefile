# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 12:30:50 by sfarren           #+#    #+#              #
#    Updated: 2025/04/02 15:04:16 by sfarren          ###   ########.fr        #
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

SRC_FILES = so_long.c \
			so_long_utils.c \
			files.c \
			map_parsing.c \
			map_validation.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) # $(GNL_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $< $(MLX_INC)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	# $(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	# $(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
