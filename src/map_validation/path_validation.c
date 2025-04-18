/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/19 00:12:54 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

int	get_cell_type(t_game *data, t_m_data *map_data, int x, int y)
{
	if (x < 0 || x >= map_data->line_length || y < 0
		|| y >= map_data->line_count)
		return (-1);
	if (data->map[y][x] == WALL)
		return (WALL);
	if (data->map[y][x] == START)
		return (START);
	if (data->map[y][x] == EXIT)
		return (EXIT);
	if (data->map[y][x] == COLLECTIBLE)
		return (COLLECTIBLE);
	return (1);
}

int	flood_fill(t_game *data, t_m_data *map_data)
{
	t_queue			*queue;
	t_queue_node	*node;
	t_context		context;
	int				cell_type;

	context.game = data;
	context.map_data = map_data;
	queue = init_queue();
	enqueue(queue, map_data->start[0], map_data->start[1]);
	data->visited[map_data->start[1]][map_data->start[0]] = 1;
	while (queue->front)
	{
		node = dequeue(queue);
		if (!node)
			continue ;
		cell_type = get_cell_type(data, map_data, node->x, node->y);
		if (cell_type == EXIT)
			data->exit = 1;
		else if (cell_type == COLLECTIBLE)
			data->collectibles++;
		check_and_enqueue(&context, queue, node->x, node->y - 1);
		check_and_enqueue(&context, queue, node->x, node->y + 1);
		check_and_enqueue(&context, queue, node->x - 1, node->y);
		check_and_enqueue(&context, queue, node->x + 1, node->y);
		free(node);
		ft_printf("Nodes in queue: %d\n", queue->front);
	}
	ft_printf("QUEUE EMPTY\n");
	clear_queue(queue);
	ft_printf("Queue cleaned up.\n");
	return (0);
}

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

int	validate_path(t_game *game, t_m_data *map_data)
{
	create_visited(game, map_data);
	if (!game->visited)
		return (
			set_error("Error: Failed to allocate memory for visited array."));
	init_visited(game, map_data);
	print_visited(game->visited, map_data->line_count, map_data->line_length);
	flood_fill(game, map_data);
	debug_print(game, map_data);
	if (game->exit == 0)
	{
		free_visited(game->visited, map_data->line_count);
		game->visited = NULL;
		ft_printf("Exit not found.\n");
		return (set_error("Error: Exit not reachable from start position.\n"));
	}
	if (game->collectibles != map_data->collectible_count)
	{
		free_visited(game->visited, map_data->line_count);
		game->visited = NULL;
		ft_printf("Not all collectibles found.\n");
		return (set_error("Error: Not all collectibles reachable.\n"));
	}
	free_visited(game->visited, map_data->line_count);
	return (0);
}
