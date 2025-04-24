/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/24 09:27:37 by sfarren          ###   ########.fr       */
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

/**
 * @brief Frees allocated memory for the game map and visited array, and sets
 * their pointers to NULL.
 *
 * This function is responsible for cleaning up dynamically allocated memory
 * associated with the game map and the visited array in the `t_game`
 * structure. It ensures that all memory is properly freed and pointers are
 * set to NULL to avoid dangling pointers.
 *
 * @param game Pointer to the `t_game` structure containing the game state.
 * @param map_data Pointer to the `t_m_data` structure containing map metadata,
 * specifically the number of lines in the map (`line_count`).
 *
 * @note This function assumes that `game->map` and `game->visited` are either
 * NULL or valid pointers to dynamically allocated memory. Additionally, it
 * assumes that `map_data->line_count` accurately reflects the number of lines
 * in the map.
 */
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
		}
		free(game->visited);
		game->visited = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_m_data	map_data;
	t_context	context;
	// int			ret;

	init_data(&game, &map_data);
	if (validate_args(argc, argv))
		return (1);
	game.file = argv[1];
	// ret = parse_and_validate(&game, &map_data);
	// print value of ret and status of memory allocated (what needs freeing)
	if (parse_and_validate(&game, &map_data))
	{
		cleanup(&game, &map_data);
		return (1);
	}
	context.game = &game;
	context.map_data = &map_data;
	run_game(&context);

	// mlx_loop(game.mlx);
	cleanup(&game, &map_data);
	// Final Cleanup after a VALID map
	// if (game.map)
	// {
	// 	int i = 0;
	// 	while (game.map[i])
	// 		free(game.map[i++]);
	// 	free(game.map);
	// }
	return (0);
}
