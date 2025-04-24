/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:12:30 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/24 10:45:51 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_exit(t_game *game, t_m_data *map_data)
{
	if (game->exit == 0)
	{
		free_visited(game->visited, map_data->line_count);
		game->visited = NULL;
		ft_printf("Exit not found.\n");
		return (set_error("Error: Exit not reachable from start position.\n"));
	}
	return (0);
}

int	check_collectibles(t_game *game, t_m_data *map_data)
{
	if (game->collectibles != map_data->collectible_count)
	{
		free_visited(game->visited, map_data->line_count);
		game->visited = NULL;
		ft_printf("Not all collectibles found.\n");
		return (set_error("Error: Not all collectibles reachable.\n"));
	}
	return (0);
}

void	check_adj(t_context *context, t_queue *queue, t_queue_node *node)
{
	check_and_enqueue(context, queue, node->x, node->y - 1);
	check_and_enqueue(context, queue, node->x, node->y + 1);
	check_and_enqueue(context, queue, node->x - 1, node->y);
	check_and_enqueue(context, queue, node->x + 1, node->y);
}
