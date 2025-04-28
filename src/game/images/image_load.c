/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:29:44 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/28 19:28:13 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"


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
	game->frame_buffer = ft_calloc(1, sizeof(t_img));
	if (!game->frame_buffer)
		return (set_error("Memory Alloc failed for frame buffer."));
	game->frame_buffer->img = mlx_new_image(game->mlx, win_w, win_h);
	if (game->frame_buffer->img == NULL)
	{
		free(game->frame_buffer);
		return (set_error("Failed to create frame buffer image."));
	}
	game->frame_buffer->buffer = mlx_get_data_addr(game->frame_buffer->img,
			&game->frame_buffer->bpp, &game->frame_buffer->line_bytes,
			&game->frame_buffer->endian);
	if (game->frame_buffer->buffer == NULL)
	{
		mlx_destroy_image(game->mlx, game->frame_buffer->img);
		free(game->frame_buffer);
		return (set_error("Failed to get frame buffer data address."));
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
		return (set_error("Failed to load floor images."));
	game->images.player = set_static_player_texture_values(game);
	if (game->images.player == NULL)
		return (set_error("Failed to load player images."));
	game->images.collectibles = set_coll_texture_values(game);
	if (game->images.collectibles == NULL)
		return (set_error("Failed to load collectible images."));
	game->images.exit = set_exit_texture_values(game);
	if (game->images.exit == NULL)
		return (set_error("Failed to load exit images."));
	if (set_frame_buffer(context))
		return (set_error("Failed to set frame buffer."));
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
	if (img->transparency)
		blit_image_transparent(game->frame_buffer, img, x, y);
	else
		blit_image_opaque(game->frame_buffer, img, x, y);
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

