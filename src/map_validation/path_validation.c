/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/07 12:27:37 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// Flood-Fill Algorithm:
// 1. Initialize a queue, `q`, with the starting position P.
// 2. While the queue is not empty:
//    a. Dequeue a position.
//    b. Check if it is E or C.
//    c. If it is E, return success.
//    d. If it is C, mark as collected.
//    e. For each adjacent cell (up, down, left, right):
// 	  i. If the cell is valid and not blocked:
// 		 - Mark as visited.
// 		 - Enqueue the cell.
// 3. If the queue is empty and E is not reached, return failure.
// 4. Check if the exit is reachable from the starting position.
// 5. Check if all collectibles are reachable from the starting position.
// 6. Check if all collectibles are reachable from the exit.
// 7. Check if the exit is reachable from all collectibles.
// 8. If all checks pass, return success.
// 9. If any check fails, return failure.

#include "../../inc/validate_path.h"

void	validate_path(t_game *game_data)
{
	// Game Data:
	// game_data->map = map passed as a 2D array
	// game_data->map_flags = map flags passed as a struct
	// game_data->map_flags.line_count = number of lines in the map
	// game_data->map_flags.line_length = length of each line
	// game_data->map_flags.player_count = number of players in the map
	// game_data->map_flags.exit_count = number of exits in the map
	// game_data->map_flags.collectible_count = number of collectibles in the map

	// Initialize the queue


}


void	bfs_validate_path(char **map, int start_x, int start_y, t_map_flags *flags)
{
	t_queue			*queue;
	t_queue_node	*current;
	int				x, y;
	int				collectible_count = 0;

	// Initialize the queue and enqueue the starting position
	queue = init_queue();
	enqueue(queue, start_x, start_y);

	while (queue->front != NULL)
	{
		// Dequeue the front node
		current = dequeue(queue);
		x = current->x;
		y = current->y;
		free(current);

		// Skip if out of bounds or already visited
		if (x < 0 || y < 0 || y >= flags->line_count || x >= flags->line_length || map[y][x] == 'V')
			continue;

		// Process the current cell
		if (map[y][x] == WALL) // Skip walls
			continue;
		if (map[y][x] == COLLECTIBLE) // Increment collectible counter
			collectible_count++;
		if (map[y][x] == EXIT) // Mark exit as reachable
			flags->exit_count--;

		// Mark the cell as visited
		map[y][x] = 'V';

		// Enqueue neighboring cells (up, down, left, right)
		enqueue(queue, x, y - 1); // Up
		enqueue(queue, x, y + 1); // Down
		enqueue(queue, x - 1, y); // Left
		enqueue(queue, x + 1, y); // Right
	}

	// Free the queue
	free_queue(queue);

	// Validate results
	if (collectible_count != flags->collectible_count)
		exit_with_error("Not all collectibles are reachable.\n");
	if (flags->exit_count != 0)
		exit_with_error("Exit is not reachable.\n");
}
