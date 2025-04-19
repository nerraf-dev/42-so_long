/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/19 12:41:44 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


// static void	process_first(char *line, t_m_data *map_data)
// {
// 	check_walls(line, map_data->line_length);
// }


/**
 * @brief Reads the map file to determine its dimensions.
 *
 * Ensures the map is rectangular and that the first line is surrounded by
 * walls. Exits with an error if the map is too small or invalid.
 *
 * @param file The path to the map file.
 * @param flags Pointer to the map flags structure.
 */
int	map_dimensions(const char *file, t_m_data *map_data)
{
	int		fd;
	char	*line;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	map_data->line_length = ft_strlen(line) - 1;
	while (line != NULL)
	{
		if (map_data->line_count == 0)
			check_walls(line, map_data->line_length);
		else
			check_line_length(line, map_data->line_length);
		map_data->line_count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	if (map_data->line_count < 3)
		return (1);
	return (0);
}
