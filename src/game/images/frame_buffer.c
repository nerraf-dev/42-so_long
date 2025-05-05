/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:41:10 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 13:49:29 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

static int	init_fb_image(t_game *game, t_fb_vars *vars, t_meta *meta)
{
	vars->win_w = meta->line_length * TILE_SIZE;
	vars->win_h = meta->line_count * TILE_SIZE;
	game->frame_buffer->img = mlx_new_image(
			game->mlx, vars->win_w, vars->win_h);
	if (!game->frame_buffer->img)
	{
		free(game->frame_buffer);
		return (set_error("Failed to create frame buffer image."));
	}
	return (0);
}

static int	free_frame_buffer(t_game *game, char *msg)
{
	mlx_destroy_image(game->mlx, game->frame_buffer->img);
	free(game->frame_buffer);
	return (set_error(msg));
}

static int	set_fb_addr(t_game *game, t_fb_vars *vars)
{
	game->frame_buffer->buffer = mlx_get_data_addr(
			game->frame_buffer->img,
			&vars->bpp,
			&vars->line_bytes,
			&vars->endian);
	if (!game->frame_buffer->buffer)
		return (free_frame_buffer(game,
				"Failed to get frame buffer data address."));
	game->frame_buffer->bpp = vars->bpp;
	game->frame_buffer->line_bytes = vars->line_bytes;
	game->frame_buffer->endian = vars->endian;
	return (0);
}

static int	malloc_frame_buffer(t_game *game)
{
	game->frame_buffer = ft_calloc(1, sizeof(t_img));
	if (!game->frame_buffer)
		return (set_error("Memory Alloc failed for frame buffer."));
	return (0);
}

int	set_frame_buffer(t_context *context)
{
	t_game		*game;
	t_meta		*meta;
	t_fb_vars	vars;

	game = context->game;
	meta = context->meta;
	if (malloc_frame_buffer(game))
		return (1);
	if (init_fb_image(game, &vars, meta))
		return (1);
	if (set_fb_addr(game, &vars))
		return (1);
	return (0);
}
