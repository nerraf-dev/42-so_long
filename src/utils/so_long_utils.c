/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:54:13 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/27 22:02:45 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//TOD: Need to add in some clean up!!
int	set_error(const char *message)
{
	ft_printf_fd(2, "Error:\n", message);
	ft_printf_fd(2, "%s\n", message);
	return (1);
}
