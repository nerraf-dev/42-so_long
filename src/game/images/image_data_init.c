/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_data_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:22:52 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 19:12:28 by sfarren          ###   ########.fr       */
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
	static t_img	textures[9];
	int				i;

	i = 0;
	textures[0].filename = WALL_TL;
	textures[1].filename = WALL_TOP;
	textures[2].filename = WALL_TR;
	textures[3].filename = WALL_SIDE_L;
	textures[4].filename = WALL_MID;
	textures[5].filename = WALL_SIDE_R;
	textures[6].filename = WALL_BASE_L;
	textures[7].filename = WALL_BASE;
	textures[8].filename = WALL_BASE_R;
	while (i < 9)
	{
		if (set_img_data(&textures[i], game))
		{
			ft_printf("Error: Failed to load wall image %s.\n",
				textures[i].filename);
			return (NULL);
		}
		i++;
	}

	return (textures);

}

t_img	*set_floor_texture_values(t_game *game)
{
	static t_img	textures[6];
	int				i;

	i = 0;
	textures[0].filename = FLOOR_TL;
	textures[1].filename = FLOOR_TOP;
	textures[2].filename = FLOOR_TR;
	textures[3].filename = FLOOR_LEFT;
	textures[4].filename = FLOOR_MID;
	textures[5].filename = FLOOR_RIGHT;
	while (i < 6)
	{
		set_img_data(&textures[i], game);
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
		set_img_data(&textures[i], game);
		i++;
	}
	return (textures);
}

t_img	*set_coll_texture_values(t_game *game)
{
	static t_img	textures[1];
	int				i;

	i = 0;
	textures[i].filename = MAP_COLLECTIBLE;
	set_img_data(&textures[i], game);
	return (textures);
}

t_img	*set_exit_texture_values(t_game *game)
{
	static t_img	textures[1];
	int				i;

	i = 0;
	textures[i].filename = MAP_EXIT;
	set_img_data(&textures[i], game);
	return (textures);
}
