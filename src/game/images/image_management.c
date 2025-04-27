/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/27 16:32:16 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

/**
 * set_img_data - Loads an XPM image and initializes its data.
 * @param img: Pointer to the image structure.
 * @param game: Pointer to the game structure.
 *
 * Loads the image from the file path stored in img->filename,
 * obtains the image dimensions, and retrieves the data address.
 * On failure, prints an error message and returns 1.
 *
 * Return: 0 on success, 1 on failure.
 */
int	set_img_data(t_img *img, t_game *game)
{
	// int		x;
	// int		y;
	// int		pixel;

	if (img->filename == NULL)
		return (set_error("Error: Image filename is NULL."));
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
	// // Transparency formatting
	// y = 0;
	// while (y < img->height)
	// {
	// 	x = 0;
	// 	while (x < img->width)
	// 	{
	// 		pixel = y * img->line_bytes + x * (img->bpp / 8);
	// 		if (*(unsigned int *)(img->buffer + pixel) == 0xFF000000)
	// 		{
	// 			*(unsigned int *)(img->buffer + pixel) = 0x00000000;
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	ft_printf("Image bpp: %d\n", img->bpp);
	ft_printf("Image line bytes: %d\n", img->line_bytes);
	return (0);
}
