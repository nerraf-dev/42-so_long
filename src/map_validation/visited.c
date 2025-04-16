/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:19:48 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/15 15:07:40 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

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

void	set_pos(int row, int col, t_game *data)
{
	if (data->map[row][col] == START)
	{
		data->flags.start[0] = col;
		data->flags.start[1] = row;
	}
	else if (data->map[row][col] == EXIT)
	{
		data->flags.exit[0] = col;
		data->flags.exit[1] = row;
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
			else if (data->map[row][col] == START ||
				data->map[row][col] == EXIT)
			{
				visited[row][col] = 1;
				set_pos(row, col, data);
			}
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
