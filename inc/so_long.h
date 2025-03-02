/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:13:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/02 15:17:36 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../lib/libft/src/libft.h"
// # include "../lib/gnl/src/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define WALL '1'
# define START 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define VALID_CHARS "01PEC"

typedef struct s_map_flags
{
	int		line_count;
	int		line_length;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}			t_map_flags;


void	exit_with_error(const char *message);
int		open_file(const char *file, int flags);
void	parse_map(const char *file);
void	map_dimensions(const char *file, t_map_flags *flags);
void	validate_map(char **map, t_map_flags *flags);

#endif
