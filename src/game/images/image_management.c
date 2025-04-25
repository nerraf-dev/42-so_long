/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 17:21:55 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

/**
 * preload_images - Preloads images required for the game.
 *
 * (Placeholder function; implement image preloading logic here.)
 *
 * Return: 0 on success.
 */
int	preload_images()
{

	return (0);
}

/**
 * set_img_data - Loads an XPM image and initializes its data.
 * @img: Pointer to the image structure.
 * @game: Pointer to the game structure.
 *
 * Loads the image from the file path stored in img->filename,
 * obtains the image dimensions, and retrieves the data address.
 * On failure, prints an error message and returns 1.
 *
 * Return: 0 on success, 1 on failure.
 */
int	set_img_data(t_img *img, t_game *game)
{
	if (img->filename == NULL)
	{
		ft_putstr_fd("Error: Image path is NULL.\n", 2);
		return (1);
	}
	img->img = mlx_xpm_file_to_image(game->mlx, img->filename,
			&img->width, &img->height);
	if (img->img == NULL)
	{
		ft_putstr_fd("Error: Failed to load image.\n", 2);
		return (1);
	}
	ft_printf("Image loaded: %s\n", img->filename);
	ft_printf("Image dimensions: %d x %d\n", img->width, img->height);
	img->buffer = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_bytes, &img->endian);
	if (img->buffer == NULL)
	{
		ft_putstr_fd("Error: Failed to get image data address.\n", 2);
		mlx_destroy_image(game->mlx, img->img);
		return (1);
	}
	ft_printf("Image bpp: %d\n", img->bpp);
	ft_printf("Image line bytes: %d\n", img->line_bytes);
	return (0);
}

/**
 * display_image - Displays an image at the specified window position.
 * @game: Pointer to the game structure.
 * @img: Pointer to the image structure.
 * @x: X-coordinate for image placement.
 * @y: Y-coordinate for image placement.
 *
 * Uses MLX to put the loaded image onto the game window.
 *
 * Return: 0 on success, 1 if the image is not loaded.
 */
int	display_image(t_game *game, t_img *img, int x, int y)
{
	if (img->img == NULL)
	{
		ft_putstr_fd("Error: Image is not loaded.\n", 2);
		return (1);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, x, y);
	return (0);
}


