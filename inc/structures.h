/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:10:40 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/25 11:11:18 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_m_data
{
	int		line_count;
	int		line_length;
	int		start_count;
	int		exit_count;
	int		collectible_count;
	int		start[2];
	int		exit[2];
}			t_m_data;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	char		*file;
	int			**visited;
	int			collectibles;
	int			exit;
	int			error;
}				t_game;

typedef struct s_context
{
	t_game		*game;
	t_m_data	*map_data;
}				t_context;

// typedef struct s_textures
// {

// }

#endif
