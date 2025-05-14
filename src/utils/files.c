/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:18:27 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/14 14:31:22 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief open_file - Opens a file with the specified flags and permissions.
 *
 * @param file: The path to the file to be opened.
 * @param flags: The flags to use when opening the file
 * 					(e.g., O_RDONLY, O_WRONLY, O_RDWR).
 * This function attempts to open the specified file with the given flags
 * and a default permission mode of 0644. If the file cannot be opened,
 * an error message is printed to standard error, and the program exits
 * with a status of 1.
 *
 * @return The file descriptor of the opened file on success.
 */
int	open_file(const char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		set_error("Error opening file");
		exit(1);
	}
	return (fd);
}
