/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:54:13 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/17 14:54:08 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//TOD: Need to add in some clean up!!
void	exit_with_error(const char *message)
{
	ft_printf_fd(2, "Error\n");
	ft_printf_fd(2, "%s", message);
	exit(EXIT_FAILURE);
}
