/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:46:23 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/21 15:33:56 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_PATH_H
# define VALIDATE_PATH_H

# include "../lib/libft/src/libft.h"

// Node structure for the queue
// The x and y coordinates represent the position in the map
// The next pointer points to the next node in the queue
// The queue is used to implement the flood-fill algorithm
typedef struct s_queue_node
{
	int					x;
	int					y;
	// char				type;	// P, C, E, 1, 0
	struct s_queue_node	*next;
}	t_queue_node;

// Queue structure
// The front pointer points to the first node in the queue
// The rear pointer points to the last node in the queue
typedef struct s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
}	t_queue;

// Function prototypes
int				create_visited(t_game *game, t_m_data *map_data);
void			init_visited(t_game *data, t_m_data *map_data);
void			free_visited(int **visited, int rows);
void			check_and_enqueue(t_context *context, t_queue *queue, int x, int y);
void			enqueue(t_queue *queue, int x, int y);
t_queue_node	*dequeue(t_queue *queue);
t_queue			*init_queue(void);
void			clear_queue(t_queue *queue);
int				get_cell_type(t_game *data, t_m_data *map_data, int x, int y);
void			print_visited(int **visited, int height, int width);

#endif
