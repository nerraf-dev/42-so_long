/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:35 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/23 16:21:22 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// int	put_pixel(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->buffer + (y * img->line_bytes + x * (img->bpp / 8));
// 	*(unsigned int *)dst = color;
// 	return (0);
// }

int	preload_images()
{
	
	return (0);
}

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
	ft_printf("Image data address obtained successfully.\n");
	ft_printf("Image bpp: %d\n", img->bpp);
	ft_printf("Image line bytes: %d\n", img->line_bytes);
	return (0);
}

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


