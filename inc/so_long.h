/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:13:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/18 22:31:39 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/src/libft.h"
# include "errors.h"
# include <fcntl.h>

# define WALL '1'
# define START 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define VALID_CHARS "01PEC"
# define ERR_MAP_DIMS "Map is not rectangular.\n"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

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

int		set_error(const char *message);
int		open_file(const char *file, int flags);
int		parse_map(t_game *game, t_m_data *flags);
void	run_game(void);
int		load_window(t_game *game);
// void	validate_map(char **map, t_m_data *flags);
int		validate_map(t_game *game, t_m_data *data);
int		validate_path(t_game *game, t_m_data *map_data);
int		map_dimensions(const char *file, t_m_data *map_data);
int		check_walls(const char *line, int length);
void	check_line_length(const char *line, int expected_length);
int		check_valid_chars(const char *line, t_m_data *flags, int line_num);

#endif
