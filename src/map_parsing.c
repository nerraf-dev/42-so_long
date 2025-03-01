/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/01 18:02:25 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define WALL '1'
#define START 'P'
#define EXIT 'E'
#define COLLECTIBLE 'C'
#define VALID_CHARS "01PEC"

void	exit_with_error(const char *message)
{
	ft_printf_fd(2, "Error\n");
	ft_printf_fd(2, "%s", message);
	exit(EXIT_FAILURE);
}

void	check_line_length(const char *line, int expected_length)
{
	if (ft_strlen(line) != (size_t)expected_length)
	{
		exit_with_error("Map is not rectangular.\n");
	}
}

void	check_walls(const char *line)
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

void	check_valid_chars(const char *line, int *player_count,
	int *exit_count, int *collectible_count)
{
	while (*line)
	{
		if (!ft_strchr(VALID_CHARS, *line))
		{
			exit_with_error("Invalid character in map.\n");
		}
		if (*line == START)
		{
			if (*player_count)
			{
				exit_with_error("Duplicate start position.\n");
			}
			(*player_count)++;
		}
		else if (*line == EXIT)
		{
			if (*exit_count)
			{
				exit_with_error("Duplicate exit position.\n");
			}
			(*exit_count)++;
		}
		else if (*line == COLLECTIBLE)
		{
			(*collectible_count)++;
		}
		line++;
	}
}

void	parse_map(const char *file)
{
	int		fd;
	char	*line;
	int		line_count;
	int		line_length;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	char	**map;
	int		i;
	size_t	len;

	fd = open_file(file, O_RDONLY);
	if (fd < 0)
	{
		exit_with_error("Failed to open map file.\n");
	}

	line_count = 0;
	line_length = 0;
	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	map = NULL;

	line = get_next_line(fd);
	while (line != NULL)
	{

		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		if (line_count == 0)
		{
			line_length = ft_strlen(line);
			check_walls(line);
		}
		else
		{
			check_line_length(line, line_length);
		}
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (line_count < 3)
		exit_with_error("Map is too small.\n");
	map = ft_calloc(line_count + 1, sizeof(char *));
	if (!map)
		exit_with_error("Memory allocation failed.\n");
	fd = open_file(file, O_RDONLY);
	if (fd < 0)
		exit_with_error("Failed to open map file.\n");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i] = ft_strdup(line);
		if (!map[i])
			exit_with_error("Memory allocation failed.\n");
		if (i == 0 || i == line_count - 1)
			check_walls(map[i]);
		else
		{
			if (map[i][0] != WALL || map[i][line_length - 1] != WALL)
				exit_with_error("Map is not surrounded by walls.\n");
			check_valid_chars(map[i], &player_count, &exit_count,
				&collectible_count);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);

	if (player_count != 1)
		exit_with_error("Map must contain exactly one player.\n");
	if (exit_count != 1)
		exit_with_error("Map must contain exactly one exit.\n");
	if (collectible_count == 0)
		exit_with_error("Map must contain at least one collectible.\n");
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
