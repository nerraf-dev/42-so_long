/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:45:40 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/24 09:22:26 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief Reallocates a memory block to a new size.
 *
 * This function reallocates a memory block pointed to by `ptr` to a new size
 * specified by `new_size`. If the new size is smaller than or equal to the
 * old size, the original pointer is returned. If the new size is larger, a
 * new memory block is allocated, the contents of the old block are copied
 * to the new block, and the old block is freed.
 *
 * @param ptr Pointer to the memory block to be reallocated. If NULL, the
 *            function behaves like `ft_calloc(1, new_size)`.
 * @param old_size The size of the currently allocated memory block.
 * @param new_size The desired size of the new memory block.
 *
 * @return A pointer to the newly allocated memory block, or NULL if the
 *         allocation fails or if `new_size` is 0.
 *
 * @note If `new_size` is 0, the function frees the memory block pointed to
 *       by `ptr` and returns NULL.
 * @note The function uses `ft_calloc` for memory allocation and `ft_memcpy`
 *       for copying data.
 */
//TODO: ft_realloc - Is this being used anywhere?
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (ft_calloc(1, new_size));
	if (new_size <= old_size)
		return (ptr);
	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
