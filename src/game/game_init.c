/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 18:02:41 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

/**
 * @brief Closes the game window and frees allocated resources.
 * Destroys the window and display, frees the MLX pointer and map
 * memory, then exits the program.
 *
 * @param game: Pointer to the game structure.
 *
 * @return Does not return.
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
 * @brief Handles key press events.
 *
 * If the Escape key is pressed, the game window is closed.
 *
 * @param keysym: The key symbol of the pressed key.
 * @param game: Pointer to the game structure.
 *
 * @return 0
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
 * @return: 0 on success.
 */
int	run_game(t_context *context)
{
	t_game		*game;
	t_img		img;
	int			width;
	int			height;
	int			x;
	int			y;
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


	x = 0;
	y = 0;

	// TOP ROW
	img.filename = WALL_TL;
	ft_printf("Image path: %s\n", img.filename);
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y); // 0, 0
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_TOP;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + img.width, y);  // 48, 0
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_TOP;
	ft_printf("Image path: %s\n", img.filename);
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y); // 96, 0
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_TR;
	ft_printf("Image path: %s\n", img.filename);
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 3), y); // 144, 0
	mlx_destroy_image(game->mlx, img.img);

	// Middle row
	img.filename = WALL_SIDE_L;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y + img.width); // 0, 48
	mlx_destroy_image(game->mlx, img.img);

	img.filename = FLOOR_MID;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + img.width, y + img.width);
	mlx_destroy_image(game->mlx, img.img);

	img.filename = FLOOR_MID;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y + img.width);
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_SIDE_R;
	ft_printf("Image path: %s\n", img.filename);
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 3), y + img.width);
	mlx_destroy_image(game->mlx, img.img);

	// Bottom row
	img.filename = WALL_BASE_L;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y + (img.width * 2)); // 0, 48
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_BASE;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + img.width, y + (img.width * 2));
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_BASE;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y + (img.width * 2));
	mlx_destroy_image(game->mlx, img.img);

	img.filename = WALL_BASE_R;
	ft_printf("Image path: %s\n", img.filename);
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 3), y + (img.width * 2));
	mlx_destroy_image(game->mlx, img.img);

	// Plaer start at 1,1
	img.filename = PLAYER_RIGHT;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + 52, y  + 48);  // 48 is tile width, player width is smaller
	mlx_destroy_image(game->mlx, img.img);

	img.filename = MAP_EXIT;
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y + img.width);
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
