/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_calcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:23:30 by olimarti          #+#    #+#             */
/*   Updated: 2023/04/06 20:42:21 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_logic.h"

t_vect2d	center_position(t_context *context)
{
	t_vect2d	iso_map_size;
	t_vect2d	center;

	iso_map_size = isometry_map_size(context->map,
			context->drawing_params.tile_size);
	center.x = (context->drw_win->img_wrapper->width - iso_map_size.x
			+ (context->drawing_params.tile_size.x
				* (context->map.height - 1))) / 2;
	center.y = (context->drw_win->img_wrapper->height - iso_map_size.y) / 2;
	return (center);
}

t_vect2d	calc_tile_size(t_context *context)
{
	t_vect2d	screen_size;
	t_vect2d	tile_size;
	t_map		map;

	map = context->map;
	screen_size = vect2d(context->drw_win->img_wrapper->width,
			context->drw_win->img_wrapper->height);
	tile_size.x = screen_size.x / (map.width + map.height - 2);
	tile_size.y = screen_size.y / (map.width + map.height - 2);
	return (tile_size);
}

t_vect2d	calc_iso_tile_size_fitted(t_context *context)
{
	t_vect2d	tile_size;

	tile_size.x = calc_tile_size(context).x;
	tile_size.y = tile_size.x * ISOMETRY_RATIO;
	if (tile_size.y * context->map.height
		> context->drw_win->img_wrapper->height)
	{
		tile_size.y = calc_tile_size(context).y;
		tile_size.x = tile_size.y / ISOMETRY_RATIO;
	}
	return (tile_size);
}
