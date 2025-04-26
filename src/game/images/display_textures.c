/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:24:52 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 16:09:51 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	display_floor(t_context *context)
{
	int		col;
	int		row;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	row = 0;
	while (row < meta->line_count)
	{
		col = 0;
		while (col < meta->line_length)
		{
			display_image(game, &game->images.floors[I_MID],
				(meta->tile * col), (meta->tile * row));
			col++;
		}
		row++;
	}
	return (0);
}

int	display_exit(t_context *context)
{
	int		col;
	int		row;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	row = 1;
	while (row < meta->line_count - 1)
	{
		col = 0;
		while (col < meta->line_length)
		{
			if (game->map[row][col] == K_EXIT)
				display_image(game, &game->images.exit[0],
					(meta->tile * col), (meta->tile * row));
			col++;
		}
		row++;
	}
	return (0);
}

int	display_collectibles(t_context *context)
{
	int		col;
	int		row;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	row = 1;
	while (row < meta->line_count - 1)
	{
		col = 0;
		while (col < meta->line_length)
		{
			if (game->map[row][col] == K_COLLECTIBLE)
				display_image(game, &game->images.collectibles[0],
					(meta->tile * col), (meta->tile * row));
			col++;
		}
		row++;
	}

	return (0);
}

int	display_player(t_context *context)
{
	int		col;
	int		row;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	row = 1;
	while (row < meta->line_count)
	{
		col = 0;
		while (col < meta->line_length - 1)
		{
			if (game->map[row][col] == K_START)
				display_image(game, &game->images.player[1],
					(meta->tile * col), (meta->tile * row));
			col++;
		}
		row++;
	}
	return (0);
}
