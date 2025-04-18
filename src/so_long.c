/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 14:05:47 by sfarren          ###   ########.fr       */
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
	map_data->player_count = 0;
	map_data->exit_count = 0;
	map_data->collectible_count = 0;
	map_data->start[0] = 0;
	map_data->start[1] = 0;
	map_data->exit[0] = 0;
	map_data->exit[1] = 0;
}

static void	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		exit(1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: Invalid map file extension. Use .ber\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_m_data	map_data;

	init_data(&game, &map_data);
	// Validate command line arguments
	// exiting here due to error is fine as no memory has been allocated
	// and no resources have been used.
	validate_args(argc, argv);
	game.file = argv[1];
	// Parse & Validate the map file
	//    From here any erros need to be handled correctly and memory freed.
	parse_map(&game, &map_data);
	// Initialize the game structure
	// load_window(&game);
	// mlx_loop(game.mlx);

	// Free resources
	if (game.map)
	{
		int i = 0;
		while (game.map[i])
			free(game.map[i++]);
		free(game.map);
	}
	ft_printf("Memory freed.\n");
	ft_printf("Game initialized.\n");
	return (0);
}
