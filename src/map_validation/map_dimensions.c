/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 17:14:37 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Reads the map file to determine its dimensions.
 *
 * Ensures the map is rectangular and that the first line is surrounded by
 * walls. Exits with an error if the map is too small or invalid.
 *
 * @param file The path to the map file.
 * @param flags Pointer to the map flags structure.
 */
int	map_dimensions(const char *file, t_meta *meta)
{
	int		fd;
	char	*line;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	meta->line_length = ft_strlen(line) - 1;
	while (line != NULL)
	{
		if (meta->line_count == 0)
			check_walls(line, meta->line_length);
		else
			check_line_length(line, meta->line_length);
		meta->line_count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	if (meta->line_count < 3)
		return (1);
	return (0);
}
