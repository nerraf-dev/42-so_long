/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:13:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/28 19:45:49 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/src/libft.h"
# include "errors.h"
# include "structures.h"
# include "images.h"
# include "validate_path.h"
# include "game.h"
# include <X11/keysym.h>
# include <fcntl.h>

// Key for map validation
# define K_EMPTY '0'
# define K_WALL '1'
# define K_START 'P'
# define K_EXIT 'E'
# define K_COLLECTIBLE 'C'
# define VALID_CHARS "01PEC"
# define ERR_MAP_DIMS "Map is not rectangular.\n"

// REMOVE DEBUGGINg RELATED STUFF
void	debug_print(t_game *game, t_meta *meta);
void	print_visited(int **visited, int height, int width);

// **************************************** //

int		set_error(const char *message);
void	cleanup(t_game *game, t_meta *map_data);
int		open_file(const char *file, int flags);
int		parse_and_validate(t_game *game, t_meta *flags);
int		validate_map(t_game *game, t_meta *data);
int		validate_path(t_game *game, t_meta *meta);
int		map_dimensions(const char *file, t_meta *meta);
int		check_walls(const char *line, int length);
void	check_line_length(const char *line, int expected_length);
int		check_valid_chars(const char *line, t_meta *flags, int line_num);

int		run_game(t_context *context);
int		load_window(t_game *game);

#endif
