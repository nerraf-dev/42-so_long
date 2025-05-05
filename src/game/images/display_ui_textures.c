/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:18:46 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 19:48:50 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_img	*set_ui_texture_values(t_game *game)
{
	static t_img	textures[1];
	int				i;

	i = 0;
	textures[0].filename = LEVEL_END;
	while (i < UI_IMAGES)
	{
		if (set_img_data(&textures[i], game))
		{
			ft_printf_fd(2, "Error: Failed to load image %s",
				textures[i].filename);
			return (NULL);
		}
		i++;
	}
	return (textures);
}
