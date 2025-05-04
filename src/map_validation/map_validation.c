/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:56:46 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/04 15:46:25 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Checks if the length of the given line matches expected length.
 *
 * Exits with an error if the map is not rectangular.
 *
 * @param line The line to check.
 * @param expected_length The expected length of the line.
 */
int	check_line_length(const char *line, int expected_length)
{
	size_t	len;

	len = ft_strlen(line) - 1;
	if (len != (size_t)expected_length)
		return (set_error("Map is not rectangular."));
	return (0);
}

/**
 * @brief Validates the map structure and content.
 *
 * Ensures the map is surrounded by walls, contains valid characters, and meets
 * the required conditions (one player, one exit, and at least one collectible).
 * Exits with an error if any condition is not met.
 *
 * @param map The 2D array representing the map.
 * @param flags Pointer to the map flags structure.
 */
// void	validate_map(char **map, t_map_flags *flags)
int	validate_map(t_game *game, t_meta *meta)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == meta->line_count - 1)
		{
			if (check_walls(game->map[i], meta->line_length))
				return (1);
		}
		else
		{
			if (game->map[i][0] != K_WALL
				|| game->map[i][meta->line_length - 1] != K_WALL)
				return (1);
			if (check_valid_chars(game->map[i], meta, i))
				return (1);
		}
		i++;
	}
	game->player_pos[0] = meta->start_pos[0];
	game->player_pos[1] = meta->start_pos[1];
	if (meta->start_count != 1)
		return (set_error("Map must contain a single player."));
	else if (meta->exit_count != 1)
		return (set_error("Map must contain a single exit."));
	else if (meta->collectible_count < 1)
		return (set_error("Map must contain at least one collectible."));
	return (0);
}
