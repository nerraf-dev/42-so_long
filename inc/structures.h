/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:10:40 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/08 10:48:24 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_img
{
	void	*img;
	char	*filename;
	int		width;
	int		height;
	char	*buffer;
	int		bpp;
	int		line_bytes;
	int		endian;
	int		transparency;
}			t_img;

typedef struct s_meta
{
	int		line_count;
	int		line_length;
	int		start_count;
	int		exit_count;
	int		collectible_count;
	int		start_pos[2];
	int		exit_pos[2];
	int		tile;
}			t_meta;

typedef struct s_images
{
	t_img	*walls;
	t_img	*floors;
	t_img	*collectibles;
	t_img	*exit;
	t_img	*player;
	t_img	*ui;
}			t_images;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*file;
	int			**visited;
	t_img		*frame_buffer;
	t_images	images;
	int			player_pos[2];
	int			collectibles;
	int			exit;
	int			error;
	int			steps;
}				t_game;

typedef struct s_context
{
	t_game		*game;
	t_meta		*meta;
}				t_context;

typedef struct s_fb_vars
{
	int	win_w;
	int	win_h;
	int	bpp;
	int	line_bytes;
	int	endian;
}	t_fb_vars;

#endif
