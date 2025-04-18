/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 14:48:19 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


static void	process_first(char *line, t_m_data *map_data)
{
	// map_data->line_length = ft_strlen(line);
	ft_printf("First line length: %d\n", map_data->line_length);
	check_walls(line, map_data->line_length);
}


/**
 * @brief Reads the map file to determine its dimensions.
 *
 * Ensures the map is rectangular and that the first line is surrounded by
 * walls. Exits with an error if the map is too small or invalid.
 *
 * @param file The path to the map file.
 * @param flags Pointer to the map flags structure.
 */
void	map_dimensions(const char *file, t_m_data *map_data)
{
	int		fd;
	char	*line;

	ft_printf("Map file: %s\n", file);
	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	map_data->line_length = ft_strlen(line) - 1;
	ft_printf("Line length: %d\n", map_data->line_length);
	while (line != NULL)
	{
		ft_printf("Line: %s\n", line);
		ft_printf("Line count: %d\n", map_data->line_count);
		if (map_data->line_count == 0)
			process_first(line, map_data);
		else
			check_line_length(line, map_data->line_length);
		map_data->line_count++;
		free(line);
		line = get_next_line(fd);
		ft_printf("Line count: %d\n", map_data->line_count);
	}
	if (line)
		free(line);
	close(fd);
	if (map_data->line_count < 3)
		exit_with_error("Map is too small.\n");
}
