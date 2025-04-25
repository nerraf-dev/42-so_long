/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_adjacent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:47:12 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 17:14:37 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../../inc/validate_path.h"

void	check_and_enqueue(t_context *context, t_queue *queue, int x, int y)
{
	int	cell_type;

	cell_type = get_cell_type(context->game, context->meta, x, y);
	if (cell_type != K_WALL && cell_type != -1
		&& context->game->visited[y][x] == 0)
	{
		enqueue(queue, x, y);
		context->game->visited[y][x] = 1;
	}
}
