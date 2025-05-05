/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 13:23:20 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_line(char *line, int fd, t_meta *meta)
{
	int		line_length;

	line_length = ft_strlen(line) - 1;
	if (line_length != meta->line_length)
	{
		free(line);
		close(fd);
		return (set_error("Map must be rectangular."));
	}
	meta->line_count++;
	return (0);
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
int	map_dimensions(const char *file, t_meta *meta)
{
	int		fd;
	char	*line;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	if (line)
		meta->line_length = ft_strlen(line) - 1;
	while (line)
	{
		if (check_line(line, fd, meta))
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (meta->line_count < 3)
		return (set_error("Map is too small."));
	return (0);
}
