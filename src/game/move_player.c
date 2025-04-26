/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:26 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 17:23:03 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	move_player(t_context *context, int new_x, int new_y)
{
	t_game	*game;
	t_meta	*meta;
	int		old_x;
	int		old_y;

	game = context->game;
	meta = context->meta;
	old_x = meta->player_pos[0];
	old_y = meta->player_pos[1];
	ft_printf("old pos: %d, %d \n", meta->player_pos[0], meta->player_pos[1]);
	if (game->map[new_y][new_x] != K_WALL)
	{
		game->map[old_y][old_x] = K_EMPTY;
		game->map[new_y][new_x] = K_START;
		meta->player_pos[0] = new_x;
		meta->player_pos[1] = new_y;
		ft_printf("updated player pos: %d, %d", meta->player_pos[0], meta->player_pos[1]);
		display_images(context);
	}
	else
	{
		ft_putstr_fd("Error: Cannot move into a wall.\n", 2);
	}
	ft_printf("new pos: %d, %d \n", meta->player_pos[0], meta->player_pos[1]);
	return (0);
}
