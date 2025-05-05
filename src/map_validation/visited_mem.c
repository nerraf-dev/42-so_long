/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:19:48 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 13:35:58 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

/**
 * @brief Allocates and initializes a 2D array to track visited positions
 *        in the map.
 * Creates a 2D array of integers, all elements initialized to 0.
 * The array is used to track visited positions in the game map.
 * Memory is allocated dynamically for both the outer array
 * (rows) and each inner array (columns).
 *
 * @param data Pointer to the game structure containing the visited array.
 * @param meta Pointer to the map data structure containing map
 *                 dimensions.
 *
 * @return int Returns 0 on success, or 1 if memory allocation fails.
 *
 * @note If memory allocation for any row fails, the function frees all
 *       previously allocated memory to prevent memory leaks.
 */
int	create_visited(t_game *data, t_meta *meta)
{
	int	i;

	data->visited = ft_calloc(meta->line_count, sizeof(int *));
	if (!data->visited)
		return (1);
	i = 0;
	while (i < meta->line_count)
	{
		data->visited[i] = ft_calloc(meta->line_length, sizeof(int));
		if (!data->visited[i])
		{
			while (i > 0)
			{
				i--;
				free(data->visited[i]);
			}
			free(data->visited);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Initializes the `visited` matrix for the game map.
 *
 * This function iterates through the game map and sets the corresponding
 * values in the `visited` matrix. If a cell in the map contains a wall
 * (denoted by `WALL`), the corresponding cell in the `visited` matrix
 * is set to 1. Otherwise, it is set to 0.
 *
 * @param data Pointer to the game structure (`t_game`) containing the map
 *             and the `visited` matrix.
 * @param meta Pointer to the map data structure (`t_m_data`) containing
 *                 information about the map dimensions (line count and
 *                 line length).
 */
void	init_visited(t_game *data, t_meta *meta)
{
	int	row;
	int	col;

	row = 0;
	while (row < meta->line_count)
	{
		col = 0;
		while (col < meta->line_length)
		{
			if (data->map[row][col] == K_WALL)
				data->visited[row][col] = 1;
			else
				data->visited[row][col] = 0;
			col++;
		}
		row++;
	}
}

/**
 * @brief Frees memory allocated for the 'visited' array and sets the
 * pointer to NULL.
 *
 * Iterates through each row of the 2D array, freeing the memory
 * allocated for each row. After all rows are freed, it frees the memory
 * allocated for the array of pointers itself. Finally, it sets the pointer to
 * NULL to avoid dangling pointers.
 *
 * @param visited A pointer to the 2D array of integers to be freed.
 * @param rows The number of rows in the 2D array.
 */
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
	visited = NULL;
}
