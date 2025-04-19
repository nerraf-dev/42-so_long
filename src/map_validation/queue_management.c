/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:10:38 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/19 12:18:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

void	enqueue(t_queue *queue, int x, int y)
{
	t_queue_node	*node;

	node = malloc(sizeof(t_queue_node));
	if (!node)
		set_error("Error: Failed to allocate memory for queue node.");
	node->x = x;
	node->y = y;
	node->next = NULL;
	if (queue->rear)
		queue->rear->next = node;
	queue->rear = node;
	if (queue->front == NULL)
		queue->front = node;
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

void	clear_queue(t_queue *queue)
{
	t_queue_node	*node;

	while (queue->front)
	{
		node = dequeue(queue);
		free(node);
	}
	free(queue);
}
