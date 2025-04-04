/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:56:46 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/02 15:04:33 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_line_length(const char *line, int expected_length)
{
	if (ft_strlen(line) != (size_t)expected_length)
	{
		exit_with_error("Map is not rectangular.\n");
	}
}

static void	check_walls(const char *line)
{
	while (*line)
	{
		if (*line != WALL)
		{
			exit_with_error("Map is not surrounded by walls.\n");
		}
		line++;
	}
}

static void	check_valid_chars(const char *line, int *player_count,
	int *exit_count, int *collectible_count)
{
	while (*line)
	{
		if (!ft_strchr(VALID_CHARS, *line))
			exit_with_error("Invalid character in map.\n");
		if (*line == START)
		{
			if (*player_count)
				exit_with_error("Duplicate start position.\n");
			(*player_count)++;
		}
		else if (*line == EXIT)
		{
			if (*exit_count)
				exit_with_error("Duplicate exit position.\n");
			(*exit_count)++;
		}
		else if (*line == COLLECTIBLE)
			(*collectible_count)++;
		line++;
	}
}

void	map_dimensions(const char *file, t_map_flags *flags)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (flags->line_count == 0)
		{
			flags->line_length = ft_strlen(line);
			check_walls(line);
		}
		else
			check_line_length(line, flags->line_length);
		flags->line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (flags->line_count < 3)
		exit_with_error("Map is too small.\n");
}

void	validate_map(char **map, t_map_flags *flags)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0 || i == flags->line_count - 1)
			check_walls(map[i]);
		else
		{
			if (map[i][0] != WALL || map[i][flags->line_length - 1] != WALL)
				exit_with_error("Map is not surrounded by walls.\n");
			check_valid_chars(map[i], &flags->player_count, &flags->exit_count,
				&flags->collectible_count);
		}
		i++;
	}
	if (flags->player_count != 1)
		exit_with_error("Map must contain exactly one player.\n");
	if (flags->exit_count != 1)
		exit_with_error("Map must contain exactly one exit.\n");
	if (flags->collectible_count == 0)
		exit_with_error("Map must contain at least one collectible.\n");
}
