/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_data_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:22:52 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/05 21:08:49 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

/*
 * set_wall_texture_values - Initialize wall textures.
 *
 * @param game: Pointer to the game structure.
 *
 * This function creates and initializes an array of 9 wall textures.
 * Each texture is assigned a filename corresponding to a specific wall
 * part. It then loads the image data by calling set_img_data for each
 * texture. If any texture fails to load, the function returns NULL.
 *
 * @return Pointer to the textures array on success, or NULL on failure.
 */
t_img	*set_wall_texture_values(t_game *game)
{
	static t_img	textures[1];
	int				i;

	i = 0;
	textures[0].filename = WALL_MID;
	while (i < WALL_IMAGES)
	{
		if (set_img_data(&textures[i], game))
			return (NULL);
		i++;
	}
	return (textures);
}

t_img	*set_floor_texture_values(t_game *game)
{
	static t_img	textures[1];
	int				i;

	i = 0;
	textures[0].filename = FLOOR_MID;
	while (i < FLOOR_IMAGES)
	{
		if (set_img_data(&textures[i], game))
			return (NULL);
		i++;
	}
	return (textures);
}

t_img	*set_static_player_texture_values(t_game *game)
{
	static t_img	textures[4];
	int				i;

	i = 0;
	textures[0].filename = PLAYER_UP;
	textures[1].filename = PLAYER_DOWN;
	textures[2].filename = PLAYER_LEFT;
	textures[3].filename = PLAYER_RIGHT;
	while (i < 4)
	{
		if (set_img_data(&textures[i], game))
			return (NULL);
		i++;
		textures[i].transparency = 1;
	}
	return (textures);
}

t_img	*set_coll_texture_values(t_game *game)
{
	static t_img	textures[1];
	int				i;

	i = 0;
	textures[i].filename = MAP_COLLECTIBLE;
	if (set_img_data(&textures[i], game))
		return (NULL);
	return (textures);
}

t_img	*set_exit_texture_values(t_game *game)
{
	static t_img	textures[2];
	int				i;

	i = 0;
	textures[0].filename = MAP_EXIT;
	textures[1].filename = MAP_EXIT_CLOSED;
	while (i < EXIT_IMAGES)
	{
		if (set_img_data(&textures[i], game))
			return (NULL);
		i++;
	}
	return (textures);
}
