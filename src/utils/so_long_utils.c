/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:54:13 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/14 13:41:20 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	set_error(const char *message)
{
	ft_printf_fd(2, "Error:\n");
	ft_printf_fd(2, "%s\n", message);
	return (1);
}

static void	cleanup_player(t_game *game)
{
	int	i;

	if (game->images.player)
	{
		i = 0;
		while (i < PLAYER_IMAGES)
		{
			if (game->images.player[i].img)
				mlx_destroy_image(game->mlx, game->images.player[i].img);
			i++;
		}
	}
}

static void	cleanup_textures(t_game *game)
{
	if (game->images.walls && game->images.walls->img)
		mlx_destroy_image(game->mlx, game->images.walls->img);
	if (game->images.floors && game->images.floors->img)
		mlx_destroy_image(game->mlx, game->images.floors->img);
	if (game->images.collectibles && game->images.collectibles->img)
		mlx_destroy_image(game->mlx, game->images.collectibles->img);
	if (game->images.exit)
	{
		if (game->images.exit[0].img)
			mlx_destroy_image(game->mlx, game->images.exit[0].img);
		if (game->images.exit[1].img)
			mlx_destroy_image(game->mlx, game->images.exit[1].img);
	}
	cleanup_player(game);
	if (game->images.ui && game->images.ui->img)
		mlx_destroy_image(game->mlx, game->images.ui->img);
}

/**
 * @brief Frees allocated memory for the game map and visited array, and sets
 * their pointers to NULL.
 *
 * Cleans up dynamically allocated memory associated with the game map
 * and the visited array in the `t_game` structure.
 * Ensures that all memory is properly freed and pointers are
 * set to NULL to avoid dangling pointers.
 *
 * @param game Pointer to the `t_game` structure containing the game state.
 * @param map_data Pointer to the `t_m_data` structure containing map metadata,
 * specifically the number of lines in the map (`line_count`).
 *
 * @note This function assumes that `game->map` and `game->visited` are either
 * NULL or valid pointers to dynamically allocated memory. Additionally, it
 * assumes that `map_data->line_count` accurately reflects the number of lines
 * in the map.
 */
void	cleanup(t_game *game)
{
	cleanup_textures(game);
	if (game->map)
	{
		free_game_arr((void **)game->map);
		game->map = NULL;
	}
	if (game->visited)
	{
		free_game_arr((void **)game->visited);
		game->visited = NULL;
	}
	if (game->frame_buffer)
	{
		if (game->frame_buffer->img)
		{
			mlx_destroy_image(game->mlx, game->frame_buffer->img);
			game->frame_buffer->img = NULL;
		}
		if (game->frame_buffer->buffer)
			game->frame_buffer->buffer = NULL;
		free(game->frame_buffer);
		game->frame_buffer = NULL;
	}
}
