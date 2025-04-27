/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/27 22:01:48 by sfarren          ###   ########.fr       */
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
	if (img->filename == NULL)
		return (set_error("Image filename is NULL."));
	img->img = mlx_xpm_file_to_image(game->mlx, img->filename,
			&img->width, &img->height);
	if (img->img == NULL)
	{
		ft_putstr_fd("Error: Failed to load image.\n", 2);
		return (1);
	}
	img->buffer = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_bytes, &img->endian);
	if (img->buffer == NULL)
	{
		ft_putstr_fd("Error: Failed to get image data address.\n", 2);
		mlx_destroy_image(game->mlx, img->img);
		return (1);
	}
	return (0);
}
