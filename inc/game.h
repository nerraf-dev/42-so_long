/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarren <sfarren@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:07:11 by sfarren           #+#    #+#             */
/*   Updated: 2025/05/06 13:08:01 by sfarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

int		load_images(t_context *context);
int		set_frame_buffer(t_context *context);
int		set_img_data(t_img *img, t_game *game);
t_img	*set_wall_texture_values(t_game *game);
t_img	*set_floor_texture_values(t_game *game);
t_img	*set_static_player_texture_values(t_game *game);
t_img	*set_coll_texture_values(t_game *game);
t_img	*set_exit_texture_values(t_game *game);
t_img	*set_ui_texture_values(t_game *game);
int		display_images(t_context *context);
int		display_image_move(t_context *context);
int		display_image(t_game *game, t_img *img, int x, int y);
int		display_walls(t_context	*context);
int		display_floor(t_context *context);
int		display_exit(t_context *context);
int		display_collectibles(t_context *context);
int		display_player(t_context *context);
int		display_level_end(t_context *context);
int		move_player(t_context *context, int new_x, int new_y);
void	blit_image_opaque(t_img *dst, t_img *src, int x_off, int y_off);
void	blit_image_transparent(t_img *dst, t_img *src, int x_off, int y_off);

#endif
