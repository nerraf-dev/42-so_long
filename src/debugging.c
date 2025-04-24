/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:58:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/24 09:59:26 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

// TODO: DELETE THIS
void	debug_print(t_game *game, t_m_data *map_data)
{
	print_visited(game->visited, map_data->line_count, map_data->line_length);
	ft_printf("Start position: [%d, %d]\n",
		map_data->start[0], map_data->start[1]);
	ft_printf("Exit position: [%d, %d]\n",
		map_data->exit[0], map_data->exit[1]);
	ft_printf("Collectibles found: %d\n", game->collectibles);
	ft_printf("Collectible count: %d\n", map_data->collectible_count);
	ft_printf("Exit found: %d\n", game->exit);
	ft_printf("--Exit count: %d\n", map_data->exit_count);
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
