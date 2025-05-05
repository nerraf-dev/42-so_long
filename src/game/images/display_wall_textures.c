/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:05:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 22:09:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	display_walls(t_context	*c)
{
	int	col;
	int	row;

	row = 1;
	while (row < c->meta->line_count - 1)
	{
		col = 0;
		while (col < c->meta->line_length)
		{
			if (c->game->map[row][col] == K_WALL)
				if (display_image(c->game,
						&c->game->images.walls[0], (TILE_SIZE * col),
						(TILE_SIZE * row)))
					return (1);
			col++;
		}
		row++;
	}
	return (0);
}

int	display_walls(t_context	*c)
{
	int	ret;

	ret = top_wall(c);
	ret = base_wall(c);
	ret = other_walls(c);
	if (ret)
		return (1);
	return (0);
}

// int	display_walls(t_context	*c)
// {
// 	// int	type;
// 	int	col;
// 	int	row;

// 	row = 0;
// 	while (row < c->meta->line_count)
// 	{
// 		col = 0;
// 		while (col < c->meta->line_length)
// 		{
// 			if (c->game->map[row][col] == K_WALL)
// 				if (display_image(c->game,
// 						&c->game->images.walls[I_MID], (TILE_SIZE * col),
// 						(TILE_SIZE * row)))
// 					return (1);
// 			col++;
// 		}
// 		row++;
// 	}
// 	return (0);
// }
