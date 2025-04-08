/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/08 12:51:37 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

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
int **create_visited(int height, int width)
{
	int **visited;
	int i;

	visited = ft_calloc(height, sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = ft_calloc(width, sizeof(int));
		if (!visited[i])
		{
			while (i > 0)
			{
				i--;
				free(visited[i]);
			}
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

void init_visited(t_game *data, int **visited)
{
	int x;
	int y;

	y = 0;
	while (y < data->map_flags.line_count)
	{
		x = 0;
		while (x < data->map_flags.line_length)
		{
			if (data->map[y][x] == WALL)
				visited[y][x] = 1;
			else
				visited[y][x] = 0;
			x++;
		}
		y++;
	}
}

void print_visited(int **visited, int height, int width)
	{
		int y, x;

		y = 0;
		while (y < height)
		{
			x = 0;
			while (x < width)
			{
				printf("%d ", visited[y][x]);
				x++;
			}
			printf("\n");
			y++;
		}
	}

void validate_path(t_game *game_data)
{
	int **visited;
	// t_queue *queue;

	visited = create_visited(game_data->map_flags.line_count,
							 game_data->map_flags.line_length);
	if (!visited)
		exit_with_error("Error: Failed to allocate memory for visited array.");
	init_visited(game_data, visited);

	ft_printf("\nVisited array:\n");
	ft_printf("*****""*****\n");
	print_visited(visited, game_data->map_flags.line_count, game_data->map_flags.line_length);
}
