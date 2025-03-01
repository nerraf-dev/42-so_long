# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 12:30:50 by sfarren           #+#    #+#              #
#    Updated: 2025/03/01 15:34:18 by sfarren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = lib/libft
GNL_DIR = lib/gnl

LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
GNL_FLAGS = -L$(GNL_DIR) -lgnl
MLX_FLAGS = -L/usr/local/lib -lmlx -lX11 -lXext -lm -lz

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = main.c files.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = $(BIN_DIR)/so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(GNL_FLAGS) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
