/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:18 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/04 16:23:00 by sfarren          ###   ########.fr       */
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
	int		ret;

	fd = open_file(file, O_RDONLY);
	line = get_next_line(fd);
	if (line)
		meta->line_length = ft_strlen(line) - 1;
	ret = 0;
	while (line)
	{
		if ((meta->line_count == 0 && check_walls(line, meta->line_length))
			|| (meta->line_count != 0
				&& check_line_length(line, meta->line_length)))
			ret = 1;
		meta->line_count++;
		free(line);
		// if (ret)
		// 	break ;
		line = get_next_line(fd);
	}
	close(fd);
	if (meta->line_count < 3 && )
		return (set_error("Map is too small."));
	return (ret);
}
