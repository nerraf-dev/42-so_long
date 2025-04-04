/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:17:13 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/03 18:10:39 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		fd;
	char	*line;

	fd = open_file("maps/test.berr", O_RDONLY);
	ft_printf("fd: %d\n", fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	if (fd != 0)
		close(fd);


	mlx = mlx_init();
	if (mlx == NULL)
	{
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (mlx_win == NULL)
	{
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}
