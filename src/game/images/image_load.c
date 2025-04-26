/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:29:44 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 16:02:49 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

// set the filename values


int	load_images(t_context *context)
{
	t_game	*game;

	game = context->game;
	game->images.walls = set_wall_texture_values(game);
	if (game->images.walls == NULL)
		return (set_error("Failed to load wall images."));
	game->images.floors = set_floor_texture_values(game);
	if (game->images.floors == NULL)
		return (set_error("Error: Failed to load floor images."));
	game->images.player = set_static_player_texture_values(game);
	if (game->images.player == NULL)
		return (set_error("Error: Failed to load player images."));
	game->images.collectibles = set_coll_texture_values(game);
	if (game->images.collectibles == NULL)
		return (set_error("Error: Failed to load collectible images."));
	game->images.exit = set_exit_texture_values(game);
	if (game->images.exit == NULL)
		return (set_error("Error: Failed to load exit images."));
	return (0);
}

/**
 * display_image - Displays an image at the specified window position.
 * @game: Pointer to the game structure.
 * @img: Pointer to the image structure.
 * @x: X-coordinate for image placement.
 * @y: Y-coordinate for image placement.
 *
 * Uses MLX to put the loaded image onto the game window.
 *
 * Return: 0 on success, 1 if the image is not loaded.
 */
int	display_image(t_game *game, t_img *img, int x, int y)
{
	if (img->img == NULL)
	{
		ft_putstr_fd("Error: Image is not loaded.\n", 2);
		return (1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, x, y);
	return (0);
}



int	display_images(t_context *context)
{
	display_floor(context);
	display_walls(context);
	display_exit(context);
	display_collectibles(context);
	display_player(context);
	return (0);
}

