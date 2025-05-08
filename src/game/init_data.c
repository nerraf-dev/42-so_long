/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:45:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/08 10:49:32 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	init_map_data(t_meta *map_data)
{
	map_data->line_count = 0;
	map_data->line_length = 0;
	map_data->start_count = 0;
	map_data->exit_count = 0;
	map_data->collectible_count = 0;
	map_data->start_pos[0] = 0;
	map_data->start_pos[1] = 0;
	map_data->exit_pos[0] = 0;
	map_data->exit_pos[1] = 0;
	map_data->tile = TILE_SIZE ;
}

static void	init_game_data(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->file = NULL;
	game->visited = NULL;
	game->frame_buffer = NULL;
	game->images.walls = NULL;
	game->images.floors = NULL;
	game->images.collectibles = NULL;
	game->images.exit = NULL;
	game->images.player = NULL;
	game->images.ui = NULL;
	game->player_pos[0] = 0;
	game->player_pos[1] = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->error = 0;
	game->steps = 0;
}

/**
 * init_data - Initializes game and map_data structures.
 * @game: Pointer to the game structure.
 * @map_data: Pointer to the map metadata structure.
 *
 * Sets default values for all pointers and counters.
 */
void	init_data(t_game *game, t_meta *map_data)
{
	init_game_data(game);
	init_map_data(map_data);
}
