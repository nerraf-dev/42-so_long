/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/05 19:08:51 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	// char		**map;
	// t_map_flags	flags;
	// t_game		game;
	// // Initialize the game structure
	// game.mlx = NULL;
	// game.mlx_win = NULL;
	// // Initialize the map flags
	// flags.line_count = 0;
	// flags.line_length = 0;
	// flags.player_count = 0;
	// flags.exit_count = 0;
	// flags.collectible_count = 0;
	// // Initialize the map
	// map = NULL;


	// Validate command line arguments
	validate_args(argc, argv);
	// Validate the map file
	parse_map(argv[1]);

	load_window();

	return (0);
}
