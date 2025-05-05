/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:26 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 19:46:30 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// static int	exit_level(t_context *context)
// {
// 	t_game	*game;
// 	t_meta	*meta;

// 	game = context->game;
// 	meta = context->meta;
// 	if (game->player_pos[0] == meta->exit_pos[0]
// 		&& game->player_pos[1] == meta->exit_pos[1])
// 	{
// 		if (game->collectibles != meta->collectible_count)
// 			ft_printf("You need to collect all collectibles before exiting!\n");
// 		else
// 			game->exit = 1;
// 	}
// 	else if (game->exit && game->collectibles == meta->collectible_count)
// 	{
// 		ft_printf("You have exited the level!\n");
// 	}
// 	return (0);
// }

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
		else if (game->map[new_y][new_x] == K_EXIT)
			game->exit++;
		game->map[old_y][old_x] = K_EMPTY;
		game->map[new_y][new_x] = K_START;
		game->player_pos[0] = new_x;
		game->player_pos[1] = new_y;
		game->steps++;
		display_images(context);
	}

	ft_printf("Steps: %d\n", game->steps);
	return (0);
}
