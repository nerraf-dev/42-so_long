/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 13:31:10 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * init_data - Initializes game and map_data structures.
 * @game: Pointer to the game structure.
 * @map_data: Pointer to the map metadata structure.
 *
 * Sets default values for all pointers and counters.
 */
void	init_data(t_game *game, t_meta *map_data)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->file = NULL;
	game->map = NULL;
	game->visited = NULL;
	game->images.walls = NULL;
	game->images.floors = NULL;
	game->images.player = NULL;
	game->player_pos[0] = 0;
	game->player_pos[1] = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->error = 0;
	game->steps = 0;
	map_data->line_count = 0;
	map_data->line_length = 0;
	map_data->start_count = 0;
	map_data->exit_count = 0;
	map_data->collectible_count = 0;
	map_data->start_pos[0] = 0;
	map_data->start_pos[1] = 0;
	map_data->exit_pos[0] = 0;
	map_data->exit_pos[1] = 0;
	map_data->tile = TILE_SIZE ;
}

/**
 * validate_args - Validates the command line arguments.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Ensures exactly one argument is passed and checks for the ".ber"
 * file extension.
 *
 * Return: 0 if arguments are valid, otherwise 1.
 */
static int	validate_args(int argc, char **argv)
{
	if (argc != 2)
		return (set_error("Usage: ./so_long <map_file>"));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		return (set_error("Invalid file extension"));
	return (0);
}

/**
 * @brief Frees allocated memory for the game map and visited array, and sets
 * their pointers to NULL.
 *
 * Cleans up dynamically allocated memory associated with the game map
 * and the visited array in the `t_game` structure.
 * Ensures that all memory is properly freed and pointers are
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
void	cleanup(t_game *game)
{
	if (game->map)
		free_game_arr((void **)game->map);
	if (game->visited)
		free_game_arr((void **)game->visited);
}

/**
 * main - Entry point for the so_long game.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Initializes game data, validates arguments, parses the map,
 * starts the game loop, and performs cleanup.
 *
 * Return: 0 on success, 1 if an error occurs.
 */
int	main(int argc, char **argv)
{
	t_game		game;
	t_meta		map_data;
	t_context	context;

	init_data(&game, &map_data);
	if (validate_args(argc, argv))
		return (1);
	game.file = argv[1];
	if (parse_and_validate(&game, &map_data))
	{
		cleanup(&game);
		return (1);
	}
	context.game = &game;
	context.meta = &map_data;
	run_game(&context);
	cleanup(&game);
	return (0);
}
