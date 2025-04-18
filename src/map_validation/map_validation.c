/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:56:46 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 22:54:46 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Checks if the length of the given line matches the expected length.
 *
 * Exits with an error if the map is not rectangular.
 *
 * @param line The line to check.
 * @param expected_length The expected length of the line.
 */
void	check_line_length(const char *line, int expected_length)
{
	size_t	len;

	len = ft_strlen(line) - 1;
	if (len != (size_t)expected_length)
	{
		set_error("Map is not rectangular.\n");
	}
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
int	validate_map(t_game *game, t_m_data *data)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == data->line_count - 1)
		{
			if (check_walls(game->map[i], data->line_length))
				return (1);
		}
		else
		{
			if (game->map[i][0] != WALL
				|| game->map[i][data->line_length - 1] != WALL)
				return (1);
			if (check_valid_chars(game->map[i], data, i))
				return (1);
		}
		i++;
	}
	if (data->collectible_count == 0)
		return (set_error("Map must contain at least one collectible.\n"));
	return (0);
}
