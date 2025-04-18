/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 23:59:45 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_data(t_game *game, t_m_data *map_data)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->file = NULL;
	game->map = NULL;
	game->visited = NULL;
	game->collectibles = 0;
	game->exit = 0;
	game->error = 0;
	map_data->line_count = 0;
	map_data->line_length = 0;
	map_data->start_count = 0;
	map_data->exit_count = 0;
	map_data->collectible_count = 0;
	map_data->start[0] = 0;
	map_data->start[1] = 0;
	map_data->exit[0] = 0;
	map_data->exit[1] = 0;
}

static int	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: Invalid map file extension. Use .ber\n", 2);
		return (1);
	}
	return (0);
}

void	cleanup(t_game *game, t_m_data *map_data)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->visited)
	{
		i = 0;
		while (i < map_data->line_count)
		{
			free(game->visited[i++]);
			game->visited[i] = NULL;
		}
		free(game->visited);
		game->visited = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_m_data	map_data;

	int			ret;

	init_data(&game, &map_data);
	if (validate_args(argc, argv))
		return (1);
	game.file = argv[1];
	ret = parse_and_validate(&game, &map_data);
	// print value of ret and status of memory allocated (what needs freeing)
	if (ret == 1)
	{
		cleanup(&game, &map_data);
		return (1);
	}
	// AT THIS POINT:
	// 1. The map is valid



	// Initialize the game structure
	// if (load_window(&game))
	// {
	// 	ft_printf("Error: Failed to load window.\n");
	// 	cleanup(&game, &map_data);
	// 	return (1);
	// }
	// mlx_loop(game.mlx);


	// Final Cleanup after a VALID map
	if (game.map)
	{
		int i = 0;
		while (game.map[i])
			free(game.map[i++]);
		free(game.map);
	}
	// ft_printf("Memory freed.\n");
	// ft_printf("Game initialized.\n");

	return (0);
}
