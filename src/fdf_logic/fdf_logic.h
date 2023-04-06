/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_logic.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:44:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/06 20:25:46 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LOGIC_H
# define FDF_LOGIC_H

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

# include <mlx.h>
# include "../utils/utils.h"
# include "../graphics/graphics.h"
# include "../map/map.h"
# include "../parsing/parsing.h"
# include "../events/events.h"
# include "../exit/fdf_exit.h"
# include "../context/context.h"

void		main_graphics(t_context *context);
t_vect2d	center_position(t_context *context);
t_vect2d	calc_tile_size(t_context *context);
t_vect2d	calc_iso_tile_size_fitted(t_context *context);

#endif
