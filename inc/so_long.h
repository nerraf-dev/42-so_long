/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:13:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/01 17:05:11 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../lib/libft/src/libft.h"
// # include "../lib/gnl/src/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

int		open_file(const char *file, int flags);
void	parse_map(const char *file);

#endif
