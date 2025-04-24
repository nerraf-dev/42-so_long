/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/24 11:12:19 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

/**
 * close_window - Closes the game window and frees allocated resources.
 * @game: Pointer to the game structure.
 *
 * Destroys the window and display, frees the MLX pointer and map
 * memory, then exits the program.
 *
 * Return: Does not return.
 */
int	close_window(t_game *game)
{
	int	i;

	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
	return (0);
}

/**
 * keypress - Handles key press events.
 * @keysym: The key symbol of the pressed key.
 * @game: Pointer to the game structure.
 *
 * If the Escape key is pressed, the game window is closed.
 *
 * Return: 0.
 */
int	keypress(int keysym, t_game	*game)
{
	// Check if the pressed key is the ESC key
	// if (keycode == 65307) // 65307 is the keycode for ESC
	if (keysym == XK_Escape)
		close_window(game);
	return (0);
}

/**
 * run_game - Sets up and runs the main game loop.
 * @context: Pointer to the context structure containing game state.
 *
 * Initializes MLX, creates a window, renders images, hooks events,
 * and starts the event loop.
 *
 * Return: 0 on success.
 */
int	run_game(t_context *context)
{
	t_game		*game;
	t_img		img;
	int			width;
	int			height;
	int			i;
	// void	*img;

	width = 640;
	height = 480;
	game = context->game;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	ft_printf("MLX initialized.\n");
	game->mlx_win = mlx_new_window(game->mlx, width, height, "Hello world!");
	if (game->mlx_win == NULL)
	{
		free(game->mlx);
		exit(1);
	}
	i = 50;
	// img.filename = "./assets/misc/sprout_lands/Tilesets/Wooden_House_Walls_Tilset.xpm";
	img.filename = WALL_TL;
	ft_printf("Image path: %s\n", img.filename);
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, i, i);
	mlx_destroy_image(game->mlx, img.img);
	img.filename = WALL_TOP;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, i + img.width, i);
	mlx_destroy_image(game->mlx, img.img);
	img.filename = WALL_LEFT;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, i, i + img.width);
	mlx_destroy_image(game->mlx, img.img);

	// Display the background (floor)
	// Display the walls, exit (and start)
	// Display the collectibles
	// Display the player


	mlx_hook(game->mlx_win, 17, 0, (int (*)(void *))close_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0,
		(int (*)(int, void *))keypress, game);

	// mlx_loop_hook();
	mlx_loop(game->mlx);

	return (0);
}
