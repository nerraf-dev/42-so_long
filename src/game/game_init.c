/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/08 11:39:44 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief Destroys a set of images of a specific type in the game.
 *
 * This function iterates through an array of images of a specified type
 * (e.g., walls, floors, player, collectibles, or exit) and destroys each
 * image using the `mlx_destroy_image` function. The type of images to be
 * destroyed is determined by the `image_type` parameter.
 *
 * @param game Pointer to the game structure containing the images and mlx
 *             instance.
 * @param image_type The type of images to destroy. This should correspond
 *                   to one of the predefined constants (e.g., WALL_IMAGES,
 *                   FLOOR_IMAGES, PLAYER_IMAGES, etc.).
 *
 * @note If the `image_type` does not match any predefined constants, the
 *       function will return without performing any action.
 */
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

static int	init_window(t_game *game, t_meta *meta)
{
	int	width;
	int	height;

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

	game = context->game;
	meta = context->meta;
	game->mlx = mlx_init();
	if (init_window(game, meta))
		return (1);
	if (load_images(context))
		return (1);
	display_images(context);
	setup_hooks(context);
	mlx_loop(game->mlx);
	return (0);
}
