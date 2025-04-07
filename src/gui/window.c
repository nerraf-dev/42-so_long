/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:24:33 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/07 11:46:49 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

// Function to handle the close event
// Function to handle the close event
int	close_window(t_game *game)
{
	// Destroy the window and clean up MiniLibX resources
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx); // Free the MiniLibX instance
	exit(0);         // Exit the program
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

void	load_window(t_game *game)
{
	// void	*params[2];

	// Initialize MiniLibX
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit(1);
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
	mlx_hook(game->mlx_win, 2, 1L << 0, (int (*)(int, void *))handle_keypress, game);
	// Start the MiniLibX event loop
	mlx_loop(game->mlx);
}
