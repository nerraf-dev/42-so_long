/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:26 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/08 11:15:38 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	move_player(t_context *context, int new_x, int new_y)
{
	t_game	*game;
	int		old_x;
	int		old_y;

	game = context->game;
	old_x = game->player_pos[0];
	old_y = game->player_pos[1];
	if (game->map[new_y][new_x] != K_WALL)
	{
		if (game->map[new_y][new_x] == K_COLLECTIBLE)
			game->collectibles++;
		else if (game->map[new_y][new_x] == K_EXIT
			&& game->collectibles == context->meta->collectible_count)
			game->exit++;
		ft_printf("Exit: %d\n", game->exit);
		game->map[old_y][old_x] = K_EMPTY;
		game->map[new_y][new_x] = K_START;
		game->player_pos[0] = new_x;
		game->player_pos[1] = new_y;
		game->steps++;
		display_image_move(context, old_x, old_y);
	}
	ft_printf("Steps: %d\n", game->steps);
	return (0);
}
