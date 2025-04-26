/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 11:40:13 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

void	destroy_images(t_game *game, int image_type)
{
	int		i;
	t_img	*images;

	if (image_type == WALL_IMAGES)
		images = game->images.walls;
	else if (image_type == FLOOR_IMAGES)
		images = game->images.floors;
	else if (image_type == PLAYER_IMAGES)
		images = game->images.player;
	else if (image_type == COLLECTIBLE_IMAGES)
		images = game->images.collectibles;
	else if (image_type == EXIT_IMAGES)
		images = game->images.exit;
	else
		return ;
	i = 0;
	while (i < image_type)
	{
		if (images[i].img)
			mlx_destroy_image(game->mlx, images[i].img);
		i++;
	}
}

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
	// int	i;

	// destroy_images(context->game, WALL_IMAGES);
	// destroy_images(context->game, FLOOR_IMAGES);
	// destroy_images(context->game, PLAYER_IMAGES);
	// destroy_images(context->game, COLLECTIBLE_IMAGES);
	// destroy_images(context->game, EXIT_IMAGES);
	if (context->game->mlx_win)
		mlx_destroy_window(context->game->mlx, context->game->mlx_win);
	if (context->game->mlx)
		mlx_destroy_display(context->game->mlx);
	if (context->game->mlx)
		free(context->game->mlx);
	// i = 0;
	// while (game->map[i])
	// {
	// 	free(game->map[i]);
	// 	i++;
	// }
	// free(game->map);
	cleanup(context->game, context->meta);
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
int	keypress(int keysym, t_context *context)
{
	// Check if the pressed key is the ESC key
	// if (keycode == 65307) // 65307 is the keycode for ESC
	if (keysym == XK_Escape)
		close_window(context);
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
	// t_img		img;
	int			width;
	int			height;
	// int			x;
	// int			y;
	// void	*img;

	width = TILE_SIZE * context->meta->line_length;
	height = TILE_SIZE * context->meta->line_count;
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

	if (load_images(context))
		return (1);
	display_images(context);

	// x = 0;
	// y = 0;

	// // TOP ROW
	// img.filename = WALL_TL;
	// ft_printf("Image path: %s\n", img.filename);
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y); // 0, 0
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_TOP;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + img.width, y);  // 48, 0
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_TOP;
	// ft_printf("Image path: %s\n", img.filename);
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y); // 96, 0
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_TR;
	// ft_printf("Image path: %s\n", img.filename);
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 3), y); // 144, 0
	// mlx_destroy_image(game->mlx, img.img);

	// // Middle row
	// img.filename = WALL_SIDE_L;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y + img.width); // 0, 48
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = FLOOR_MID;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + img.width, y + img.width);
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = FLOOR_MID;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y + img.width);
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_SIDE_R;
	// ft_printf("Image path: %s\n", img.filename);
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 3), y + img.width);
	// mlx_destroy_image(game->mlx, img.img);

	// // Bottom row
	// img.filename = WALL_BASE_L;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x, y + (img.width * 2)); // 0, 48
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_BASE;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + img.width, y + (img.width * 2));
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_BASE;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y + (img.width * 2));
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = WALL_BASE_R;
	// ft_printf("Image path: %s\n", img.filename);
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 3), y + (img.width * 2));
	// mlx_destroy_image(game->mlx, img.img);

	// // Plaer start at 1,1
	// img.filename = PLAYER_RIGHT;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + 52, y  + 48);  // 48 is tile width, player width is smaller
	// mlx_destroy_image(game->mlx, img.img);

	// img.filename = MAP_EXIT;
	// set_img_data(&img, game);
	// mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, x + (img.width * 2), y + img.width);
	// mlx_destroy_image(game->mlx, img.img);


	// Display the background (floor)
	// Display the walls, exit (and start)
	// Display the collectibles
	// Display the player


	mlx_hook(game->mlx_win, 17, 0, (int (*)(void *))close_window, context);
	mlx_hook(game->mlx_win, 2, 1L << 0,
		(int (*)(int, void *))keypress, context);

	// mlx_loop_hook();
	mlx_loop(game->mlx);

	return (0);
}
