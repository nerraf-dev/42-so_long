/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/06 16:56:04 by sfarren          ###   ########.fr       */
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

void	validate_path(char **map, t_map_flags *flags)
{
	// Map passed as a 2D array
	// flags->line_count = number of lines in the map
	// flags->line_length = length of each line
	// flags->player_count = number of players in the map
	// flags->exit_count = number of exits in the map
	// flags->collectible_count = number of collectibles in the map

	
}
