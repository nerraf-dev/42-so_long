/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 15:33:41 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

void	destroy_images(t_game *game, int image_type)
{
	int		i;
	t_img	*images;

	if (image_type == WALL_IMAGES)
		images = game->images.walls;
	else if (image_type == FLOOR_IMAGES)
		images = game->images.floors;
	else if (image_type == PLAYER_IMAGES)
		images = game->images.player;
	else if (image_type == COLLECTIBLE_IMAGES)
		images = game->images.collectibles;
	else if (image_type == EXIT_IMAGES)
		images = game->images.exit;
	else
		return ;
	i = 0;
	while (i < image_type)
	{
		if (images[i].img)
			mlx_destroy_image(game->mlx, images[i].img);
		i++;
	}
}

/**
 * @brief Closes the game window and frees allocated resources.
 * Destroys the window and display, frees the MLX pointer and map
 * memory, then exits the program.
 *
 * @param game: Pointer to the game structure.
 *
 * @return Does not return.
 */
int	close_window(t_context *context)
{
	if (context->game->mlx_win)
		mlx_destroy_window(context->game->mlx, context->game->mlx_win);
	if (context->game->mlx)
		mlx_destroy_display(context->game->mlx);
	if (context->game->mlx)
		free(context->game->mlx);
	cleanup(context->game, context->meta);
	exit(0);
	return (0);
}

/**
 * @brief Handles key press events.
 *
 * If the Escape key is pressed, the game window is closed.
 *
 * @param keysym: The key symbol of the pressed key.
 * @param game: Pointer to the game structure.
 *
 * @return 0
 */
int	keypress(int keysym, t_context *context)
{
	// Check if the pressed key is the ESC key
	// if (keycode == 65307) // 65307 is the keycode for ESC
	if (keysym == XK_Escape)
		close_window(context);
	return (0);
}

/**
 * run_game - Sets up and runs the main game loop.
 * @context: Pointer to the context structure containing game state.
 *
 * Initializes MLX, creates a window, renders images, hooks events,
 * and starts the event loop.
 *
 * @return: 0 on success.
 */
int	run_game(t_context *context)
{
	t_game		*game;
	t_meta		*meta;
	int			width;
	int			height;

	game = context->game;
	meta = context->meta;
	game->mlx = mlx_init();
	width = meta->tile * meta->line_length + 20;
	height = meta->tile * meta->line_count;
	if (game->mlx == NULL)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx, width, height, "- so_long -");
	if (game->mlx_win == NULL)
	{
		free(game->mlx);
		exit(1);
	}
	if (load_images(context))
		return (1);
	display_images(context);
	mlx_hook(game->mlx_win, 17, 0, (int (*)(void *))close_window, context);
	mlx_hook(game->mlx_win, 2, 1L << 0,
		(int (*)(int, void *))keypress, context);
	// mlx_loop_hook();
	mlx_loop(game->mlx);
	return (0);
}
