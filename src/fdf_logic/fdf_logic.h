/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_logic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:44:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/22 18:14:16 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LOGIC_H
# define FDF_LOGIC_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include "../context/context.h"
# include "../events/events.h"
# include "../exit/fdf_exit.h"
# include "../graphics/graphics.h"
# include "../map/map.h"
# include "../parsing/parsing.h"
# include "../utils/utils.h"
# include <mlx.h>

void		main_graphics(t_context *context);
t_f_vect2d	center_position(t_context *context);
void		draw_map(t_context *context);
void		redraw_map(t_context *context);
int			refresh_if_needed(t_context *context);

void		fdf_altitude_zoom(float factor, t_context *context);
void		fdf_zoom(float factor, t_context *context);
void		fdf_move(int x, int y, t_context *context);
void		fdf_rot(t_vect3d angle, t_context *context);
double		calc_zoom_factor(t_context *context);

#endif
