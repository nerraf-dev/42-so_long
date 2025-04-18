/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:56:46 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 14:53:16 by sfarren          ###   ########.fr       */
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
		exit_with_error("Map is not rectangular.\n");
	}
}

/**
 * @brief Verifies that the given line is composed entirely of wall characters.
 *
 * Exits with an error if the map is not surrounded by walls.
 *
 * @param line The line to check.
 */
void	check_walls(const char *line, int length)
{
	int	i;

	i = 0;
	ft_printf("length: %d\n", length);
	while (i < length)
	{
		ft_printf("Checking wall: %c\n", line[i]);
		if (line[i] != WALL && line[i] != '\n')
		{
			exit_with_error("Map is not surrounded by walls.\n");
		}
		i++;
	}
}

/**
 * @brief Validates the characters in the given line of the map.
 *
 * This function checks each character in the provided line to ensure it is
 * part of the valid character set defined by `VALID_CHARS`. It also ensures
 * that there is exactly one player start position (`START`) and one exit
 * position (`EXIT`) in the map. Additionally, it counts the number of
 * collectibles (`COLLECTIBLE`) present. If an invalid character is found,
 * or if there are duplicate start or exit positions, the program exits with
 * an error message.
 *
 * @param line The line of the map to validate.
 * @param flags A pointer to a `t_map_flags` structure that tracks the counts
 *              of players, exits, and collectibles in the map.
 * @note program will terminate if invalid characters/duplicates are found.
 */
static void	check_valid_chars(const char *line, t_m_data *flags, int line_num)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			exit_with_error("Invalid character in map.\n");
		if (line[i] == START)
		{
			if (flags->player_count)
				exit_with_error("Duplicate start position.\n");
			flags->player_count++;
			flags->start[0] = i;
			flags->start[1] = line_num;
		}
		else if (line[i] == EXIT)
		{
			if (flags->exit_count)
				exit_with_error("Duplicate exit position.\n");
			flags->exit_count++;
			flags->exit[0] = i;
			flags->exit[1] = line_num;
		}
		else if (line[i] == COLLECTIBLE)
			flags->collectible_count++;
		i++;
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
void	validate_map(t_game *game, t_m_data *data)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == data->line_count - 1)
			check_walls(game->map[i], data->line_length);
		else
		{
			if (game->map[i][0] != WALL
				|| game->map[i][data->line_length - 1] != WALL)
				exit_with_error("Map is not surrounded by walls.\n");
			check_valid_chars(game->map[i], data, i);
		}
		i++;
	}
	if (data->player_count != 1)
		exit_with_error("Map must contain exactly one player.\n");
	if (data->exit_count != 1)
		exit_with_error("Map must contain exactly one exit.\n");
	if (data->collectible_count == 0)
		exit_with_error("Map must contain at least one collectible.\n");
}
