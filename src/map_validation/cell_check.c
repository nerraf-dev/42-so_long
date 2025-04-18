/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:52:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 19:51:17 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	set_start(t_m_data *flags, int x, int y)
{
	flags->start_count++;
	flags->start[0] = x;
	flags->start[1] = y;
}

static void	set_exit(t_m_data *flags, int x, int y)
{
	flags->exit_count++;
	flags->exit[0] = x;
	flags->exit[1] = y;
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
	ft_printf("length: %d\n", length);
	while (i < length)
	{
		ft_printf("Checking wall: %c\n", line[i]);
		if (line[i] != WALL && line[i] != '\n')
		{
			ft_printf_fd(2, "Map is not surrounded by walls.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_valid_chars(const char *line, t_m_data *flags, int line_num)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			return (set_error("Invalid character in map.\n"));
		if (line[i] == START)
		{
			if (flags->start_count)
				return (set_error("Map must contain only one player.\n"));
			set_start(flags, i, line_num);
		}
		else if (line[i] == EXIT)
		{
			if (flags->exit_count)
				return (set_error("Map must contain only one exit.\n"));
			set_exit(flags, i, line_num);
		}
		else if (line[i] == COLLECTIBLE)
			flags->collectible_count++;
		i++;
	}
	return (0);
}
