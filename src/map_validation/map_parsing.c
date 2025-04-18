/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 19:03:29 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Initializes the map flags structure.
 *
 * Sets all counters (line count, line length, player count, exit count,
 * and collectible count) to zero.
 *
 * @param flags Pointer to the map flags structure to initialize.
 */
// static void	init_flags(t_m_data *flags)
// {
// 	flags->line_count = 0;
// 	flags->line_length = 0;
// 	flags->player_count = 0;
// 	flags->exit_count = 0;
// 	flags->collectible_count = 0;
// }

/**
 * @brief Copies the map data from the file into a 2D array.
 *
 * Reads the map file line by line, removes trailing newlines, and duplicates
 * each line into the provided map array. Exits with an error if memory
 * allocation fails.
 *
 * @param file The path to the map file.
 * @param map The 2D array to store the map data.
 */
static int	copy_map_data(t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	size_t	len;

	fd = open_file(game->file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			return (1);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

/**
 * @brief Parses the map file and validates its structure and content.
 *
 * Initializes map flags, determines map dimensions, allocates memory for the
 * map, copies the map data, validates the map, and prints it. Frees all
 * allocated memory after use. Exits with an error if any step fails.
 *
 * @param file The path to the map file.
 */
int	parse_map(t_game *game, t_m_data *map_data)
{
	int			i;
	ft_printf("PARSE MAP\n");
	// init_flags(&game->map_flags);
	if (map_dimensions(game->file, map_data))
	{
		ft_printf_fd(2, "Error: Map is too small or invalid.\n");
		return (1);
	}

	ft_printf("Map dimensions: %d x %d\n", map_data->line_count, map_data->line_length);
	game->map = ft_calloc(map_data->line_count + 1, sizeof(char *));
	if (!game->map)
	{
		ft_printf_fd(2, "Error: Memory allocation failed.\n");
		return (1);
	}
	if (copy_map_data(game))
	{
		free_map(game);
		return (1);
	}
	ft_printf("Map data copied successfully.\n");
	// validate_map(game->map, &game->flags);
	if (validate_map(game, map_data))
	{
		free_map(game);
		return (1);
	}
	ft_printf("Map validated successfully.\n");
	ft_printf("START: [%d, %d]\n", map_data->start[0], map_data->start[1]);
	ft_printf("EXIT: [%d, %d]\n", map_data->exit[0], map_data->exit[1]);
	validate_path(game, map_data);

	i = 0;
	// Print the map for debugging purposes
	ft_printf("Map:\n");
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	i = 0;
	return (0);
}
