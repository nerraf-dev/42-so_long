/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/07 12:09:26 by sfarren          ###   ########.fr       */
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
	t_game	game;
	int		i;

	// Validate command line arguments
	validate_args(argc, argv);
	// Parse & Validate the map file
	parse_map(argv[1], &game);

	// Initialize the game structure
	load_window(&game);
	mlx_loop(game.mlx);


	// Exit and Cleanup:
	// Free the map memory
	i = 0;
	while (game.map[i])
	{
		free(game.map[i]);
		i++;
	}
	free(game.map);

	return (0);
}
