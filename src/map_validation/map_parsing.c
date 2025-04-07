/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/07 11:28:48 by sfarren          ###   ########.fr       */
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
static void	init_flags(t_map_flags *flags)
{
	flags->line_count = 0;
	flags->line_length = 0;
	flags->player_count = 0;
	flags->exit_count = 0;
	flags->collectible_count = 0;
}

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
static void	copy_map_data(const char *file, char **map)
{
	int		fd;
	char	*line;
	int		i;
	size_t	len;

	fd = open_file(file, O_RDONLY);
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
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
void	parse_map(const char *file, t_game *game)
{
	int			i;

	init_flags(&game->map_flags);
	map_dimensions(file, &game->map_flags);
	game->map = ft_calloc(game->map_flags.line_count + 1, sizeof(char *));
	if (!game->map)
		exit_with_error("Memory allocation failed.\n");
	copy_map_data(file, game->map);
	validate_map(game->map, &game->map_flags);
	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	i = 0;

	// while (game->map[i])
	// {
	// 	free(game->map[i]);
	// 	i++;
	// }
	// free(game->map);

}
