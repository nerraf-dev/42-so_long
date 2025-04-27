/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blit_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:33:39 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/27 19:26:30 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

// For floor/background: always copy
void	blit_image_opaque(t_img *dst, t_img *src, int x_off, int y_off)
{
	int	x;
	int	y;
	int	src_width;
	int	src_height;
	int	src_pixel;

	src_width = src->width;
	src_height = src->height;
	y = 0;
	while (y < src_height)
	{
		x = 0;
		while (x < src_width)
		{
			src_pixel = *(int *)(src->buffer + (y * src->line_bytes + x * (src->bpp / 8)));
			*(int *)(dst->buffer + ((y + y_off) * dst->line_bytes + (x + x_off) * (dst->bpp / 8))) = src_pixel;
			x++;
		}
		y++;
	}
}

// For sprites: skip transparent pixels
void	blit_image_transparent(t_img *dst, t_img *src, int x_off, int y_off)
{
	int				x;
	int				y;
	int				src_width;
	int				src_height;
	unsigned int	src_pixel;

    src_width = src->width;
    src_height = src->height;
    y = 0;
    while (y < src_height)
    {
        x = 0;
        while (x < src_width)
        {
            src_pixel = *(int *)(src->buffer + (y * src->line_bytes + x * (src->bpp / 8)));
			if (x == 0 && y == 0) // or any known transparent pixel
				ft_printf("Transparent pixel value: 0%x\n", src_pixel);
            // Skip if pixel is exactly black (transparent in XPM)
            if (src_pixel != 0xFF000000)
            {
                *(int *)(dst->buffer + ((y + y_off) * dst->line_bytes + (x + x_off) * (dst->bpp / 8))) = src_pixel;
            }
            x++;
        }
        y++;
    }
}
