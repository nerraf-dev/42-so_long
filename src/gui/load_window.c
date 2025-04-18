/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:57:51 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/07 10:51:03 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Function to handle the close event
int	close_window(void *params[2])
{
	void	*mlx_win = params[0];
	void	*mlx = params[1];

	// Destroy the window and clean up MiniLibX resources
	if (mlx_win)
		mlx_destroy_window(mlx, mlx_win);
	if (mlx)
		mlx_destroy_display(mlx);
	free(mlx); // Free the MiniLibX instance
	exit(0);   // Exit the program
}

// Function to handle key presses
int	handle_keypress(int keysym, void *params[2])
{
	// if (keycode == 65307) // 65307 is the keycode for ESC
	if (keysym == XK_Escape)
		close_window(params);
	return (0);
}

void	load_window(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*params[2];

	mlx = mlx_init();
	if (mlx == NULL)
		exit(1);
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	if (mlx_win == NULL)
	{
		free(mlx);
		exit(1);
	}
	// Pass both mlx and mlx_win to the event handlers
	params[0] = mlx_win;
	params[1] = mlx;
	// Hook the close event (DestroyNotify) to the close_window function
	mlx_hook(mlx_win, 17, 0, (int (*)(void *))close_window, params);
	// Hook key press events to the handle_keypress function
	mlx_hook(mlx_win, 2, 1L << 0, (int (*)(int, void *))handle_keypress, params);
	// Start the MiniLibX event loop
	mlx_loop(mlx);
}

