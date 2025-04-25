/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:29:44 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 19:53:51 by sfarren          ###   ########.fr       */
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
	{
		ft_printf("Error: Failed to load wall images.\n");
		return (1);
	}
	game->images.floors = set_floor_texture_values(game);
	if (game->images.floors == NULL)
	{
		ft_printf("Error: Failed to load floor images.\n");
		return (1);
	}
	game->images.player = set_static_player_texture_values(game);
	if (game->images.player == NULL)
	{
		ft_printf("Error: Failed to load player images.\n");
		return (1);
	}
	game->images.collectibles = set_coll_texture_values(game);
	if (game->images.collectibles == NULL)
	{
		ft_printf("Error: Failed to load collectible images.\n");
		return (1);
	}
	game->images.exit = set_exit_texture_values(game);
	if (game->images.exit == NULL)
	{
		ft_printf("Error: Failed to load exit images.\n");
		return (1);
	}
	// if (!game->images.walls || !game->images.floors || !game->images.player
	// 	|| !game->images.collectibles || !game->images.exit)
	// 	return (1);
	ft_printf("Images loaded successfully.\n");
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
	int		col;
	int		row;
	t_game	*game;
	t_meta	*meta;
	// int		i;

	game = context->game;
	meta = context->meta;
	// i = 0;
	// Display the background (floor)
	row = 0;
	while (row < meta->line_count)
	{
		col = 0;
		while (col < meta->line_length)
		{
			display_image(game, &game->images.floors[I_MID], col + (TILE_SIZE * col), row + (TILE_SIZE * row));
			// mlx_put_image_to_window(game->mlx, game->mlx_win,
			// 	game->images.floors[i].img, x + (TILE_SIZE * x), y);
			col++;
		}
		row++;
	}

	// Display the walls, exit (and start)
	// Display the collectibles
	// Display the player

	// Iterate through the map and display the relevant images


	return (0);
}

