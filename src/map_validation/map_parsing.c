/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/04 14:51:24 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// TODO: Remove before 42 push!
// void	print_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("Map:\n");
// 	while (game->map[i])
// 	{
// 		ft_printf("%s\n", game->map[i]);
// 		i++;
// 	}
// }

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

void	free_game_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	parse_and_validate(t_game *game, t_meta *meta)
{
	if (map_dimensions(game->file, meta))
	{
		ft_printf_fd(2, "Error: Map is too small or invalid.\n");
		return (1);
	}
	game->map = ft_calloc(meta->line_count + 1, sizeof(char *));
	if (!game->map)
		return (1);
	else if (copy_map_data(game))
		return (1);
	else if (validate_map(game, meta))
		return (1);
	else if (validate_path(game, meta))
		return (1);
	return (0);
}
