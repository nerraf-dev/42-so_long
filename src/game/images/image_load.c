/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:29:44 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/07 16:47:24 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

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
	game->images.ui = set_ui_texture_values(game);
	if (game->images.ui == NULL)
		return (set_error("Failed to load UI images."));
	if (set_frame_buffer(context))
		return (set_error("Failed to set frame buffer."));
	return (0);
}

/**
 * @brief display_image - Displays an image at the specified window position.
 * @param game: Pointer to the game structure.
 * @param img: Pointer to the image structure.
 * @param x: X-coordinate for image placement.
 * @param y: Y-coordinate for image placement.
 *
 * Uses MLX to put the loaded image onto the game window.
 *
 * Return: 0 on success, 1 if the image is not loaded.
 */
int	display_image(t_game *game, t_img *img, int x, int y)
{
	if (img->img == NULL)
		return (set_error("Image not loaded"));
	if (img->transparency)
		blit_image_transparent(game->frame_buffer, img, x, y);
	else
		blit_image_opaque(game->frame_buffer, img, x, y);
	return (0);
}

int	display_image_move(t_context *context)
{
	int		buffer_size;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	buffer_size = game->frame_buffer->height * game->frame_buffer->line_bytes;
	ft_memset(game->frame_buffer->buffer, 0, buffer_size);

	// Walls do nto need redrawing
	// Floors only need redrawing IF
	//	player moves
	//	collectible is taken

	// display_image(game, &game->images.floors[0],
	// 	(meta->tile * col), (meta->tile * row));

	display_exit(context);
	display_collectibles(context);
	display_player(context);

	if (game->player_pos[0] == meta->exit_pos[0]
		&& game->player_pos[1] == meta->exit_pos[1]
		&& game->collectibles == meta->collectible_count)
		display_level_end(context);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->frame_buffer->img, 0, 0);
	return (0);
}

int	display_images(t_context *context)
{
	int		buffer_size;
	t_game	*game;
	t_meta	*meta;

	game = context->game;
	meta = context->meta;
	buffer_size = game->frame_buffer->height * game->frame_buffer->line_bytes;
	ft_memset(game->frame_buffer->buffer, 0, buffer_size);
	display_floor(context);
	display_walls(context);
	display_exit(context);
	display_collectibles(context);
	display_player(context);
	if (game->player_pos[0] == meta->exit_pos[0]
		&& game->player_pos[1] == meta->exit_pos[1]
		&& game->collectibles == meta->collectible_count)
		display_level_end(context);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->frame_buffer->img, 0, 0);
	return (0);
}
