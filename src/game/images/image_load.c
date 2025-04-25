/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:29:44 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 18:50:46 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

// set the filename values


int	load_images(t_context *context)
{
	t_game	*game;

	game = context->game;
	game->images.walls = set_wall_texture_values(game);
	game->images.floors = set_floor_texture_values(game);
	game->images.player = set_static_player_texture_values(game);
	game->images.collectibles = set_coll_texture_values(game);
	game->images.exit = set_exit_texture_values(game);
	if (!game->images.walls || !game->images.floors || !game->images.player
		|| !game->images.collectibles || !game->images.exit)
		return (1);
	return (0);
}

int	display_images(t_context *context, int x, int y)
{
	int	x;
	int	y;
	int	i;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	i = 0;
	x = 0;
	y = 0;
	// Display the background (floor)
	while (y < meta->line_count)
	{
		while (x < meta->line_length)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->images.floors[i].img, x + (TILE_SIZE * x), y);
			x++;
		}
		y++;
	}

	// Display the walls, exit (and start)
	// Display the collectibles
	// Display the player

	// Iterate through the map and display the relevant images



}
