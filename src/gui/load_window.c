/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:57:51 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/04 13:26:00 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// Function to handle the close event
static int	close_window(void *mlx)
{
	mlx_destroy_display(mlx); // Clean up the display
	free(mlx);                // Free the MiniLibX instance
	exit(0);                  // Exit the program
}

// Function to handle key presses
int	handle_keypress(int keycode, void *mlx)
{
	if (keycode == 65307) // 65307 is the keycode for ESC
		close_window(mlx);
	return (0);
}

void	load_window(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (mlx == NULL)
		exit(1);
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx);
		exit(1);
	}

	// Hook the close event (DestroyNotify) to the close_window function
	mlx_hook(mlx_win, 17, 0, close_window, mlx);

	// Hook key press events to the handle_keypress function
	mlx_hook(mlx_win, 2, 1L << 0, handle_keypress, mlx);

	mlx_loop(mlx);
}
