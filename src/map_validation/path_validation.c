/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:44:16 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/16 13:48:58 by sfarren          ###   ########.fr       */
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

	ft_printf("Enqueue [%d, %d]\n", y, x);
	node = malloc(sizeof(t_queue_node));
	if (!node)
		exit_with_error("Error: Failed to allocate memory for queue node.");
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
	ft_printf("Enqueued [%d, %d]\n", node->y, node->x);
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
		exit_with_error("Error: Failed to allocate memory for queue.");
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
int	check_cell(t_game *data, int x, int y)
{
	if (x < 0 || x >= data->flags.line_length || y < 0
		|| y >= data->flags.line_count)
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

int	flood_fill(t_game *data, int **visited)
{
	t_queue			*queue;
	t_queue_node	*node;
	int				c_count;
	int				cell_type;

	c_count = 0;
	// Initialize the queue
	queue = init_queue();
	ft_printf("Queue initialized.\n");
	// Initialize the queue with the starting position
	enqueue(queue, data->flags.start[0], data->flags.start[1]);
	ft_printf("Enqueue start position [%d, %d]\n",
		data->flags.start[1], data->flags.start[0]);
	// Mark the starting position as visited
	visited[data->flags.start[1]][data->flags.start[0]] = 1;
	while (queue->front)
	{
		node = dequeue(queue);
		// if node is null, the queue is empty
		if (!node)
		{
			ft_printf("Queue is empty.\n");
			// clean up memory  (need to make function)
			// return (0);
		}
		// Check if the cell is valid and get type
		cell_type = check_cell(data, node->x, node->y);
		ft_printf("Checking cell [%d, %d] - Type: %d\n",
			node->y, node->x, cell_type);
		if (cell_type == EXIT)
		{
			ft_printf("Exit found at [%d, %d]\n", node->y, node->x);
			// Clean up queue memory and remaining nodes
			free(node);
			break ;
		}
		// If it is a collectible update the counter
		else if (cell_type == COLLECTIBLE)
		{
			c_count++;
			ft_printf("Collectible found at [%d, %d]\n", node->y, node->x);
			ft_printf("Collectible count: %d\n", c_count);
		}
		// Check surounding cells on visited array
		//   if not visited and not a wall (i.e. not '1')
		//   enqueue the cell and mark it as visited
		if (cell_type == -1)
		{
			ft_printf("Invalid cell [%d, %d]\n", node->y, node->x);
			free(node);
			continue;
		}

	}
	// Free the queue and all its nodes
	while (queue->front)
	{
		node = dequeue(queue);
		free(node);
	}
	free(queue);
	if (node)
		free(node);
	ft_printf("Queue cleaned up.\n");
	return (0);
}

void	validate_path(t_game *data)
{
	int	**visited;

	visited = create_visited(data->flags.line_count,
			data->flags.line_length);
	if (!visited)
		exit_with_error("Error: Failed to allocate memory for visited array.");
	init_visited(data, visited);
	ft_printf("\nVisited array:\n");
	ft_printf("*****""*****\n");
	print_visited(visited, data->flags.line_count, data->flags.line_length);
	flood_fill(data, visited);
	ft_printf("*****""*****\n");
	print_visited(visited, data->flags.line_count, data->flags.line_length);
	ft_printf("Start position: [%d, %d]\n",
		data->flags.start[0], data->flags.start[1]);
	ft_printf("Exit position: [%d, %d]\n",
		data->flags.exit[0], data->flags.exit[1]);



	free_visited(visited, data->flags.line_count);
}
