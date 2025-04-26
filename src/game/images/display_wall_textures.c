/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:05:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 16:20:04 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

// int	display_walls(t_context	*c)
// {
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
static int	get_wall_type(t_context *context, int row, int col)
{
	if (row == 0 && col == 0)
		return (I_TL);
	else if (row == 0 && col == context->meta->line_length - 1)
		return (I_TR);
	else if (row == context->meta->line_count - 1 && col == 0)
		return (I_BASE_L);
	else if (row == context->meta->line_count - 1
		&& col == context->meta->line_length - 1)
		return (I_BASE_R);
	else if (col == 0)
		return (I_SIDE_L);
	else if (col == context->meta->line_length - 1)
		return (I_SIDE_R);
	else if (context->game->map[row][col] == K_WALL)
		return (I_MID);
	else
		return (-1);
}

static int	top_wall(t_context *context)
{
	int		type;
	int		col;

	col = 0;
	while (col < context->meta->line_length)
	{
		if (col == 0)
			type = I_TL;
		else if (col == context->meta->line_length - 1)
			type = I_TR;
		else
			type = I_TOP;
		if (display_image(context->game, &context->game->images.walls[type],
				(TILE_SIZE * col), (TILE_SIZE * 0)))
			return (1);
		col++;
	}
	return (0);
}

static int	base_wall(t_context *context)
{
	int	type;
	int	col;
	int	row;

	row = context->meta->line_length - 1;
	col = 0;
	while (col < context->meta->line_length)
	{
		if (col == 0)
			type = I_BASE_L;
		else if (col == context->meta->line_length - 1)
			type = I_BASE_R;
		else
			type = I_BASE;
		if (display_image(context->game, &context->game->images.walls[type],
				(TILE_SIZE * col), (TILE_SIZE * row)))
			return (1);
		col++;
	}
	return (0);
}

static int	other_walls(t_context *c)
{
	int	type;
	int	col;
	int	row;

	row = 1;
	while (row < c->meta->line_count - 1)
	{
		col = 0;
		while (col < c->meta->line_length)
		{
			type = get_wall_type(c, row, col);
			if (type != -1 && display_image(c->game,
					&c->game->images.walls[type], (TILE_SIZE * col),
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

