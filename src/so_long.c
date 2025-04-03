/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:51:07 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/03 18:31:04 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./map_parser <map_file>\n", 2);
		return (1);
	}
	parse_map(argv[1]);

	mlx = mlx_init();
	if (mlx == NULL)
	{
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	if (mlx_win == NULL)
	{
		return (free(mlx), 1);
	}
	mlx_loop(mlx);

	return (0);
}
