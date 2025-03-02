/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:13:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/02 14:00:09 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../lib/libft/src/libft.h"
// # include "../lib/gnl/src/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map_flags
{
	int		line_count;
	int		line_length;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}			t_map_flags;


int		open_file(const char *file, int flags);
void	parse_map(const char *file);

#endif
