/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:24:52 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/06 13:23:52 by sfarren          ###   ########.fr       */
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
			if (display_image(game, &game->images.floors[0],
					(meta->tile * col), (meta->tile * row)))
				return (set_error("Failed to display floor image."));
			col++;
		}
		row++;
	}
	return (0);
}

int	display_exit(t_context *context)
{
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	if (game->collectibles == meta->collectible_count)
	{
		if (display_image(game, &game->images.exit[0],
				(meta->tile * meta->exit_pos[0]),
				(meta->tile * meta->exit_pos[1])))
			return (set_error("Failed to display exit image."));
	}
	else
	{
		if ((display_image(game, &game->images.exit[1],
					(meta->tile * meta->exit_pos[0]),
					(meta->tile * meta->exit_pos[1]))))
			return (set_error("Failed to display exit image."));
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
	row = 0;
	while (row < meta->line_count)
	{
		col = 0;
		while (col < meta->line_length)
		{
			if (game->map[row][col] == K_COLLECTIBLE)
			{
				if (display_image(game, &game->images.collectibles[0],
						(meta->tile * col), (meta->tile * row)))
					return (set_error("Failed to display collectible image."));
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	display_player(t_context *context)
{
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	if (display_image(game, &game->images.player[1],
			(meta->tile * game->player_pos[0]),
			(meta->tile * game->player_pos[1])))
		return (set_error("Failed to display player image."));
	return (0);
}

int	display_level_end(t_context *context)
{
	t_game	*game;

	game = context->game;
	if (display_image(game, &game->images.ui[0], 100, 100))
		return (set_error("Failed to display level end image."));
	return (0);
}
