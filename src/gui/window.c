/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:24:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 22:19:47 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

// Function to handle the close event
// Function to handle the close event
int	close_window(t_game *game)
{
	// int	i;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	// i = 0;
	// while (game->map[i])
	// {
	// 	free(game->map[i]);
	// 	i++;
	// }
	// free(game->map);
	// exit(0);
	return (0);
}

// Function to handle key presses
int	handle_keypress(int keysym, t_game	*game)
{
	// Check if the pressed key is the ESC key
	// if (keycode == 65307) // 65307 is the keycode for ESC
	if (keysym == XK_Escape)
		close_window(game);
	return (0);
}

int	load_window(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	// Create a new window
	game->mlx_win = mlx_new_window(game->mlx, 640, 480, "Hello world!");
	if (game->mlx_win == NULL)
	{
		free(game->mlx);
		exit(1);
	}
	// Hook the close event (DestroyNotify) to the close_window function
	mlx_hook(game->mlx_win, 17, 0, (int (*)(void *))close_window, game);
	// Hook key press events to the handle_keypress function
	mlx_hook(game->mlx_win, 2, 1L << 0,
		(int (*)(int, void *))handle_keypress, game);
	return (0);
}
