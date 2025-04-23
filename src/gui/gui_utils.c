/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:00:21 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/22 15:47:57 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief Converts RGB color components into a single integer representation.
 *
 * This function takes three separate color components (red, green, and blue),
 * each represented as an integer, and combines them into a single 24-bit integer
 * where:
 * - The red component occupies the most significant 8 bits.
 * - The green component occupies the middle 8 bits.
 * - The blue component occupies the least significant 8 bits.
 *
 * @param r The red component (0-255).
 * @param g The green component (0-255).
 * @param b The blue component (0-255).
 * @return An integer representing the combined RGB color.
 */
int	rgb_to_int(int r, int g, int b)
{
	int	colour;

	colour = 0;
	colour |= (r << 16);
	colour |= (g << 8);
	colour |= b;
	return (colour);
}
