/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:17 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/23 13:54:52 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <X11/keysym.h> // For keysyms

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

// Function to handle key presses
int	keypress(int keysym, t_game	*game)
{
	// Check if the pressed key is the ESC key
	// if (keycode == 65307) // 65307 is the keycode for ESC
	if (keysym == XK_Escape)
		close_window(game);
	return (0);
}

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

	i = 0;
	while (i < width)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, i, 240, 0x00FF00);
		i++;
	}
	i = 0;
	while (i < height)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, 320, i, 0x0000FF);
		i++;
	}
	i = 50;
	// img.filename = "./assets/misc/sprout_lands/Tilesets/Wooden_House_Walls_Tilset.xpm";
	img.filename = "./assets/walls/top-left.xpm";
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, i, 50);
	mlx_destroy_image(game->mlx, img.img);
	img.filename = "./assets/walls/top.xpm";
	set_img_data(&img, game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, i + img.width, 50);
	mlx_destroy_image(game->mlx, img.img);
	// Calc TileSize
	// Centre the view (optional)
	// Load images
	// Show images
	ft_printf("Line drawn\n");

	mlx_hook(game->mlx_win, 17, 0, (int (*)(void *))close_window, game);
	mlx_hook(game->mlx_win, 2, 1L << 0,
		(int (*)(int, void *))keypress, game);

	return (0);
}
