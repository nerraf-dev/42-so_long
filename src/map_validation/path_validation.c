/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 17:28:07 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * get_cell_type - Returns the type of the cell at (x, y).
 * @data: Pointer to the game structure.
 * @meta: Pointer to the map data structure.
 * @x: X-coordinate.
 * @y: Y-coordinate.
 *
 * Checks boundaries and returns the cell type:
 * WALL, START, EXIT, or COLLECTIBLE. Returns -1 if out-of-bounds.
 */
int	get_cell_type(t_game *data, t_meta *meta, int x, int y)
{
	if (x < 0 || x >= meta->line_length || y < 0
		|| y >= meta->line_count)
		return (-1);
	if (data->map[y][x] == K_WALL)
		return (K_WALL);
	if (data->map[y][x] == K_START)
		return (K_START);
	if (data->map[y][x] == K_EXIT)
		return (K_EXIT);
	if (data->map[y][x] == K_COLLECTIBLE)
		return (K_COLLECTIBLE);
	return (1);
}

/**
 * flood_fill - Explores the map starting from the start cell.
 * @data: Pointer to the game structure.
 * @meta: Pointer to the map data structure.
 *
 * Uses BFS to mark reachable cells, updating the exit flag and
 * counting collectibles.
 *
 * Return: 0 on success.
 */
int	flood_fill(t_game *data, t_meta *meta)
{
	t_queue			*queue;
	t_queue_node	*node;
	t_context		context;
	int				cell_type;

	context.game = data;
	context.meta = meta;
	queue = init_queue();
	enqueue(queue, meta->start_pos[0], meta->start_pos[1]);
	data->visited[meta->start_pos[1]][meta->start_pos[0]] = 1;
	while (queue->front)
	{
		node = dequeue(queue);
		if (!node)
			continue ;
		cell_type = get_cell_type(data, meta, node->x, node->y);
		if (cell_type == K_EXIT)
			data->exit = 1;
		else if (cell_type == K_COLLECTIBLE)
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
 * @meta: Pointer to the map data structure.
 *
 * Initializes the visited array, runs flood_fill, and then checks
 * if the exit and all collectibles are reachable.
 *
 * Return: 0 if valid, otherwise an error code.
 */
int	validate_path(t_game *game, t_meta *meta)
{
	create_visited(game, meta);
	if (!game->visited)
		return (
			set_error("Error: Failed to allocate memory for visited array."));
	init_visited(game, meta);
	print_visited(game->visited, meta->line_count, meta->line_length);
	flood_fill(game, meta);
	debug_print(game, meta);
	if (check_exit(game, meta))
		return (1);
	if (check_collectibles(game, meta))
		return (1);
	free_visited(game->visited, meta->line_count);
	return (0);
}
