/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:46:23 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/06 16:49:59 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_PATH_H
# define VALIDATE_PATH_H

# include "../lib/libft/src/libft.h"

typedef struct s_queue_node
{
	int					x;
	int					y;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue
{
	int		front;
	int		back;
}	t_queue;

#endif
