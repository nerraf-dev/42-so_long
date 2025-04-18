/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visited.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:19:48 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 23:33:48 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

int	create_visited(t_game *data, t_m_data *map_data)
{
	int	i;

	data->visited = ft_calloc(map_data->line_count, sizeof(int *));
	if (!data->visited)
		return (1);
	i = 0;
	while (i < map_data->line_count)
	{
		data->visited[i] = ft_calloc(map_data->line_length, sizeof(int));
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

void	init_visited(t_game *data, t_m_data *map_data)
{
	int	row;
	int	col;

	row = 0;
	while (row < map_data->line_count)
	{
		col = 0;
		while (col < map_data->line_length)
		{
			if (data->map[row][col] == WALL)
				data->visited[row][col] = 1;
			else
				data->visited[row][col] = 0;
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
	ft_printf("\nVisited array:\n");
	ft_printf("*****""*****\n");
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
	visited = NULL;
}
