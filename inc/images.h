/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:05:58 by sfarren           #+#    #+#             */
/*   Updated: 2025/04/26 16:27:28 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

// TILE_SIZE: size of each tile in pixels
# define TILE_SIZE 48
# define ASSETS_DIR "./assets/"
// WALLS
//  Top. Brick wall, can be 3 tiles high
# define WALL_IMAGES 1
# define WALL_MID "./assets/walls/mid.xpm"

// FLOORS
# define FLOOR_IMAGES 1
# define FLOOR_MID "./assets/floors/gb_mid.xpm"

// PLAYER
// # define PLAYER "./assets/player/player.xpm"
# define PLAYER_IMAGES 4
# define PLAYER_UP "./assets/player/walk_up_000.xpm"
# define PLAYER_DOWN "./assets/player/walk_down_000.xpm"
# define PLAYER_LEFT "./assets/player/walk_left_000.xpm"
# define PLAYER_RIGHT "./assets/player/walk_right_000.xpm"

// EXIT
# define EXIT_IMAGES 1
# define MAP_EXIT "./assets/exit.xpm"
// COLLECTIBLES
# define COLLECTIBLE_IMAGES 1
# define MAP_COLLECTIBLE "./assets/collectible.xpm"

// TEXTURE index vals - Foors and walls
# define I_TL 0
# define I_TOP 1
# define I_TR 2
# define I_SIDE_L 3
# define I_MID 4
# define I_SIDE_R 5
# define I_BASE_L 6
# define I_BASE 7
# define I_BASE_R 8

// Player index values
# define I_PLR_UP 0
# define I_PLR_DOWN 1
# define I_PLR_LEFT 2
# define I_PLR_RIGHT 3

// Object index values
# define I_EXIT 0
# define I_COLLECTIBLE 1

#endif
