/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 22:33:41 by sfarren          ###   ########.fr       */
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

void	enqueue(t_queue *queue, int x, int y)
{
	t_queue_node	*node;

	node = malloc(sizeof(t_queue_node));
	if (!node)
		set_error("Error: Failed to allocate memory for queue node.");
	ft_printf("NODE ALLOCATED\n");
	node->x = x;
	node->y = y;
	node->next = NULL;

	//  This should handle the queue is empty or in use
	//  Check if there is a node at the rear postion
	//  If so set that node to point at the new node.
	//  Then set the rear pointer to the new node.
	//  Check if the front is NULL - empty queue check
	//  if so set the front to the new node.
	if (queue->rear)
		queue->rear->next = node;
	queue->rear = node;
	if (queue->front == NULL)
		queue->front = node;
	// ft_printf("Enqueued [%d, %d]\n", node->y, node->x);
}

t_queue_node	*dequeue(t_queue *queue)
{
	t_queue_node	*node;

	if (queue->front == NULL)
		return (NULL);
	node = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	return (node);
}


// Initialise the queue with the starting position
t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		set_error("Error: Failed to allocate memory for queue.");
	queue->front = NULL;
	queue->rear = NULL;

	return (queue);
}

/**
 * valid_position - Checks if a given position (x, y) is valid within the game map.
 *
 * @data: Pointer to the game structure containing map and flags information.
 * @x: The x-coordinate of the position to validate.
 * @y: The y-coordinate of the position to validate.
 *
 * Return:
 *   1 if the position is valid (within bounds and not a wall).
 *   0 if the position is invalid (out of bounds or a wall).
 *
 * This function ensures that the given position is within the boundaries of the
 * game map and does not correspond to a wall tile.
 */
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
	int				cell_type;

	// Initialize the queue
	queue = init_queue();
	ft_printf("Queue initialized.\n");
	// Initialize the queue with the starting position
	enqueue(queue, map_data->start[0], map_data->start[1]);
	ft_printf("Enqueue start position [%d, %d]\n",
		map_data->start[0], map_data->start[1]);
	// Mark the starting position as visited
	ft_printf("---starting position [%d, %d]---\n",
		map_data->start[0], map_data->start[1]);
	data->visited[map_data->start[1]][map_data->start[0]] = 1;
	ft_printf("Visited start position [%d, %d]\n",
		map_data->start[0], map_data->start[1]);
	while (queue->front)
	{
		node = dequeue(queue);
		if (!node)
			continue ;
		// Check if the cell is valid and get type
		cell_type = get_cell_type(data, map_data, node->x, node->y);
		ft_printf("Checking cell [%d, %d] - Type: %d\n",
			node->x, node->y, cell_type);
		if (cell_type == EXIT)
		{
			data->exit = 1;
			ft_printf("***Exit found at [%d, %d]***\n", node->y, node->x);
			// free(node);
			// break ;
		}
		// If it is a collectible update the counter
		else if (cell_type == COLLECTIBLE)
		{
			data->collectibles++;
			ft_printf("---Collectible found at [%d, %d]----\n", node->y, node->x);
			ft_printf("Collectible count: %d\n", data->collectibles);
		}
		// Check surounding cells on visited array
		//   if not visited and not a wall (i.e. not '1')
		//   enqueue the cell and mark it as visited
		// if the type is not a wall, not marked vistied, and not -1 (error)
		//    enqueue the cell and mark it as visited.
		// UP:
		cell_type = get_cell_type(data, map_data, node->x, node->y - 1);
		if (cell_type != WALL && cell_type != -1
			&& data->visited[node->y - 1][node->x] == 0)
			{
				enqueue(queue, node->x, node->y - 1);
				data->visited[node->y - 1][node->x] = 1;
				ft_printf("Enqueued UP [%d, %d]\n",
					node->x, node->y - 1);
			}
		// DOWN:
		cell_type = get_cell_type(data, map_data, node->x, node->y + 1);
		if (cell_type != WALL && cell_type != -1
			&& data->visited[node->y + 1][node->x] == 0)
			{
				enqueue(queue, node->x, node->y + 1);
				data->visited[node->y + 1][node->x] = 1;
				ft_printf("Enqueued DOWN [%d, %d]\n",
					node->x, node->y + 1);
			}
		// LEFT:
		cell_type = get_cell_type(data, map_data, node->x - 1, node->y);
		if (cell_type != WALL && cell_type != -1
			&& data->visited[node->y][node->x - 1] == 0)
			{
				enqueue(queue, node->x - 1, node->y);
				data->visited[node->y][node->x - 1] = 1;
				ft_printf("Enqueued LEFT [%d, %d]\n",
					node->x - 1, node->y);
			}
		// RIGHT:
		cell_type = get_cell_type(data, map_data, node->x + 1, node->y);
		if (cell_type != WALL && cell_type != -1
			&& data->visited[node->y][node->x + 1] == 0)
			{
				enqueue(queue, node->x + 1, node->y);
				data->visited[node->y][node->x + 1] = 1;
				ft_printf("Enqueued RIGHT [%d, %d]\n",
					node->x + 1, node->y);
			}
		free(node);
		ft_printf("Nodes in queue: %d\n", queue->front);
	}
	ft_printf("QUEUE EMPTY\n");
	// Free the queue and all its nodes
	while (queue->front)
	{
		node = dequeue(queue);
		free(node);
	}
	free(queue);
	ft_printf("Queue cleaned up.\n");
	return (0);
}

int	validate_path(t_game *game, t_m_data *map_data)
{
	create_visited(game, map_data);
	if (!game->visited)
		set_error("Error: Failed to allocate memory for visited array.");
	init_visited(game, map_data);
	ft_printf("\nVisited array:\n");
	ft_printf("*****""*****\n");
	print_visited(game->visited, map_data->line_count, map_data->line_length);
	flood_fill(game, map_data);
	ft_printf("*****""*****\n");
	print_visited(game->visited, map_data->line_count, map_data->line_length);
	ft_printf("Start position: [%d, %d]\n",
		map_data->start[0], map_data->start[1]);
	ft_printf("Exit position: [%d, %d]\n",
		map_data->exit[0], map_data->exit[1]);
	ft_printf("Collectibles found: %d\n", game->collectibles);
	ft_printf("Collectible count: %d\n", map_data->collectible_count);
	ft_printf("Exit found: %d\n", game->exit);
	ft_printf("--Exit count: %d\n", map_data->exit_count);


	

	free_visited(game->visited, map_data->line_count);
	return (0);
}
