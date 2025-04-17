/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/17 15:32:52 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map = NULL;
	game->collectibles = 0;
	game->exit = 0;
	game->visited = NULL;
	game->flags.line_count = 0;
	game->flags.line_length = 0;
	game->flags.player_count = 0;
	game->flags.exit_count = 0;
	game->flags.collectible_count = 0;
	game->flags.start[0] = 0;
	game->flags.start[1] = 0;
	game->flags.exit[0] = 0;
	game->flags.exit[1] = 0;
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
	t_game	game;
	// int		i;
	init_game(&game);
	// Validate command line arguments
	validate_args(argc, argv);
	// Parse & Validate the map file
	parse_map(argv[1], &game);

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
