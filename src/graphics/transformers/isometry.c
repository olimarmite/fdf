/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:00:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/28 09:04:06 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../graphics.h"

t_vect2d	isometry_transform(t_point point, t_vect2d start_pos,
	t_vect2d tile_size, int altitude_ratio)
{
	t_vect2d	screen_pos;

	screen_pos.x = start_pos.x + (point.x - point.y) * tile_size.x / 2;
	screen_pos.y = start_pos.y + (point.x + point.y) * tile_size.y / 2;
	screen_pos.y -= point.altitude * altitude_ratio;
	return (screen_pos);
}


t_vect2d	isometry_map_size(t_map map, t_vect2d tile_size)
{
	t_vect2d	isometry_size;

	isometry_size.x = ((map.width + map.height - 2) * tile_size.x) / 2;
	isometry_size.y = (map.width + map.height - 2) * tile_size.y / 2;
	return (isometry_size);
}
