/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/02 15:02:47 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_flags(t_map_flags *flags)
{
	flags->line_count = 0;
	flags->line_length = 0;
	flags->player_count = 0;
	flags->exit_count = 0;
	flags->collectible_count = 0;
}

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

void	parse_map(const char *file)
{
	char		**map;
	t_map_flags	flags;
	int			i;

	init_flags(&flags);
	map = NULL;
	map_dimensions(file, &flags);
	map = ft_calloc(flags.line_count + 1, sizeof(char *));
	if (!map)
		exit_with_error("Memory allocation failed.\n");
	copy_map_data(file, map);
	validate_map(map, &flags);
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
