/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:29:44 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/27 18:14:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	blit_image(t_img *dst, t_img *src, int x_off, int y_off)
{
	int	x;
	int	y;
	int	src_width;
	int	src_height;
	int	src_pixel;

	src_width = src->width;
	src_height = src->height;
	y = 0;
	while (y < src_height)
	{
		x = 0;
		while (x < src_width)
		{
			src_pixel = *(int *)(src->buffer + (y * src->line_bytes + x * (src->bpp / 8)));
			// Handle transparency if needed (skip if src_pixel is transparent)
			*(int *)(dst->buffer + ((y + y_off) * dst->line_bytes + (x + x_off) * (dst->bpp / 8))) = src_pixel;
			x++;
		}
		y++;
	}
}

// set the filename values
int	set_frame_buffer(t_context *context)
{
	t_game	*game;
	t_meta	*meta;
	int		win_w;
	int		win_h;

	game = context->game;
	meta = context->meta;
	win_w = meta->line_length * TILE_SIZE;
	win_h = meta->line_count * TILE_SIZE;
	game->frame_buffer = malloc(sizeof(t_img));
	if (!game->frame_buffer)
		return (set_error("Error: Failed to allocate memory for frame buffer."));
	game->frame_buffer->img = mlx_new_image(game->mlx, win_w, win_h);
	if (game->frame_buffer->img == NULL)
	{
		free(game->frame_buffer);
		return (set_error("Error: Failed to create frame buffer image."));
	}
	game->frame_buffer->buffer = mlx_get_data_addr(game->frame_buffer->img,
			&game->frame_buffer->bpp, &game->frame_buffer->line_bytes,
			&game->frame_buffer->endian);
	if (game->frame_buffer->buffer == NULL)
	{
		mlx_destroy_image(game->mlx, game->frame_buffer->img);
		free(game->frame_buffer);
		return (set_error("Error: Failed to get frame buffer data address."));
	}
	return (0);
}

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
	if (set_frame_buffer(context))
		return (set_error("Error: Failed to set frame buffer."));
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
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, x, y);
	blit_image(game->frame_buffer, img, x, y);
	return (0);
}



int	display_images(t_context *context)
{
	int		buffer_size;
	t_game	*game;
	
	game = context->game;
	buffer_size = game->frame_buffer->height * game->frame_buffer->line_bytes;
	ft_memset(game->frame_buffer->buffer, 0, buffer_size); // Clear buffer

	display_floor(context);
	display_walls(context);
	display_exit(context);
	display_collectibles(context);
	display_player(context);
	mlx_put_image_to_window(context->game->mlx,
		context->game->mlx_win, context->game->frame_buffer->img, 0, 0);
	return (0);
}

