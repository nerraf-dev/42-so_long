/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/15 12:16:54 by sfarren          ###   ########.fr       */
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
int	**create_visited(int height, int width)
{
	int	**visited;
	int	i;

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

void	set_pos(int **visited, int row, int col, t_game *data)
{
	if (data->map[row][col] == START)
	{
		visited[row][col] = START;
		data->flags.start_pos[0] = col;
		data->flags.start_pos[1] = row;
	}
	else if (data->map[row][col] == EXIT)
	{
		visited[row][col] = EXIT;
		data->flags.exit_pos[0] = col;
		data->flags.exit_pos[1] = row;
	}
}

void	init_visited(t_game *data, int **visited)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->flags.line_count)
	{
		col = 0;
		while (col < data->flags.line_length)
		{
			if (data->map[row][col] == WALL)
				visited[row][col] = 1;
			else if (data->map[row][col] == START || data->map[row][col] == EXIT)
				set_pos(visited, row, col, data);
			else
				visited[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	print_visited(int **visited, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ft_printf("%d ", visited[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	validate_path(t_game *game_data)
{
	int	**visited;

	visited = create_visited(game_data->flags.line_count,
			game_data->flags.line_length);
	if (!visited)
		exit_with_error("Error: Failed to allocate memory for visited array.");
	init_visited(game_data, visited);
	ft_printf("\nVisited array:\n");
	ft_printf("*****""*****\n");
	print_visited(visited, game_data->flags.line_count, game_data->flags.line_length);
	ft_printf("Start position: [%d, %d]\n",
		game_data->flags.start_pos[0], game_data->flags.start_pos[1]);
	ft_printf("Exit position: [%d, %d]\n",
		game_data->flags.exit_pos[0], game_data->flags.exit_pos[1]);
	// Implement the flood-fill algorithm here
	// get start position
	free_visited(visited, game_data->flags.line_count);
}
