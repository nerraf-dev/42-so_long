/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:17:13 by sfarren           #+#    #+#             */
/*   Updated: 2025/03/01 14:21:22 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	int		fd;

	fd = open_file("maps/test.ber", O_RDONLY);
	ft_printf("fd: %d\n", fd);

	// mlx = mlx_init();
	// if (mlx == NULL)
	// {
	// 	return (1);
	// }
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// if (mlx_win == NULL)
	// {
	// 	return (1);
	// }
	// mlx_loop(mlx);
	return (0);
}
