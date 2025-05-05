/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:52:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 12:51:30 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	set_start(t_meta *meta, int x, int y)
{
	meta->start_count++;
	meta->start_pos[0] = x;
	meta->start_pos[1] = y;
}

static void	set_exit(t_meta *meta, int x, int y)
{
	meta->exit_count++;
	meta->exit_pos[0] = x;
	meta->exit_pos[1] = y;
}

/**
 * @brief Verifies that the given line is composed entirely of wall characters.
 *
 * Exits with an error if the map is not surrounded by walls.
 *
 * @param line The line to check.
 */
int	check_walls(const char *line, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (line[i] != K_WALL && line[i] != '\n')
			return (set_error("Map is not surrounded by walls."));
		i++;
	}

	return (0);
}

/**
 * check_valid_chars - Validates the characters in a map line and updates flags.
 *
 * @line: A string representing a single line of the map.
 * @flags: A pointer to a t_m_data structure that tracks map properties such as
 *         the number of players, exits, and collectibles.
 * @line_num: The current line number in the map being validated.
 *
 * This function iterates through each character in the given map line and
 * performs the following checks:
 * - Ensures the character is part of the valid character set (VALID_CHARS).
 * - Ensures that there is only one player (START) in the map.
 * - Ensures that there is only one exit (EXIT) in the map.
 * - Counts the number of collectibles (COLLECTIBLE) in the map.
 *
 * If an invalid character is found, or if there are multiple players or exits,
 * the function sets an appropriate error message and returns a non-zero value.
 * Otherwise, it returns 0 to indicate successful validation.
 *
 * Return: 0 if the line is valid, or a non-zero value if an error occurs.
 */
int	check_valid_chars(const char *line, t_meta *meta, int line_num)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			return (set_error("Map contains invalid characters."));
		else if (line[i] == K_START)
			set_start(meta, i, line_num);
		else if (line[i] == K_EXIT)
			set_exit(meta, i, line_num);
		else if (line[i] == K_COLLECTIBLE)
			meta->collectible_count++;
		i++;
	}
	return (0);
}
