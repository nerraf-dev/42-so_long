/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 13:30:37 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * check_exit - Validates if the exit is reachable from the start position.
 * @game: Pointer to the game structure.
 * @meta: Pointer to the map data structure.
 *
 * Frees the visited array and sets an error if the exit is not reachable.
 *
 * Return: 0 if the exit is reachable, otherwise an error code.
 */
int	check_exit(t_game *game)
{
	if (game->exit == 0)
	{
		game->visited = NULL;
		return (set_error("Exit not reachable from start position."));
	}
	game->exit = 0;
	return (0);
}

/**
 * check_collectibles - Validates if all collectibles are reachable.
 * @game: Pointer to the game structure.
 * @meta: Pointer to the map data structure.
 *
 * Frees the visited array and sets an error if not all collectibles
 * are reachable.
 *
 * Return: 0 if all collectibles are reachable, otherwise an error code.
 */
int	check_collectibles(t_game *game, t_meta *meta)
{
	if (game->collectibles != meta->collectible_count)
	{
		game->visited = NULL;
		return (set_error("Not all collectibles reachable."));
	}
	game->collectibles = 0;
	return (0);
}

/**
 * check_adj - Checks adjacent positions and enqueues them if valid.
 * @context: Pointer to the context structure containing game state.
 * @queue: Pointer to the queue used for BFS traversal.
 * @node: Pointer to the current queue node being processed.
 *
 * Enqueues valid adjacent positions (up, down, left, right) for further
 * processing in the BFS traversal.
 */
void	check_adj(t_context *context, t_queue *queue, t_queue_node *node)
{
	check_and_enqueue(context, queue, node->x, node->y - 1);
	check_and_enqueue(context, queue, node->x, node->y + 1);
	check_and_enqueue(context, queue, node->x - 1, node->y);
	check_and_enqueue(context, queue, node->x + 1, node->y);
}
