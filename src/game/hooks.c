/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:31:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/08 11:32:20 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief Closes the game window and frees allocated resources.
 * Destroys the window and display, frees the MLX pointer and map
 * memory, then exits the program.
 *
 * @param game: Pointer to the game structure.
 *
 * @return Does not return.
 */
int	close_window(t_context *context)
{
	cleanup(context->game);
	if (context->game->mlx_win)
		mlx_destroy_window(context->game->mlx, context->game->mlx_win);
	if (context->game->mlx)
		mlx_destroy_display(context->game->mlx);
	if (context->game->mlx)
		free(context->game->mlx);
	exit(0);
	return (0);
}

/**
 * @brief Handles key press events.
 *
 * If the Escape key is pressed, the game window is closed.
 *
 * @param keysym: The key symbol of the pressed key.
 * @param game: Pointer to the game structure.
 *
 * @return 0
 */
int	keypress(int keycode, t_context *context)
{
	if (keycode == XK_Escape)
		close_window(context);
	if (context->game->exit)
		return (0);
	if (keycode == XK_Up || keycode == XK_w)
		move_player(context, context->game->player_pos[0],
			context->game->player_pos[1] - 1);
	else if (keycode == XK_Down || keycode == XK_s)
		move_player(context, context->game->player_pos[0],
			context->game->player_pos[1] + 1);
	else if (keycode == XK_Left || keycode == XK_a)
		move_player(context, context->game->player_pos[0] - 1,
			context->game->player_pos[1]);
	else if (keycode == XK_Right || keycode == XK_d)
		move_player(context, context->game->player_pos[0] + 1,
			context->game->player_pos[1]);
	return (0);
}

int	expose_hook(t_context *context)
{
	display_images(context);
	return (0);
}

void	setup_hooks(t_context *context)
{
	t_game	*game;

	game = context->game;
	mlx_hook(game->mlx_win, 17, 0, (int (*)(void *))close_window, context);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, keypress, context);
	mlx_hook(game->mlx_win, Expose, ExposureMask, expose_hook, context);
}
