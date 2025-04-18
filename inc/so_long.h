/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:13:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 14:43:40 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/src/libft.h"
// # include <stdio.h>
# include <fcntl.h>

# define WALL '1'
# define START 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define VALID_CHARS "01PEC"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_m_data
{
	int		line_count;
	int		line_length;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		start[2];
	int		exit[2];
}			t_m_data;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*file;
	char		**map;
	int			**visited;
	int			collectibles;
	int			exit;
	int			error;
}				t_game;

// Create a player data structure.

void	exit_with_error(const char *message);
int		open_file(const char *file, int flags);
int		parse_map(t_game *game, t_m_data *flags);
void	run_game(void);
void	load_window(t_game *game);
void	free_map(t_game *game);
// void	validate_map(char **map, t_m_data *flags);
void	validate_map(t_game *game, t_m_data *data);
void	validate_path(t_game *game, t_m_data *map_data);
void	map_dimensions(const char *file, t_m_data *map_data);
void	check_walls(const char *line, int length);
void	check_line_length(const char *line, int expected_length);


#endif
