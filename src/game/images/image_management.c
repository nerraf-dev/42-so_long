/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/28 19:34:48 by sfarren          ###   ########.fr       */
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
		return (set_error("Failed to load image."));
	img->buffer = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_bytes, &img->endian);
	if (img->buffer == NULL)
	{
		mlx_destroy_image(game->mlx, img->img);
		return (set_error("Failed to get image data address."));
	}
	return (0);
}
