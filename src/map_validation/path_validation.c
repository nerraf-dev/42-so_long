/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/24 11:10:41 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * get_cell_type - Returns the type of the cell at (x, y).
 * @data: Pointer to the game structure.
 * @map_data: Pointer to the map data structure.
 * @x: X-coordinate.
 * @y: Y-coordinate.
 *
 * Checks boundaries and returns the cell type:
 * WALL, START, EXIT, or COLLECTIBLE. Returns -1 if out-of-bounds.
 */
int	get_cell_type(t_game *data, t_m_data *map_data, int x, int y)
{
	if (x < 0 || x >= map_data->line_length || y < 0
		|| y >= map_data->line_count)
		return (-1);
	if (data->map[y][x] == WALL)
		return (WALL);
	if (data->map[y][x] == START)
		return (START);
	if (data->map[y][x] == EXIT)
		return (EXIT);
	if (data->map[y][x] == COLLECTIBLE)
		return (COLLECTIBLE);
	return (1);
}

/**
 * flood_fill - Explores the map starting from the start cell.
 * @data: Pointer to the game structure.
 * @map_data: Pointer to the map data structure.
 *
 * Uses BFS to mark reachable cells, updating the exit flag and
 * counting collectibles.
 *
 * Return: 0 on success.
 */
int	flood_fill(t_game *data, t_m_data *map_data)
{
	t_queue			*queue;
	t_queue_node	*node;
	t_context		context;
	int				cell_type;

	context.game = data;
	context.map_data = map_data;
	queue = init_queue();
	enqueue(queue, map_data->start[0], map_data->start[1]);
	data->visited[map_data->start[1]][map_data->start[0]] = 1;
	while (queue->front)
	{
		node = dequeue(queue);
		if (!node)
			continue ;
		cell_type = get_cell_type(data, map_data, node->x, node->y);
		if (cell_type == EXIT)
			data->exit = 1;
		else if (cell_type == COLLECTIBLE)
			data->collectibles++;
		check_adj(&context, queue, node);
		free(node);
	}
	clear_queue(queue);
	return (0);
}

/**
 * validate_path - Validates the map path using flood fill.
 * @game: Pointer to the game structure.
 * @map_data: Pointer to the map data structure.
 *
 * Initializes the visited array, runs flood_fill, and then checks
 * if the exit and all collectibles are reachable.
 *
 * Return: 0 if valid, otherwise an error code.
 */
int	validate_path(t_game *game, t_m_data *map_data)
{
	create_visited(game, map_data);
	if (!game->visited)
		return (
			set_error("Error: Failed to allocate memory for visited array."));
	init_visited(game, map_data);
	print_visited(game->visited, map_data->line_count, map_data->line_length);
	flood_fill(game, map_data);
	debug_print(game, map_data);
	if (check_exit(game, map_data))
		return (1);
	if (check_collectibles(game, map_data))
		return (1);
	free_visited(game->visited, map_data->line_count);
	return (0);
}
